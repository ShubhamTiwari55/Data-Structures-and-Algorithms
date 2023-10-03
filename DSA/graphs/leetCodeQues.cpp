#include<iostream>
#include<vector>
#include<set>
#include<queue>
using namespace std;

//leetcode ques no. 733 -> Flood Fill
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int m = image.size(), n = image[0].size();
        DFS(image, sr, sc, m, n, image[sr][sc], newColor);
        return image;
    }
    
    void DFS(vector<vector<int>>& image, int r, int c, int m, int n, int target, int newColor){
        if(r < 0 || c < 0 || r == m || c == n || image[r][c] == newColor || image[r][c] != target) return;
        image[r][c] = newColor;
        DFS(image, r + 1, c, m, n, target, newColor);
        DFS(image, r - 1, c, m, n, target, newColor);
        DFS(image, r, c + 1, m, n, target, newColor);
        DFS(image, r, c - 1, m, n, target, newColor);
    }
};

//leetcode ques no. 1791 -> find center of star graph
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int a = edges[0][0];
        int b = edges[0][1];
        int c = edges[1][0];
        int d = edges[1][1];

        return (a==c || b==c)?c:d;
    }
};

//leetcode ques no. 841 -> keys and rooms
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int>visited;
        queue<int>q;
        q.push(0);
        visited.insert(0);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neighbour:rooms[curr]){
                if(visited.count(neighbour)==0){
                    //neighbour not visited yet
                    q.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        return visited.size()==rooms.size();
    }
};