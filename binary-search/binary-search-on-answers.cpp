#include<bits/stdc++.h>
using namespace std;

long long floorSqrt(long long n)  {
    /*
    // Linear
    long long ans = 0;
    for(long long i = 1; i<=n; i++) {
    long long sq = i * i;
    if(sq <= n * 1ll) {
        ans = i;
    } else {
        break;
    }
    }
    return ans; // O(N ^ 1/2)
    */
    long long low = 1, high = n;
    while(low <= high) {
    long long mid = (low + high)/2;
    long long sq = mid * mid;
    if(sq <= n * 1ll) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
    }
    return high; // O(log N)
}

long long Pow(int b, int exp) {
    long long ans = 1;
    long long base = b;
    
    // Exponentiation by squaring method
    while (exp > 0) {
        if (exp % 2) {
            exp--;
            ans = ans * base;
        } else {
            exp /= 2;
            base = base * base;
        }
    }
    return ans;
} // O(log N)

long long power(int num, int N) {
    long long ans = 1;
    for(int i = 0; i<N; i++) {
        ans *= num;
    }
    return ans;
} // O(N)

// return 1 if == m
// return 0 if < m
// return 2 if > m
int helperFunc(int mid, int n, int m) {
    long long ans = 1, base = mid;
    
    while (n > 0) {
        if (n % 2) {
            ans = ans * base;
            if (ans > m) return 2;  // Early exit
            n--;
        } 
        else {
            n /= 2;
            base = base * base;
            if(base > m) return 2;
        }
    }
    if (ans == m) return 1;
    return 0;
}

int NthRoot(int N, int M) {
    /*
    // Linear
    for(int i = 1; i<= M; i++) {
        long long val = power(i,N);
        if(val == M * 1ll) {
            return i;
        } else if(val > M * 1ll) {
            break;
        }
    }
    return -1;
    */
    int low = 1, high = M;
    while(low <= high) {
        int mid = (low + high)/2;
        int midN = helperFunc(mid,N,M);
        if(midN == 1) {
            return mid;
        } else if(midN == 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // O(logM * logN)
}

int linearSmallestDivisor(vector<int> &nums, int limit) {
    int n = nums.size();
    int maxi = *max_element(nums.begin(),nums.end());

    for(int d = 1; d <= maxi; d++) {
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += ceil((double)nums[i]/(double)d);
        }
        if(sum <= limit) {
            return d;
        }
    }
    return -1; // O(max*N), where max 
    // is the maximum element in the array, N is size of the array.
}

int sumByD(vector<int> &nums, int limit) {
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += ceil((double)nums[i] / (double)limit);
    }
    return sum;
}

int smallestDivisor(vector<int> &nums, int limit) {
    int n = nums.size();
    if(n > limit) return -1;
    int low = 1, high = *max_element(nums.begin(),nums.end());

    while(low <= high) {
        int mid = (low + high)/2;
        if(sumByD(nums,mid) <= limit) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
    // O(log(max)*N), where max is 
    // the maximum element in the array, N is size of the array.
}


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