#include<iostream>
#include<climits>
using namespace std;
float max(float a,float b){
    if(a>=b) return a;
    else return b;
}
float min(float a,float b){
    if(a<=b) return a;
    else  return b;
}
int main(){
    int arr[]={5,3,10,3};
    int n=4;
    float kmin=(float)(INT_MIN);
    float kmax=(float)(INT_MAX);
    bool flag=true;

    // kmin and kmax values can be found by using the equation |a1-k|<|a2-k| and then |a2-k|<|a3-k| and so on for all the elements in the array; after solving the above equations we can observe the below if-else conditons //
    
    for(int i=0;i<n-1;i++){
        if(arr[i]>=arr[i+1]){
         kmin = max(kmin,(arr[i]+arr[i+1])/2.0); 
        }
        else {
              kmax = min(kmax,(arr[i]+arr[i+1])/2.0);
        }
        if(kmin>kmax){
            flag=false;
            break;
        }
    }
   if(flag==false) cout<<-1;
   else if (kmin==kmax){
    if(kmin-(int)kmin==0){
        cout<<"There is only one value of k which is "<<(int)kmin;
    }
    else cout<<-1;
   }
   if(kmin-(int)kmin>0){
    kmin=(int)kmin+1;
   }
    else cout<<"The range is ("<<(int)(kmin)<<","<<(int)kmax<<")";

}