#include<iostream>
#include<stack>
using namespace std;
void stockSpan(int arr[], int n){
    stack<int>st;
    int ans[n];
    ans[0]=1;
    st.push(0);
    for(int i=1;i<n;i++){
        while(st.size()>0 && arr[st.top()]<=arr[i]){
            st.pop();
        }
        if(st.size()==0) ans[i]=-1;
        else ans[i]=st.top();
         ans[i]=i-ans[i];
        st.push(i);
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){
        int arr[]={100,80,60,81,70,60,75,85};
        int n = sizeof(arr)/sizeof(arr[0]);
        stockSpan(arr,n);
}