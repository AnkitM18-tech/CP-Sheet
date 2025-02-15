#include<bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>& a, int num) {
    for(int i = 0; i<a.size(); i++) {
        if(a[i] == num) {
            return true;
        }
    }
    return false;
}

int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) {
        return 0;
    }
    /*
    // Brute
    int longest = 1;
    for(int i = 0; i<n; i++) {
        int x = nums[i];
        int cnt = 1;
        while(linearSearch(nums,x+1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(cnt,longest);
    }
    return longest; // O(N^2)
    
    // Better
    sort(nums.begin(),nums.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0; i<n; i++) {
        if(lastSmaller == nums[i] - 1) {
            cnt += 1;
            lastSmaller = nums[i];
        } else if(nums[i] != lastSmaller) {
            cnt = 1;
            lastSmaller = nums[i];
        }
        longest = max(cnt,longest);
    }
    return longest; //  O(NlogN) + O(N)
    */
   // Optimal
    int longest = 1;
    unordered_set<int> st;

    for(int i = 0; i<n; i++) {
        st.insert(nums[i]);
    }
    
    for(auto it : st) {
        if(st.find(it - 1) == st.end()) {
            int cnt = 1;
            int x = it;

            while(st.find(x+1) != st.end()) {
                x += 1;
                cnt += 1;
            }

            longest = max(longest,cnt);
        }
    }
    return longest; // O(N) + O(2xN) ~ O(3xN)
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