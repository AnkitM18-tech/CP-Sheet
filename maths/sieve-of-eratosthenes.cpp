#include<bits/stdc++.h>
using namespace std;

class PrintAllPrimesTillN{
    private:
        bool isPrime(int n) {
            int count = 0;
            for(int i = 1; i <= sqrt(n); i++) {
                if(n % i == 0) {
                    count++;
                    if(n / i != i) {
                        count++;
                    }
                }
            }

            if(count == 2) return true;
            return false;
        }

    public:
        vector<int> primeTillN(int n){
            /*
            // Brute - TC = O(N^3/2), SC = O(N / log N)
            //  In the worst case, the number of prime numbers less 
            // than or equal to N is approximately N / logN.
            vector<int> primes;

            for(int i = 2; i <= n; i++) {
                if(isPrime(i)) {
                    primes.push_back(i);
                }
            }

            return primes;
            */
            // Optimal
            vector<int> isPrime(n + 1, 1);
            vector<int> ans;

            for(long long i = 2; i <= n; i++) {
                if(isPrime[i]) {
                    // Store the number in the result
                    ans.push_back(i);

                    // Mark all its multiples as not prime
                    for(long long val = i * i; val <= n; val += i) {
                        // Marking multiples of i as not prime
                        isPrime[val] = 0;
                    }
                }
            }
            return ans;
            // TC = O(N x log(logN)) The Sieve of Eratosthenes algorithm is 
            // used which takes O(N x log(logN)) time.- mathematically proved
            // prime harmonic series

            // SC = O(N)
        }
};



int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        
    }
    return 0;
}