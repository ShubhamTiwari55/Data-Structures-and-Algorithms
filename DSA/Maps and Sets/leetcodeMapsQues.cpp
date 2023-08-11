#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

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
int main(){
}