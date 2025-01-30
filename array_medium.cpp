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