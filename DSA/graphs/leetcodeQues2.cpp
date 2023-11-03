#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<unordered_set>
#include<list>
using namespace std;

//leetcode ques no. 947 -> Most Stones Removed with Same Row or Column
class Solution {
public:
    vector<list<int>> graph;
    int v; // no. of vertices
    void add_edge(int src, int dest, bool biDir = true) {
        graph[src].push_back(dest);
        if (biDir) {
            graph[dest].push_back(src);
        }
    }

    void dfs(int node, unordered_set<int> &visited) {
        visited.insert(node);
        for (auto neighbour : graph[node]) {
            if (!visited.count(neighbour)) {
                dfs(neighbour, visited);
            }
        }
    }
    int connectedComp() {
        int result = 0;
        unordered_set<int> visited;
        for (int i = 0; i < v; i++) {
            if (visited.count(i) == 0) {
                result++;
                dfs(i, visited);
            }
        }
        return result;
    }

    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        v = n;
        graph.resize(v, list<int>());

        // Construct the graph
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    add_edge(i, j);
                }
            }
        }
        // Calculate the result
        return n - connectedComp();
    }
};
