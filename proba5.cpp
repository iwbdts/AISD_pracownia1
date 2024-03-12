//#include <iostream>
//#include <array>
//#include <algorithm>
//#include <stack>
//using namespace std;
//
//array<pair<int, int>, 1000000> edges;
//array<int, 1000000> inTime;
//array<int, 1000000> outTime;
//array<bool, 1000000> visited;
//int my_time = 0;
//
//int firstChild(int parent){
//    int l = 0;
//    int r = 999999;
//    while (l <= r){
//        int m = l +(r- l)/2;
//        if((m == 0 or edges[m-1].first < parent) and edges[m].first == parent){
//            return m;
//        }else if (parent > edges[m].first){
//            l = m+1;
//        }else{
//            r = m-1;
//        }
//    }
//    return -1;
//}
//
//int lastChild(int parent){
//    int l = 0;
//    int r = 999999;
//    while (l <= r){
//        int m = l +(r- l)/2;
//        if((m ==999999 or edges[m+1].first > parent) and edges[m].first == parent){
//            return m;
//        }else if (parent < edges[m].first){
//            r = m-1;
//        }else{
//            l = m+1;
//        }
//    }
//    return -1;
//}
//
//
//void dfs(int v) {
//    stack<int> S;
//    S.push(v);
//    while (!S.empty()) {
//        v = S.top();
//        if (!visited[v]) {
//            visited[v] = true;
//            my_time++;
//
//            inTime[v] = my_time;
//            int first_child = firstChild(v);
//            int last_child = lastChild(v)+1;
//            for (int i = first_child; i < last_child; i++) {
//                S.push(edges[i].second);
//            }
//        } else {
//            S.pop();
//            outTime[v] = my_time;
////            cout << v << " : " << inTime[v] << " " << outTime[v] << endl;
//        }
//    }
//}
//
//
//int main() {
//    int num_of_women, queries; // num_of_women - liczba kobiet, queries - liczba zapytań
//    visited.fill(false);
//    edges.fill({2000000, 0});
//
//    cin >> num_of_women >> queries;
//    for (int i = 1; i < num_of_women; i++) {
//        int mother;
//        cin >> mother;
//        edges[i] = {mother - 1, i};
//    }
//    sort(edges.begin(), edges.end());
//    dfs(0);
//
//    for (int i = 0; i < queries; i++) {
//        int possible_ancestor, possible_descendant;
//        cin >> possible_ancestor >> possible_descendant;
//        possible_ancestor--;
//        possible_descendant--;
//        if (inTime[possible_ancestor] < inTime[possible_descendant] &&
//            outTime[possible_ancestor] >= outTime[possible_descendant]) {
//            cout << "TAK\n";
//        } else {
//            cout << "NIE\n";
//        }
//
//    }
//    return 0;
//}
