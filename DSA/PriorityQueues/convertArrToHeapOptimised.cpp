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
    void downHeapify(int idx){
        while(idx<hp.size()){
            int lc = 2*idx+1;   //left child
            int rc = 2*idx+2;   //right child
            if(lc>=hp.size()) break;    //idx -> leaf
            int maxEl = idx;
            if(hp[lc]>hp[maxEl]) maxEl = lc;
            if(rc<hp.size() && hp[rc]>hp[maxEl]) maxEl = rc;
            if(maxEl!=idx){
                swap(hp[idx], hp[maxEl]);
                idx = maxEl;    //for next iteration
            }else {
                break;
            }
        }
    }

    void pop(){     //removes the highest priority element
        if(isEmpty()) return;
        swap(hp[0],hp[hp.size()-1]);
        hp.pop_back();
        if(!isEmpty()) downHeapify(0);
    }
    void push(int element){     //A method to create heap by pushing individual elements//
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

    maxHeap(vector<int> v){
        hp = v;
        for(int i=hp.size()/2;i>=0;i--){
            downHeapify(i);
        }
    }
};
int main(){
    vector<int> v = {9,6,1,19,3,2,8,12,5};
    maxHeap h(v);
    h.display();
   
}