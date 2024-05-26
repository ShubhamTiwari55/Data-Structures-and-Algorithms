// Leetcode ques no. 307 --> Range sum query - mutable
class NumArray {
public:
    vector<int> sgt;
    int n;
    void buildTree(vector<int> &nums, int i, int lo, int hi){
        if(hi==lo){
            sgt[i] = nums[hi];
            return;
        }
        int mid = lo+(hi-lo)/2;
        buildTree(nums, 2*i+1, lo, mid);
        buildTree(nums, 2*i+2, mid+1, hi);
        sgt[i] = sgt[2*i+1]+sgt[2*i+2];
    }
    NumArray(vector<int>& nums) {
     n = nums.size();
     sgt.resize(4*n);
     buildTree(nums, 0, 0, n-1);   
    }
    
    void updateval(int i, int lo, int hi, int& index, int& val){
        if(lo==hi){
            sgt[i] = val;
            return;
        }
        int mid = lo+(hi-lo)/2;
        if(index<=mid) updateval(2*i+1,lo,mid,index,val);
        else updateval(2*i+2,mid+1,hi,index,val);
        sgt[i] = sgt[2*i+1] + sgt[2*i+2];
    }

    void update(int index, int val) {
        updateval(0,0,n-1,index,val);
    }
    int getsum(int i, int lo, int hi, int& l, int& r){
    if(l>hi || r<lo) return 0;
    if(lo>=l && hi<=r) return sgt[i];
    int mid = lo+(hi-lo)/2;
    int leftsum = getsum(2*i+1, lo, mid, l, r);
    int rightsum = getsum(2*i+2, mid+1, hi, l, r);
    return leftsum + rightsum;
    }

    int sumRange(int left, int right) {
        return getsum(0, 0, n-1, left, right);
    }
};


// leetcode ques no. 2080 -> Range frequencies query
class RangeFreqQuery {
public:
vector<unordered_map<int,int>> sgt;
int n;
unordered_map<int,int> addMaps(unordered_map<int,int> &mp1, unordered_map<int,int>&mp2){
    unordered_map<int,int> ans;
    for(auto x:mp1){
        ans.insert(x);
    }
    for(auto x:mp2){
        int key = x.first;
        int freq = x.second;
        if(ans.find(key)==ans.end()){ //not found in ans map
            ans.insert(x);
        }
        else ans[key]+=freq;
    }
    return ans;
}
void buildTree(vector<int> &arr, int i, int lo, int hi){
    if(lo==hi){
        sgt[i][arr[lo]] = 1;
        return;
    }
    int mid = lo+(hi-lo)/2;
    buildTree(arr, 2*i+1, lo, mid);
    buildTree(arr, 2*i+2, mid+1, hi);
    sgt[i] = addMaps(sgt[2*i+1],sgt[2*i+2]);
}
    RangeFreqQuery(vector<int>& arr) {
        n = arr.size();
        sgt.resize(4*n);
        buildTree(arr,0,0,n-1);
    }
    int getFreq(int i, int lo, int hi, int l, int r, int key){
        if(l>hi || r<lo) return 0;
        if(lo>=l and hi<=r){
            if(sgt[i].find(key)==sgt[i].end()) return 0;
            else return sgt[i][key];
        }
        int mid = lo+(hi-lo)/2;
        int leftAns = getFreq(2*i+1, lo, mid, l, r, key);
        int rightAns = getFreq(2*i+2, mid+1, hi, l, r, key);
        return leftAns+rightAns;
    }
    int query(int left, int right, int value) {
        return getFreq(0,0,n-1,left,right,value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */