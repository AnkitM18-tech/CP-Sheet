#include<bits/stdc++.h>
using namespace std;

int recursion(vector<int> nums,int low, int high, int target) {
    if(low > high) {
        return -1;
    }
    int mid = low + (high - low)/2; // Overflow case eq (low + high)/2 
    // when low and high point to last index which can be INT_MAX
    if(nums[mid] == target) {
        return mid;
    } else if(target > nums[mid]) {
        return recursion(nums,mid+1,high,target);
    } else {
        return recursion(nums,low,mid-1,target);
    }
}

int search(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1;
    /*
    // Iterative - O(log N)
    while (low <= high) {
        int mid = (low + high) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
    */
    // Recursive
    return recursion(nums,0,nums.size()-1,target);
    // O(logN) - TC , SC - O(logN) - recursion stack space
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