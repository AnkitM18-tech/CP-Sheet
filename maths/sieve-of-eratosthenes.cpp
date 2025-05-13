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

#define MAX_N 100000
/* To store the smallest prime factors for 
all number with all nodes initially 
having smallest prime factor as 1 */
vector<int> SPF(MAX_N + 1, 1);

class PrimeFactorisationOfNumber{
    private:
        vector<int> primeFactorisation(int n) {
            vector<int> ans;
            /* Keep dividing the number with 
            2 till it is possible */
            while(n % 2 == 0) {
                ans.push_back(2);
                n /= 2;
            }

            /* Start iterating from 3 skipping 
            one number (because n is now odd) */
            for(int i = 3; i*i <= n; i += 2) {
                while(n % i == 0) {
                    ans.push_back(i);
                    n /= i;
                }
            }

            // edge case
            if(n > 2) ans.push_back(n);
            return ans; 
        }

        void sieve() {
            for(int i = 2; i <= MAX_N; i++) {
                if(SPF[i] == 1) {
                    /* Mark all its multiples who have not 
                    received their smallest prime factor yet*/
                    for(int j = i; j <= MAX_N; j += i) {
                        if(SPF[j] == 1) {
                            SPF[j] = i;
                        }
                    }
                }
            }
            return;
        }

        vector<int> primeFact(int n) {
            vector<int> ans;

            while(n != 1) {
                // Add the smallest prime factor to the list
                ans.push_back(SPF[n]);
                // Update the number
                n = n / SPF[n];
            }

            return ans;
        }

    public:
        vector<vector<int>> primeFactors(vector<int>& queries){
            /*
                // Brute - TC = O(N x num^1/2), SC = O(N x log2(num))
                vector<vector<int>> ans;

                for(int i = 0; i < queries.size(); i++) {
                    ans.push_back(primeFactorisation(queries[i]));
                }

                return ans;
            */
            // Optimal
            vector<vector<int>> ans;
            /* Pre compute the smallest 
            possible factor for all numbers */
            sieve();

            for(int i = 0; i < queries.size(); i++) {
                ans.push_back(primeFact(queries[i]));
            }
            return ans;
            // TC = O(max_N x log(log(max_N))) + O(N x log(num)) 
            // (where N represent the number of queries, num represents the average 
            // number in the queries and max_N = 10^5)

            // SC = O(max_N) + O(N x log(num))
            // The SPF array takes O(max_N) space and the space 
            // taken by list to store the result is O(N x log(num)).
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