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
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    return 0;
}