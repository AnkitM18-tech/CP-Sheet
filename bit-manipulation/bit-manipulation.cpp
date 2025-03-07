#include<bits/stdc++.h>
using namespace std;

int minBitsFlip(int start, int goal) { 
    int num = start ^ goal;

    int cnt = 0;
    while(num) {
        cnt += (num & 1);
        num >>= 1;
    }
    return cnt; // O(1)
}

int singleNumber(vector<int>& nums){
    /*
    // Brute - O(N) - TC & SC
    unordered_map<int,int> mpp;

    for(int i = 0; i< nums.size(); i++) {
        mpp[nums[i]]++;
    }

    for(auto it: mpp) {
        if(it.second == 1) {
            return it.first;
        }
    }

    return -1;
    */
    // Optimal - TC - O(N), SC - O(1)
    int XOR = 0;

    for(int i = 0; i<nums.size(); i++) {
        XOR ^= nums[i];
    }

    return XOR;
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