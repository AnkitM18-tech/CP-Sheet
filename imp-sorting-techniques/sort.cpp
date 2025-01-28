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
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    return 0;
}