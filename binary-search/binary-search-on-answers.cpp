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
    // max limit can be = size of array - ceil every member to 1
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

int findMax(vector<int> &nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++) {
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

long long calculateHours(vector<int> &nums, int hourlyRate) {
    long long totalHours = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++) {
        totalHours += ceil((double)nums[i]/(double)hourlyRate);
    }
    return totalHours;
}

int linearMinimumRate(vector<int> &nums, int h) {
    int n = nums.size();
    int maxi = findMax(nums);

    for(int i = 1; i<=maxi; i++) {
        long long reqTime = calculateHours(nums,i);
        if(reqTime <= (long long)h) {
            return i;
        }
    }
    return maxi;
    // O(max * N), where max is the maximum 
    // element in the array and N is the size of the array
}

int minimumRateToEatBananas(vector<int> &nums, int h) {
    int low = 1, high = findMax(nums);
    while(low <= high) {
        int mid = (low + high)/2;
        int totalHours = calculateHours(nums,mid);
        if(totalHours <= h) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
    // O(N * log(max)), where max is the 
    // maximum element in the array and N is size of the array
}

 bool possible(vector<int> &nums, int day, int m, int k) {
    int n = nums.size();
    int cnt = 0, noOfBqt = 0;
    for(int i = 0; i<n; i++) {
        if(nums[i] <= day) {
            cnt++;
        } else {
            noOfBqt += (cnt/k);
            cnt = 0;
        }
    }
    noOfBqt += (cnt/k);

    return noOfBqt >= m;
}

int linearRoseGarden(int n, vector<int> &nums, int k, int m) {
    long long val = m * 1ll * k * 1ll;

    /* Impossible case: not enough 
    flowers to make m bouquets*/
    if(val > n) return -1;

    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, nums[i]); 
        maxi = max(maxi, nums[i]); 
    }

    for(int i = mini; i <= maxi; i++) {
        if(possible(nums,i,m,k)) {
            return i;
        }
    }
    return -1;
    // O((max-min+1) * N), where max is the maximum element of the array, 
    // min is the minimum element of the array, N is size of the array}.
}

int roseGarden(int n,vector<int> &nums, int k, int m) {
    long long val = m * 1ll * k * 1ll;
    /* Impossible case: not enough 
    flowers to make m bouquets*/
    if(val > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        mini = min(mini, nums[i]); 
        maxi = max(maxi, nums[i]); 
    }
    int low = mini, high = maxi, ans = -1;
    while(low <= high) {
        int mid = low + (high - low)/2; // eq - low + high
        if(possible(nums,mid,m,k)) {
            ans = mid;
            high = mid -1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
    // O(log(max-min+1) * N), where max is the maximum element of the array, 
    // min is the minimum element of the array, N is size of the array.
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