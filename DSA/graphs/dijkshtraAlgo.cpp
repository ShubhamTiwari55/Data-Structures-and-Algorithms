#include <bits/stdc++.h>
#define pp pair<int, int>
#define ll long long int
using namespace std;

vector<list<pp>> gr;

void addEdge(int u, int v, int wt, bool bidir = true) {
    gr[u].push_back({v, wt});
    if (bidir) {
        gr[v].push_back({u, wt});
    }
}

//T.C -> O(Vlogv+ElogV)

unordered_map<int, int> dijkstra(int src, int n) {
    priority_queue<pp, vector<pp>, greater<pp>> pq;
    unordered_map<int, int> mp;
    vector<int> via(n, -1);
    unordered_set<int> vis;
    for (int i = 0; i < n; i++) {
        mp[i] = INT_MAX;
    }
    pq.push({0, src});
    mp[src] = 0;
    while (!pq.empty()) {
        pp curr = pq.top();
        if (vis.count(curr.second)) {
            pq.pop();
            continue;
        }
        vis.insert(curr.second);
        pq.pop();
        for (auto neighbour : gr[curr.second]) {
            if (!vis.count(neighbour.first) && mp[neighbour.first] > curr.first + neighbour.second) {
                pq.push({curr.first + neighbour.second, neighbour.first});
                via[neighbour.first] = curr.second;
                mp[neighbour.first] = curr.first + neighbour.second;
            }
        }
    }
    return mp;
}

int main() {
    int n, m;
    cin >> n >> m;
    gr.resize(n, list<pp>());
    while (m--) {
        int u, v, wt;
        cin >> u >> v >> wt;
        addEdge(u, v, wt);
    }
    int src;
    cin >> src;
    unordered_map<int, int> sp = dijkstra(src, n);
    int dest;
    cin >> dest;
    cout << sp[dest] << endl;
    return 0;
}
