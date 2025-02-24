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

vector<int> linearSearch(vector<int> &nums, int target) {
    int n = nums.size();
    int start = -1, end = -1;
    for(int i = 0; i<n; i++) {
        if(nums[i] == target) {
            if(start == -1) start = i;
            end = i;
        }
    }
    return {start,end}; // O(N)
}
int lowerBound(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, ans = n;
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
int upperBound(vector<int> &nums, int target) {
    int n = nums.size();
    int low = 0, high = n-1, ans = n;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] > target) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans; // O(log N)
}
int first(vector<int> &nums, int target) {
    int n = nums.size(), ans = -1;
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == target) {
            ans = mid;
            high = mid - 1;
        } else if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}
int last(vector<int> &nums, int target) {
    int n = nums.size(), ans = -1;
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == target) {
            ans = mid;
            low = mid + 1;
        } else if(nums[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int> &nums, int target) {
    // Linear Search - O(N)
    // return linearSearch(nums,target);
    /*
    // Using Bounds - 2*O(log N)
    int start = lowerBound(nums,target);
    if(start == nums.size() || nums[start] != target) return {-1,-1};
    int end = upperBound(nums,target) - 1;
    return {start,end};
    */
    // Binary Search - O(log N)
    int start = first(nums,target);
    if(start == -1) return {-1,-1};
    int end = last(nums,target);
    return {start,end};
}

int linearSearch2(vector<int> &nums, int target) {
    int n = nums.size();
    for(int i = 0; i<n; i++) {
        if(nums[i] == target) {
            return i;
        }
    }
    return -1; // O(N)
}

int search(vector<int> &nums, int k) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while(low <= high) {
    int mid = (low + high)/2;
    if(nums[mid] == k) {
        return mid;
    }
    if(nums[low] <= nums[mid]) {
        if(nums[low] <= k && k <= nums[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } else {
        if(nums[mid] <= k && k <= nums[high]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    }
    return -1; // O(log N)
}

bool linearSearchRotatedArray(vector<int> &nums, int k) {
    int n = nums.size();
    for(int i = 0; i<n; i++) {
        if(nums[i] == k) {
            return true;
        }
    }
    return false; // O(N)
}

bool searchInARotatedSortedArrayII(vector<int> &nums, int k)  {
    int n = nums.size();
    int low = 0, high = n-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if(nums[mid] == k) return true;
        if(nums[mid] == nums[low] && nums[mid] == nums[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= k && k <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if(nums[mid] <= k && k <= nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }
    return false; // O(log N)
}

int linearSearchFindmin(vector<int> &arr) {
    int n = arr.size();
    int minNum = INT_MAX;
    for(int i = 0; i<n; i++) {
        minNum = min(minNum, arr[i]);
    }
    return minNum; // O(N)
}

int findMin(vector<int> &arr)  {
    int n = arr.size();
    int low = 0, high = n-1, ans = INT_MAX;
    while(low <= high) {
        int mid = (low + high)/2;
        // search space sorted already
        if(arr[low] <= arr[high]) {
            ans = min(arr[low],ans);
            break;
        }
        if(arr[low] <= arr[mid]) {
            ans = min(ans,arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans,arr[mid]);
            high = mid - 1;
        }
    }
    return ans; // O(log N)
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