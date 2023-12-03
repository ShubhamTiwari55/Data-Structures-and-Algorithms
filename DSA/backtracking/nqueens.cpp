#include<iostream>
#include<vector>
using namespace std;

vector<vector<char>> grid;
vector<vector<string>> result;

bool canPlaceQueen(int row, int col, int n){
    // column check
    for(int i=row-1;i>=0;i--){
        if(grid[i][col]=='Q') return false;
    }
    // left diagonal check
    for(int i=row-1,j=col-1;i>=0&&j>=0;i--&&j--){
        if(grid[i][j]=='Q') return false;
    }
    // Right diagonal check
    for(int i=row-1,j=col+1;i>=0&&j<n;i--&&j++){
        if(grid[i][j]=='Q') return false;
    }
    return true;
}

void f(int row, int n){

if(row == n){
    // we got one possible answer
    vector<string> temp;
    for(int i=0;i<n;i++){
        string res = "";
        for(int j=0;j<n;j++){
            res+=grid[i][j];
        }
        temp.push_back(res);
    }
    result.push_back(temp);
    return;
}

    for(int col=0;col<n;col++){
        if(canPlaceQueen(row, col, n)){
            grid[row][col] = 'Q';
            f(row+1,n);
            grid[row][col] = '.';
        }

    }
}
vector<vector<string>> nqueens(int n){
    grid.clear();
    result.clear();
    grid.resize(n, vector<char>(n, '.'));
    f(0,n);
    return result;
}
int main(){
    vector<vector<string>> ans;
    ans = nqueens(4);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans.size();j++){
            cout<<ans[i][j]<<endl;
        }
    }
}