#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class maxHeap{
    vector<int> hp;
     void upheapify(int ci){
        while(ci>0){
            int pi = (ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci = pi;
            }
            else break;
        }
    }
public:

    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1);
    }

    int peek(){     //returns max value of the heap
        if(hp.size()==0) return INT_MAX;
        return hp[0];
    }
    bool isEmpty(){
        return hp.size()==0;
    }
    void display(){
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    maxHeap h;
    h.push(3);
    h.push(4);
    h.push(11);
    h.push(9);
    h.push(14);
    h.push(-1);
    h.push(30);
    h.push(44);
    h.push(50);
    h.display();
}