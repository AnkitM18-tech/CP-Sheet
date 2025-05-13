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

class CountPrimesInRange{
    private:
        bool isPrime(int n) {
            if(n <= 1) return false;
            for(int i = 2; i*i <= n; i++) {
                if(n % i == 0) return false;
            }
            return true;
        }
    public:
        vector<int> primesInRange(vector<vector<int>>& queries){
            vector<int> result;
            /*
                // Brute - TC = O(Q * (R-L+1) * √R)
                for(auto& query: queries) {
                    int l = query.first;
                    int r = query.second;
                    int count = 0;

                    for(int j = l; j <= r; j++) {
                        if(isPrime(j)) count++;
                    }
                    result.push_back(count);
                }
                return result;
            */
            // Optimal - TC = O(N log (log N)), SC = O(N)
            if (queries.empty()) return {};

            // Find the maximum value in the queries 
            // to determine the sieve range
            int maxVal = 0;
            for(const auto& query : queries) {
                maxVal = max(maxVal, query[1]);
            }

            // Step 1: Use the Sieve of Eratosthenes 
            // to find all primes up to maxVal
            vector<bool> isPrime(maxVal + 1, true);
            isPrime[0] = isPrime[1] = false;
            for(int i = 2; i * i <= maxVal; i++) {
                if(isPrime[i]) {
                    for(int j = i * i; j <= maxVal; j += i) {
                        isPrime[j] = false;
                    }
                }
            }

            // Step 2: Create a prefix sum array 
            // to count primes up to each number
            vector<int> primeCount(maxVal + 1, 0);
            for(int i = 1; i<= maxVal; i++) {
                primeCount[i] = primeCount[i-1];
                if(isPrime[i]) {
                    primeCount[i]++;
                }
            }

            // Step 3: Process each query to find the number of primes 
            // in the given range
            for(const auto& query : queries) {
                int start = query[0];
                int end = query[1];
                if(start == 0) {
                    result.push_back(primeCount[end]);
                } else {
                    result.push_back(primeCount[end] - primeCount[start - 1]);
                }
            }
            return result;
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