#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

//leetcode ques no. 2507 -> Smallest Value After Replacing With Sum of Prime Factors
class Solution {
public:
    bool isPrime(int n){
            if(n==1) return false;
            for(int i=2;i<=sqrt(n);i++){
                if(n%i==0) return false;
            }
            return true;
        }
    int smallestValue(int num) {
        if(isPrime(num)) return num;
        int sum = 0;
        for(int i=1;i<sqrt(num);i++){
            if(num%i==0 && isPrime(i)){
                int m = num;
                while(m%i==0){
                    sum+=i;
                    m/=i;
                }
            }
        }
        for(int i=sqrt(num);i>1;i--){
            if(num%i==0 && isPrime(num/i)){
                int m = num;
                while(m%(num/i)==0){
                    sum+=num/i;
                    m/=(num/i);
                }
            }
        }
        if(sum==num) return num;
        return smallestValue(sum);
    }
};

// leetcode ques no. 204 -> count primes
class Solution {
public:
	int countPrimes(int n) {
		//prime no. generation
		vector<bool> prime(n + 1, true);
		prime[0] = false;
		prime[1] = false;
		for (int i = 2; i <= sqrt(n); i++) {
			if (prime[i]) {
				for (int j = i * 2; j <= n; j += i) {
					prime[j] = false;
				}
			}
		}
		//counting prime numbers
		int primeCount = 0;
		for (int i = 2; i < n; i++) {
			if (prime[i]) {
				primeCount++;
			}
		}
		return primeCount;
	}
};

// Leetcode ques no. 2521 -> Distinct Prime Factors of Product of Array.
class Solution {
public:
    void fillSieve(vector<bool> &sieve){
        int n = sieve.size()-1;
        for(int i=2; i<=sqrt(n); i++){
            for(int j=i*2; j<=n; j+=i){  // Use 'i' as the increment here
                sieve[j] = 0;
            }
        }
    }

    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;
        for(int i=0; i<n; i++){
            mx = max(mx, nums[i]);
        }
        vector<bool> sieve(mx + 1, 1);
        if (mx + 1 > 0) sieve[0] = 0;
        if (mx + 1 > 1) sieve[1] = 0;
        fillSieve(sieve);
        vector<int> primes;
        for(int i=2; i<=mx; i++){
            if(sieve[i] == 1) primes.push_back(i);
        }
        vector<bool> taken(primes.size(), 0);
        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            for(int j=0; j<primes.size(); j++){  // Change 'i' to 'j' here
                if(primes[j] > ele) break;
                if(ele % primes[j] == 0) taken[j] = 1;
            }
        }
        int count = 0;
        for(int i=0; i<taken.size(); i++){
            if(taken[i] == 1) count++;
        }
        return count;
    }
};

// Leetcode ques no. 650 -> 2 keys keyboard
class Solution {
public:
int gd(int n){
    for(int i=n/2;i>=1;i--){
        if(n%i==0) return i;
    }
    return 0;
}
// hf -> highest factor
// gd = greatest divisor
    int minSteps(int n) {
        int count = 0;
        while(n>1){
            int hf = gd(n);
            count += n/hf;
            n = hf;
        }
        return count;
    }
};


int main(){
}