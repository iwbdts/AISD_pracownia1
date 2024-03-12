#include <iostream>
#include <array>
#include <algorithm>
#include <stack>

using namespace std;

array<pair<int, int>, 1000000> edges;
array<int, 1000000> inTime;
array<int, 1000000> outTime;
array<bool, 1000000> visited;
int my_time = 0;


void dfs(int v) {
    stack<int> S;
    S.push(v);
    while (!S.empty()) {
        v = S.top();
        if (!visited[v]) {
            visited[v] = true;
            my_time++;

            inTime[v] = my_time;
            int first_child = lower_bound(edges.begin(), edges.end(), make_pair(v, 0)) - edges.begin();
            int last_child = upper_bound(edges.begin(), edges.end(), make_pair(v, 2000000)) - edges.begin();
            for (int i = first_child; i < last_child; i++) {
                S.push(edges[i].second);
            }
        } else {
            S.pop();
            outTime[v] = my_time;

        }
    }


}


int main() {
    int num_of_women, queries; // num_of_women - liczba kobiet, queries - liczba zapytań
    visited.fill(false);
    edges.fill({2000000, 0});

    cin >> num_of_women >> queries;
    for (int i = 1; i < num_of_women; i++) {
        int mother;
        cin >> mother;
        edges[i] = {mother - 1, i};
    }

    sort(edges.begin(), edges.end());
    dfs(0);


    for (int i = 0; i < queries; i++) {
        int possible_ancestor, possible_descendant;
        cin >> possible_ancestor >> possible_descendant;
        possible_ancestor--;
        possible_descendant--;
        if (inTime[possible_ancestor] < inTime[possible_descendant] &&
            outTime[possible_ancestor] >= outTime[possible_descendant]) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }

    }
    return 0;
}