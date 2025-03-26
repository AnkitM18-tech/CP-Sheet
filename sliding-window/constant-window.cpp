#include<bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardScore , int k){
    int lSum = 0, rSum = 0, maxSum = 0;

    for(int i = 0; i < k; i++) {
        lSum += cardScore[i];
        maxSum = lSum;
    }

    int right = cardScore.size() - 1;

    for(int i = k-1; i >= 0; i--) {
        lSum -= cardScore[i];
        rSum += cardScore[right];
        right--;
        maxSum = max(maxSum, lSum + rSum);
    }

    return maxSum; // O(2*k)
}

int longestNonRepeatingSubstring(string& s){
    /*
    // Brute - TC = O(N^2), SC = O(256)
    int n = s.size();

    int maxLen = 0;

    for(int i = 0; i<n; i++) {

        vector<int>hash(256,0);

        for(int j = i; j<n; j++) {
        if(hash[s[j]] == 1) break;

        hash[s[j]] = 1;

        int len = j - i + 1;
        maxLen = max(maxLen,len);
        }
    }
    return maxLen;
    */
    // Optimal
    int n = s.size();
    int HASHLENGTH = 256;
    int hash[HASHLENGTH];

    for(int i = 0; i<HASHLENGTH; i++) {
    hash[i] = -1;
    }

    int l = 0, r = 0, maxLen = 0;

    while(r<n) {
    if(hash[s[r]] != -1) {
        if(hash[s[r]] >= l) l = max(hash[s[r]] + 1, l);
    }

    int len = r - l + 1;
    maxLen = max(maxLen,len);

    hash[s[r]] = r;
    r++;
    }

    return maxLen; // O(N)
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