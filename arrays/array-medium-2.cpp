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

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    /*
    // Brute
    set<vector<int>> ans;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n-1; j++) {
            for(int k = j + 1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> triplet(ans.begin(),ans.end());
    return triplet;
    // SC - O(2 x no. of the unique triplets)
    // TC - O(N^3 x log(no. of unique triplets))
    
    // Better
    set<vector<int>> triplet;
    for(int i = 0; i<n; i++) {
        set<int> hashset;
        for(int j = i + 1; j<n;j++) {
            int third = -(nums[i] + nums[j]);
            if(hashset.find(third) != hashset.end()) {
                vector<int> temp = {nums[i],nums[j],third};
                sort(temp.begin(),temp.end());
                triplet.insert(temp);
            }
            hashset.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(triplet.begin(),triplet.end());
    return ans;
    // SC - O(2 x no. of the unique triplets) + O(N)
    // TC - O(N^2 x log(no. of unique triplets))
    */
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());

    for(int i = 0; i<n;i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue;

        int j = i+1;
        int k = n-1;

        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if( sum > 0) {
                k--;
            } else {
                vector<int> temp = {nums[i],nums[j],nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j < k && nums[j] == nums[j-1]) j++;
                while(j < k && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return ans;
    // TC - O(NlogN)+O(N^2)
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