#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

class TreeNode {
public:
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int val){
        this->left=NULL;
        this->right=NULL;
        this->val=val;
     }
 };
//leetcode ques no. 242 -> valid anagram//
class Solution {
public:
//using the concept of frequency array
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map1;
        unordered_map<char,int> map2;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            map2[t[i]]++;
        }
        for(auto x:map1){
            char ch1 = x.first;
            int freq1 = x.second;
            if(map2.find(ch1)!=map2.end()){
                int freq2 = map2[ch1];
                if(freq2!=freq1) return false;
            }
            else return false;
        }
        return true;
    }
};
//method 2..
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> map1;
        for(int i=0;i<s.length();i++){
            map1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            char ch = t[i];
            if(map1.find(ch)!=map1.end()){
                map1[ch]--;
                if(map1[ch]==0) map1.erase(ch);
            }
            else return false;
        }
        if(map1.size()>0) return false;
        return true;
    }
};

//leetCode ques no. 1 -> Two sum//
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int rem = target - nums[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(m[rem]);
                ans.push_back(i);
            }
            else m[nums[i]] = i;
        }
        return ans;
    }
};

//leetcode ques no. 1207 -> Unique Number of Occurrences//
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }    
        unordered_set<int> s;
        for(auto x:m){
            int freq = x.second;
            if(s.find(freq)!=s.end()) return false;
            else s.insert(freq);
        }
        return true;
    }
};

//leetCode ques no. 2094 -> Finding 3-Digit Even Numbers
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        unordered_map<int,int> m;
        for(int ele:arr){
            m[ele]++;
        }
        for(int i=100;i<=999;i+=2){
            int x = i;
            int a = x%10;  //one's place digit
            x = x/10;
            int b = x%10;   //tens place digit
            x = x/10;
            int c = x;      //Hundred's place digit
            if(m.find(a)!=m.end()){
                    m[a]--;
                    if(m[a]==0) m.erase(a);
                    if(m.find(b)!=m.end()){
                        m[b]--;
                         if(m[b]==0) m.erase(b);
                        if(m.find(c)!=m.end()) ans.push_back(i);
                        m[b]++;
                    }
                    m[a]++;
            }
        }
        return ans;
    }
};

//LeetCode ques no. 1814 -> Count nice pairs in an array//
class Solution {
public:
    int rev(int n){
        int r = 0;
        while(n>0){
            r *= 10;
            r += n%10;
            n/=10;
        }
        return r;
    } 
    int countNicePairs(vector<int>& nums) {
        //for every i in nums -> nums[i] = nums[i]-rev(nums[i])//
        int n = nums.size();
        int count = 0;
        for(int i=0;i<n;i++){
            nums[i] = nums[i] - rev(nums[i]);
        }
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){

     // we are finding if the element is already present or not and if present then its frequency is added to count as the new occurrence which is to be added can form pair with all the occurences of the element already present //

            if(m.find(nums[i])!=m.end()){
               count = count%1000000007;
                count += m[nums[i]];
                m[nums[i]]++; 
            }
            else m[nums[i]]++;
        }
        //Use of this modulo operator is specified iin question//
        return count%1000000007;
    }
};

//LeetCode ques no. 138 -> copy list with random pointer
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
//Actual solution starts from here...
class Solution {
public:
    Node* copyRandomList(Node* head) {
       //create deep copy without random color
       Node* dummy = new Node(100);
       Node* temp = head;
       Node* tempC = dummy;
       while(temp){
           Node* a = new Node(temp->val);
        tempC->next = a;
           tempC = tempC->next;
              temp = temp->next; 
       }
       Node* b = dummy->next;
       Node* a = head;
       unordered_map<Node*, Node*> m;
       Node* tempa = a;
       Node* tempb = b;
       while(tempa!=NULL){
           m[tempa] = tempb;
           tempa = tempa->next;
           tempb = tempb->next;
       }
       for(auto x:m){
           Node* o = x.first;
           Node* d = x.second;
           if(o->random!=NULL){
               Node* dRandom = m[o->random];
               d->random = dRandom;
           }
       }
       return b;
    }
};

//leetcode ques no. 560 -> subarray sum equals k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> pre(nums.size(),0);
        pre[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i] = nums[i]+pre[i-1];
        }
        unordered_map<int, int> m;
        int count = 0;
       for(int i=0;i<nums.size();i++){
            if(pre[i]==k){
               count++;
           }
               int rem = pre[i]-k;
               if(m.find(rem)!=m.end()) count+=m[rem];
                m[pre[i]]++;
        }
        return count;
    }
};

//leetcode ques no. 2385 -> Amount of time for binary tree to be infected//
class Solution {
public:
TreeNode* first = NULL;
void find(TreeNode* root, int start){
    if(root==NULL) return;
    if(root->val == start) first = root;
    find(root->left, start);
    find(root->right, start);
}
void markParent(TreeNode* root,unordered_map<TreeNode*, TreeNode*>& parent){
    if(root==NULL) return;
    if(root->left!=NULL) parent[root->left] = root;
    if(root->right!=NULL) parent[root->right] = root;
    markParent(root->left, parent);
    markParent(root->right, parent);
}
    int amountOfTime(TreeNode* root, int start) {
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root,parent);
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue< pair<TreeNode*, int> >q;
        q.push({first,0});
        int maxLevel = 0;
        while(q.size()>0){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel, level);
            TreeNode* temp = p.first;
            if(temp->left!=NULL){
                if(s.find(temp->left)==s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right!=NULL){
                if(s.find(temp->right)==s.end()){
                    q.push({temp->right, level+1});
                    s.insert(temp->right);
                }
            }
            //checking for the parent element using maps
            if(parent.find(temp)!=parent.end()){
                if(s.find(parent[temp])==s.end()){
                    q.push({parent[temp], level+1});
                    s.insert(parent[temp]);
                }
            }
        }
        return maxLevel;
    }
};

//leetcode ques no. 49 -> Group Anagrams//
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string, vector<string>>m;
        for(int i=0;i<arr.size();i++){
            string str = arr[i];
            sort(str.begin(),str.end());
            if(m.find(str)==m.end()){
                vector<string> v;
                v.push_back(arr[i]);
                m[str] = v;
            }
            else{
                m[str].push_back(arr[i]);
            }
        }
        vector<vector<string>> ans;
        for(auto x:m){
            ans.push_back(x.second);
        }
        return ans;
    }
};

//leetcode ques no. 1657 -> Determine if two strings are close//
class Solution {
public:
    bool closeStrings(string str1, string str2) {
        if(str1.length()!=str2.length()) return false;
        unordered_map<char,int>m1,m2;
        for(int i=0;i<str1.length();i++){
            m1[str1[i]]++;
            m2[str2[i]]++;
        }
        for(auto x:m1){
            char ch = x.first;
            if(m2.find(ch)==m2.end()) return false;
        }
        unordered_map<int,int> h1,h2;
        for(auto x:m1){
            int freq = x.second;
            h1[freq]++;
        }
        for(auto x:m2){
            int freq = x.second;
            h2[freq]++;
        }
        for(auto x:h1){
            int key = x.first;
            int freq = x.second;
        if(h2.find(key)==h2.end()) return false;
        if(h2[key]!=h1[key]) return false;
        }
        return true;
    }
};

int main(){
}