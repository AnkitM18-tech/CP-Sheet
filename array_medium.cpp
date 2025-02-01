#include<bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& nums, int target) {
    for(int i=0;i<nums.size();i++) {
        if(nums[i] == target) return i;
    }
    return -1;
}

int largestElement(vector<int>& nums) {
    /*
    sort(nums.begin(),nums.end());
    return nums[nums.size()-1];
    TC - O(N * log N)
    */
    int largest = nums[0];
    for(int i=1;i<nums.size();i++){
        if(nums[i]>largest) largest = nums[i];
    }
    return largest;
} // TC - O(N)

int secondLargestElement(vector<int>& nums) {
    int n = nums.size();
    if(n<2) return -1;
    /*
    // Brute Force
    sort(nums.begin(),nums.end());
    int largest = nums.back();
    int secondLargest = -1;
    for(int i=n-2;i>=0;i--){
        if(nums[i] != largest){
            secondLargest = nums[i];
            break;
        }
    }
    return secondLargest;
    //TC - O(N * log N) 
    
    // Better
    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0;i<n;i++){
        if(nums[i] > largest) {
            largest = nums[i];
        }
    }
    for(int i=0;i<n;i++) {
        if(nums[i] != largest && nums[i] > secondLargest) {
            secondLargest = nums[i];
        }
    }

    return secondLargest == INT_MIN ? -1 : secondLargest;
    // TC -  O(N) + O(N) = O(2N)
    */
    // Best
    int largest = INT_MIN, secondLargest = INT_MIN;
    for(int i=0;i<n;i++) {
        if(nums[i] > largest) {
            secondLargest = largest;
            largest = nums[i];
        } else if(nums[i] > secondLargest && nums[i] != largest) {
            secondLargest = nums[i];
        }
    }
    return secondLargest == INT_MIN ? -1 : secondLargest;
}

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCnt = 0, cnt = 0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i] == 1) {
            cnt += 1;
            maxCnt = max(maxCnt,cnt);
        } else {
            cnt = 0;
        }
    }
    return maxCnt;
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