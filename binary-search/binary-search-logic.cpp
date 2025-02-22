#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)  {
    int n = nums.size();
    /*
    // Brute
    for(int i = 0; i<n; i++) {
    if(nums[i] >= target) {
        return i;
    }
    }
    return n; // O(N)
    */
    // Optimal
    int low = 0, high = n-1;
    int ans = n;
    while(low <= high) {
    int mid = (low + high)/2;
    if(nums[mid] >= target) {
        ans = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
    }
    return ans; // O(log N)
}

int findFloor(vector<int> nums, int x) {
    int ans = -1, n = nums.size();
    /*
    // Brute - O(N)
    for(int i = 0; i<n; i++) {
        if(nums[i] <= x) {
            ans = nums[i];
        } else {
            break;
        }
    }
    return ans;
    */
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] <= x) {
            ans = nums[mid];
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int findCeil(vector<int> nums, int x) {
    int ans = -1, n = nums.size();
    /*
    // Brute - O(N)
    for(int i = 0; i<n; i++) {
        if(nums[i] >= x) {
            ans = nums[i];
            break;
        } else {
            continue;
        }
    }
    return ans;
    */
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] >= x) {
            ans = nums[mid];
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

vector<int> getFloorAndCeil(vector<int> nums, int x) {
    int n = nums.size();
    // Optimal
    int floor = findFloor(nums,x);
    int ceil = findCeil(nums,x);
    return {floor,ceil}; // O(log N)
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