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

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    /*
    set<vector<int>> st;
    // Brute
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            for(int k = j+1; k<n; k++) {
                for(int l = k+1; l<n; l++) {
                    if(nums[i] + nums[j] + nums[k] + nums[l] == target) {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> quad(st.begin(),st.end());
    return quad; // TC -  O(N^4), SC - O(2 x no. of the quadruplets)
    
    // Better
    for(int i = 0; i<n; i++) {
        for(int j = i+1; j<n; j++) {
            set<long long> hashset;
            for(int k = j+1;k<n; k++) {
                long long sum = nums[i] + nums[j] + nums[k];
                long long fourth = target - sum;

                if(hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {nums[i],nums[j],nums[k],fourth};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> quad(st.begin(),st.end());
    return quad; // TC - O(N^3xlog(M)), SC - O(2 x no. of the quadruplets)+O(N)
    */
    // Optimal
    vector<vector<int>> quad;
    sort(nums.begin(),nums.end());

    for(int i = 0; i<n; i++) {
        if(i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        for(int j = i+1; j<n; j++) {
            if(j > i + 1 && nums[j] == nums[j-1]) continue;

            int left = j + 1, right = n - 1;

            while(left < right) {
                long long sum = nums[i] + nums[j] + nums[left] + nums[right];
                if(sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[left], nums[right]};
                    quad.push_back(temp);
                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left-1]) left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                } else if(sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
    }
    return quad;
    // TC - O(N^3), SC - O(no. of quadruplets)
}

void sortZeroOneTwo(vector<int>& nums) {
    /*
    // Brute
    sort(nums.begin(),nums.end());
    // TC - O(N*logN), SC - O(1)
    
    // Better
    int n = nums.size();
    int cntZero = 0, cntOne = 0, cntTwo = 0;
    for(int i = 0; i<n; i++) {
        if(nums[i] == 0) cntZero++;
        else if(nums[i] == 1) cntOne++;
        else cntTwo++;
    }
    for(int i = 0; i<cntZero; i++) {
        nums[i] = 0;
    }
    for(int i = cntZero; i<cntZero + cntOne; i++) {
        nums[i] = 1;
    }
    for(int i = cntZero + cntOne; i<n; i++) {
        nums[i] = 2;
    } // TC = O(N)+O(N) = O(2N)
    */
    // Optimal - Dutch National Flag ALgorithm
    int low = 0, mid = 0, high = nums.size()-1;
    while(mid <= high) {
        if(nums[mid] == 0) {
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        } else if(nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid],nums[high]);
            high--;
        }
    } // TC - O(N)
    // Index 0 to low - 1 contains 0
    // Index low to mid - 1 contains 1
    // Index high +1 to sizeOfArray - 1 contains 2.
}

int maxSubArray(vector<int>& nums) {
    int n = nums.size();
    int maxi = INT_MIN;
    /*
    // Brute
    for(int i = 0; i < n; i++) {
        for(int j = i; j<n;j++) {
            int sum = 0;
            for(int k = i; k<=j; k++) {
                sum += nums[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi; // O(N^3)
    
    // Better
    for(int i = 0; i<n; i++) {
        int sum = 0;
        for(int j = i; j<n; j++) {
            sum += nums[j];
            maxi = max(maxi,sum);
        }
    }
    return maxi; // O(N^2)
    */
    // Optimal
    int sum = 0;
    for(int i = 0; i<n; i++) {
        sum += nums[i];
        if(sum > maxi) {
            maxi = sum;
        }
        if(sum < 0) sum = 0;
    }
    return maxi;
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