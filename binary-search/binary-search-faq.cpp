#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &nums,int dist, int cows) {
    int n = nums.size();
    // no of cows
    int cntCows = 1;
    // position of last placed cow
    int last = nums[0];

    for(int i = 1; i<n; i++) {
        if(nums[i] - last >= dist) {
            cntCows++;
            last = nums[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    /*
    // Linear Search
    int range = nums[n-1] - nums[0];
    for(int i = 1; i<=range; i++) {
        if(canWePlace(nums,i,k) == false) {
            return (i-1);
        }
    }
    return range;
    // O(NlogN) + O(N *(max-min)), where N is size of the array, 
    // max is the maximum element in array, min is the minimum element in array.
    */
    // Optimal
    int low = 1, high = nums[n-1] - nums[0];
    while(low <= high) {
        int mid = (low + high)/2;
        if(canWePlace(nums,mid,k) == true) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
    // O(NlogN) + O(N *log(max-min)), where N is size of the array, 
    // max is the maximum element in array, min is the minimum element in array.
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