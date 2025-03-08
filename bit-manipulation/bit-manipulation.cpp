#include<bits/stdc++.h>
using namespace std;

int minBitsFlip(int start, int goal) { 
    int num = start ^ goal;

    int cnt = 0;
    while(num) {
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt; // O(1)
}

int singleNumber(vector<int>& nums){
    /*
    // Brute - O(N) - TC & SC
    unordered_map<int,int> mpp;

    for(int i = 0; i< nums.size(); i++) {
        mpp[nums[i]]++;
    }

    for(auto it: mpp) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
    */
    // Optimal - TC - O(N), SC - O(1)
    int XOR = 0;

    for(int i = 0; i<nums.size(); i++) {
        XOR ^= nums[i];
    }

    return XOR;
}

int singleNumber2(vector<int>& nums) {
    /*      
    // Brute - O(N) - SC ,TC
    unordered_map<int,int> mpp;

    for(int i = 0; i<nums.size(); i++) {
        mpp[nums[i]]++;
    }

    for(auto it : mpp) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
    
    // Better - 1 - O(32*N)
    int n = nums.size();

    int ans = 0;

    // Checking every bit position
    for(int bitIndex = 0; bitIndex < 32; bitIndex++) {
        // Variable to count number of 
        // set bits in bitIndex position 
        int cnt = 0;
        for(int i = 0; i<n; i++) {
            // Counting elements having set
            // bits at bitIndex position
            if(nums[i] & (1 << bitIndex)) {
                cnt++;
            }
        }

        // Updating bits in answer
        if(cnt % 3 != 0) {
            ans |= (1 << bitIndex);
        }
    }
    return ans;
    
    // Better - 2 - O(Nlog(N))
    int n = nums.size();

    sort(nums.begin(), nums.end());

    for(int i = 1; i<nums.size(); i+=3) {
        if(nums[i] != nums[i-1]) {
            return nums[i-1];
        }
    }

    // If not found till now, then 
    // the last number will be single
    return nums[n-1];
    */
    // Optimal - O(N)
    int ones = 0, twos = 0;

    for(int i = 0; i < nums.size(); i++) {
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }

    return ones;
}

vector<int> singleNumber3(vector<int>& nums){
    int n = nums.size();
    /*
    // Brute - SC - O(N) ans TC - O(N)
    vector<int> ans;
    unordered_map<int,int> mpp;

    for(int i = 0; i<n; i++) {
        mpp[nums[i]]++;
    }

    for(auto it : mpp) {
        if(it.second == 1) {
            ans.push_back(it.first);
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
    */
    // Optimal - O(2N)
    long XOR = 0;
    for(int i = 0; i<n; i++) {
        XOR = XOR ^ nums[i];
    }
    // Variable to get the rightmost 
    // set bit in overall XOR
    int rightmost = (XOR & (XOR - 1)) ^ XOR;
    int XOR1 = 0, XOR2 = 0;

    for(int i = 0; i<n; i++) {
        if(nums[i] & rightmost) {
            XOR1 = XOR1 ^ nums[i];
        } else {
            XOR2 = XOR2 ^ nums[i];
        }
    }

    if(XOR1 < XOR2) return {XOR1, XOR2};
    return {XOR2, XOR1};
}

int divide(int dividend, int divisor) {
    if(dividend == divisor) return 1;

    bool isPositive = true;

    if(dividend >= 0 && divisor < 0) {
        isPositive = false;
    } else if(dividend < 0 && divisor > 0) {
        isPositive = false;
    }

    int n = abs(dividend);
    int d = abs(divisor);
    /*
    // Brute - O(dividend)

    int ans = 0, sum = 0;

    while(sum + d <= n) {
        ans++;
        sum += d;
    }
    */
    // Optimal - O((logN)^2)
    int ans = 0;

    while(n >= d) {
        int cnt = 0;
        while(n >= (d << (cnt + 1))) {
            cnt++;
        }

        ans += (1 << cnt);
        n -= d*(1 << cnt);
    }

    if(ans > INT_MAX && isPositive) {
        return INT_MAX;
    }
    if(ans > INT_MAX && !isPositive) {
        return INT_MIN;
    }

    return isPositive ? ans : -1 * ans;
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