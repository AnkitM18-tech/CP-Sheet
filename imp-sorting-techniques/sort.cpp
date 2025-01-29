#include<bits/stdc++.h>
using namespace std;

// select minimum and sort
vector<int> selectionSort(vector<int>& nums) {
    for(int i = 0;i<nums.size()-1;i++){
        int mini = i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] < nums[mini]) {
                mini = j;
            }
        }
        if(mini != i) {
            swap(nums[mini],nums[i]);
        }
    }
    return nums;
}

// push the max to the last by adjacent swaps
vector<int> bubbleSort(vector<int>& nums) {
    int n = nums.size();
    int didSwap = 0;
    for(int i = n-1;i >= 0;i--) {
        for(int j = 0; j < i;j++) {
            if(nums[j] > nums[j+1]) {
                swap(nums[j],nums[j+1]);
                // if swap happended at any time
                didSwap = 1;
            }
        }
        // if no swaps happened out of the loop as 
        // it is already sorted
        if(didSwap == 0) break;
    }
    return nums;
}

// Take an element and place it in its correct order
vector<int> insertionSort(vector<int>& nums) {
    int n = nums.size();
    for(int i=0;i<n;i++){
        int j = i;
        while(j > 0 && nums[j-1] > nums[j]) {
            swap(nums[j-1],nums[j]);
            j--;
        }
    }
    return nums;
}
// Worst - Avg - O(N^2)
// Best - O(N)

void merge(vector<int>& nums, int low, int mid, int high) {
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high) {
        if(nums[left] <= nums[right]) {
            temp.push_back(nums[left]);
            left++;
        } else {
            temp.push_back(nums[right]);
            right++;
        }
    }

    while(left <= mid) {
        temp.push_back(nums[left]);
        left++;
    }

    while(right <= high) {
        temp.push_back(nums[right]);
        right++;
    }

    for(int i=low;i<=high;i++) {
        nums[i] = temp[i-low];
    }
}

void mergeSortHelper(vector<int>& nums, int low, int high) {
    if(low >= high) return;
    int mid = (low + high)/2;
    mergeSortHelper(nums,low,mid);
    mergeSortHelper(nums,mid+1,high);
    merge(nums,low,mid,high);
}

// Divide and Merge
vector<int> mergeSort(vector<int>& nums) {
    int n = nums.size();
    mergeSortHelper(nums,0,n-1);
    return nums;
} // TC - O(nlogn) , SC - O(n)
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    return 0;
}