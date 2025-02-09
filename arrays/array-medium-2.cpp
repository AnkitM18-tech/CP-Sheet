#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> ans;
    /*
    // Brute
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return {-1,-1}; // O(N^2)
    
    // Better
    unordered_map<int,int> mpp;
    for(int i = 0; i < nums.size(); i++) {
        int num = nums[i];
        int reqNum = target - num;
        if(mpp.find(reqNum) != mpp.end()) {
            return {mpp[reqNum],i};
        }
        mpp[num] = i;
    }
    return {-1,-1}; // O(N) - TC - SC
    */
    // Optimal
    vector<vector<int>> index;
    for(int i = 0; i < nums.size(); i++) {
        index.push_back({nums[i],i});
    }

    sort(index.begin(), index.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    int left = 0, right = nums.size()-1;

    while( left < right) {
        int sum = index[left][0] + index[right][0];
        if(sum == target) {
            ans.push_back(index[left][1]);
            ans.push_back(index[right][1]);
            return ans;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return {-1,-1};
    // TC - O(N) + O(NlogN)
    // Here we are distorting the given array. So, if we need 
    // to consider this change, 
    // the space complexity will be O(N).
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