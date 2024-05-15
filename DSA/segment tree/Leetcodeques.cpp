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