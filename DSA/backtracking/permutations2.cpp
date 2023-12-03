#include<iostream>
#include<unordered_set>
using namespace std;

//Using backtracking
void permutations(string &str, int i){
    if(i==str.size()-1){
        cout<<str<<endl;
        return;
    }

    //set for ensuring that repeated steps won't come
    unordered_set<char> s;
    for(int j=i;j<str.size();j++){
        if(s.count(str[j])) continue;

        s.insert(str[j]);
        swap(str[j],str[i]);
        permutations(str,i+1);
        swap(str[j],str[i]);
    }
}

int main(){
    string str = "abcd";
    permutations(str,0);
}