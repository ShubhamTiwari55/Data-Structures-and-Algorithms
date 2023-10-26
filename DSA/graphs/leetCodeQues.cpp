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

//leetcode ques no.133 -> clone graph
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
class Solution {
public:
    vector<Node*> nodeRegisters;

    void dfs(Node* actual, Node* clone){
        for(auto neighbour : actual->neighbors){
            if(!nodeRegisters[neighbour->val]){
                //create the neighbour for the first time
            Node* newNode = new Node(neighbour->val);
            nodeRegisters[newNode->val] = newNode;
            clone->neighbors.push_back(newNode);
            dfs(neighbour, newNode);
            }else {
                clone->neighbors.push_back(nodeRegisters[neighbour->val]);
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->val);  //source node
        nodeRegisters.resize(110, NULL);  //this array contains reference to the created nodes i.e if NULL is there that means no node is created and if there is any value then a node is created by that value
        nodeRegisters[clone->val] = clone;
        dfs(node, clone);
        return clone;
    }
}; 

//leetcode ques no. 1034 -> coloring a border
class Solution {
public:
    vector<pair<int,int>>internal;
    void dfs(vector<vector<int>>& grid, int r, int c, int newColor, int originalColor){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != originalColor) return;
        grid[r][c] = -newColor;
        dfs(grid, r+1, c, newColor, originalColor);
        dfs(grid, r-1, c, newColor, originalColor);
        dfs(grid, r, c+1, newColor, originalColor);
        dfs(grid, r, c-1, newColor, originalColor);
        //we are applying flood fill on connected components and then removing the color of inner elements so that we can get a border of all the connected components
        //below code if for returning back from recursion in which we are filling colors for border and unfilling the color of inner elements
        if(!(r==0 || c==0 || r==grid.size()-1 || c==grid[0].size()-1 || grid[r+1][c]!=-newColor ||  grid[r][c+1]!=-newColor ||  grid[r-1][c]!=-newColor ||  grid[r][c-1]!=-newColor)) internal.push_back({r, c}); //internal cell
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalColor = grid[row][col];
        if(originalColor == color) return grid;
        dfs(grid, row, col, color, originalColor);
        for(auto p:internal){
            int i = p.first;
            int j = p.second;
            grid[i][j] = originalColor;
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]<0) grid[i][j] = -grid[i][j];
            }
        }
        return grid;
    }
};

//leetcode ques no. 200 -> no. of islands
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (r == 0) return 0;
        int c = grid[0].size();
        int cc = 0; //connected components
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j]=='0') continue; //water body or already visited land
                //new unvisited connected component found
                cc++;
                grid[i][j] = '0';  //mark it visited
                queue<pair<int,int>> q;
                q.push({i,j});  //store the src node and begin bfs traversal
                while(!q.empty()){
                    auto curr = q.front();
                    q.pop();
                    //go to all unvisited node of the cc
                    int currRow = curr.first;
                    int currCol = curr.second;
                    //check up
                    if(currRow-1>=0 && grid[currRow-1][currCol]=='1'){
                        q.push({currRow-1,currCol});
                        grid[currRow-1][currCol]='0';
                    }
                    //check down
                    if(currRow+1<r && grid[currRow+1][currCol]=='1'){
                        q.push({currRow+1,currCol});
                        grid[currRow+1][currCol]='0';
                    }
                    //check left
                    if(currCol-1>=0 && grid[currRow][currCol-1]=='1'){
                        q.push({currRow,currCol-1});
                        grid[currRow][currCol-1]='0';
                    }
                    //check right
                    if(currCol+1<c && grid[currRow][currCol+1]=='1'){
                        q.push({currRow,currCol+1});
                        grid[currRow][currCol+1]='0';
                    }
                }
            }
        }
        return cc;
    }
};