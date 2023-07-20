#include<iostream>
#include<stack>
#include<climits>
using namespace std;
class MinStack {
public:
stack<long long> st;
long long min;
    MinStack() {
        min = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = (long long)(val);
      if(st.size()==0){
          st.push(x);
          min = x;
      }
      else if(x>=min) st.push(x);
      else{
          st.push(x+(x-min));   //we are creating a fake value by this and retrieving it later when needed
          min = x;
      }
    }
    
    void pop() {
        if(st.top()>=min) st.pop();
        else{ //st.top()<min that means a fake value is present because no value should be smaller than the min value and we have to retreive the old value before popping using the below relation obtained by min = val + (val-min); which is given above in the push function just the change is x==val //
            long long oldMin = 2*min - st.top();
            min = oldMin;
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<min) return (int)min;   //because originally in the stack there is a fake value //
       else return (int)st.top();
    }
    
    int getMin() {
        return (int)min;
    }
};