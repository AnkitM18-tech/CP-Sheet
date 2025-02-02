#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    /*
    // Brute
    vector<int> temp;
    for(int i=0;i<n;i++) {
        if(nums[i] != 0) {
            temp.push_back(nums[i]);
        }
    }

    int nz = temp.size();

    for(int i=0;i<nz;i++){
        nums[i] = temp[i];
    }
    for(int i=nz;i<n;i++) {
        nums[i] = 0;
    }
    */
    // Optimal
    int j = -1;
    for(int i=0;i<n;i++) {
        if(nums[i] == 0) {
            j = i;
            break;
        }
    }
    
    if(j == -1) return;

    for(int i=j+1;i<n;i++) {
        if(nums[i] != 0) {
            swap(nums[i],nums[j]);
            j++;
        }
    }
}

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) return 0;
    int n = nums.size();
    /*
    // Brute
    set<int> temp;
    for(int num:nums) {
        temp.insert(num);
    }
    int k = temp.size();

    int j = 0;
    for(int num:temp) {
        nums[j] = num;
        j++;
    }
    return k;
    // TC - O(N * log N) for set + O(N) traverse array
    */
    // Optimal
    int i = 0;

    for(int j=1;j<n;j++) {
        if(nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
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