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