#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& a, int num) {
    for(int i = 0; i<a.size(); i++) {
        if(a[i] == num) {
            return true;
        }
    }
    return false;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) {
        return 0;
    }
    /*
    // Brute
    int longest = 1;
    for(int i = 0; i<n; i++) {
        int x = nums[i];
        int cnt = 1;
        while(linearSearch(nums,x+1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(cnt,longest);
    }
    return longest; // O(N^2)
    
    // Better
    sort(nums.begin(),nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0; i<n; i++) {
        if(lastSmaller == nums[i] - 1) {
            cnt += 1;
            lastSmaller = nums[i];
        } else if(nums[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(cnt,longest);
    }
    return longest; //  O(NlogN) + O(N)
    */
   // Optimal
    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i<n; i++) {
        st.insert(nums[i]);
    }
    
    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;

            while(st.find(x+1) != st.end()) {
                x += 1;
                cnt += 1;
            }

            longest = max(longest,cnt);
        }
    }
    return longest; // O(N) + O(2xN) ~ O(3xN)
}

int longestSubarray(vector<int> &nums, int k){
    int n = nums.size();
    /*
    // Brute
    if(n == 0) return 0;
    int longest = 0;
    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += nums[j];
            if(sum == k) {
                longest = max(j-i+1,longest);
                break;
            } else if(sum > k) {
                break;
            }
        }
    }
    return longest; // O(N^2)

    // Optimal - for positives
    int left = 0, right = 0;
    long long sum = nums[0];
    int maxLen = 0;
    while(right < n) {
        while(left <= right && sum > k) {
            sum -= nums[left];
            left++;
        }
        if(sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if(right < n) sum += nums[right];
    }
    return maxLen; // O(N)
    */
    // Better - Only Positives , Optimal - for positives + negatives
    map<long long, int> prefixSum;
    long long sum = 0;
    int maxLen = 0;
    for(int i = 0; i<n; i++) {
        sum += nums[i];
        if(sum == k) {
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(prefixSum.find(rem) != prefixSum.end()) {
            int len = i - prefixSum[rem];
            maxLen = max(maxLen,len);
        }
        if(prefixSum.find(sum) == prefixSum.end()) {
            prefixSum[sum] = i;
        }
    }

    return maxLen; // TC - O(NlogN), SC - O(N)
}

int subarraySum(vector<int> &nums, int k){
    int n = nums.size();
    /*
    // Brute - using 3 loops - one iterating through i -> j // O(N^3)
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int K = i; K <= j; K++) {
                sum += nums[K];
            }
            if (sum == k) {
                cnt++;
            }
        }
    }
    return cnt;
    // Better
    int cnt = 0;
    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += nums[j];
            if(sum == k) {
                cnt++;
            }
        }
    }
    return cnt; // O(N^2)
    */
    // Optimal
    unordered_map<int,int> prefixSumMap;
    int cnt = 0, sum = 0;
    prefixSumMap[0] = 1;
    for(int i = 0; i<n; i++) {
        sum += nums[i];
        int sumToRemove = sum - k;
        cnt += prefixSumMap[sumToRemove];
        prefixSumMap[sum] += 1;
    }
    return cnt; // O(N)
}

int subarraysWithXorK(vector<int> &nums, int k) {
    int n = nums.size();
    int cnt = 0;
    /*
    // Brute - use 3 loops - 3rd => K = i->j
    for(int i = 0; i<n; i++) {
        for(int j = i; j<n; j++) {
            int xorr = 0;
            for(int K = i; K<j; K++) {
                xorr = xorr ^ nums[j];
            }
            if(xorr == k) {
                cnt++;
            }
        }
    }
    return cnt; // O(N^3)

    // Better
    for(int i = 0; i<n; i++) {
        int xorr = 0;
        for(int j = i; j<n; j++) {
            xorr = xorr ^ nums[j];
            if(xorr == k) {
                cnt++;
            }
        }
    }
    return cnt; // O(N^2)
    */
    // Optimal
    map<int,int> mpp;
    mpp[0] = 1;
    int xorr = 0;
    for(int i = 0; i<n; i++) {
        xorr = xorr ^ nums[i];
        int x = xorr ^ k;
        cnt += mpp[x];
        mpp[xorr]++;
    }
    return cnt; // O(Nlog N)
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