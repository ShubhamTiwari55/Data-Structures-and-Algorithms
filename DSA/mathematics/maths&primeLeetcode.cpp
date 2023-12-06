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

int main(){
}