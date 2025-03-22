#include<bits/stdc++.h>
using namespace std;

long long solve(vector<int>& bt) {
    sort(bt.begin(), bt.end());

    long long waitTime = 0;
    long long total = 0;

    int n = bt.size();

    for(int i = 0; i<n; i++) {
        waitTime += total;
        total += bt[i];
    }

    return waitTime/n; // O(N log N + N)
}

vector<int> JobScheduling(vector<vector<int>>& Jobs) {
    // sort jobs based on profit in desc order
    sort(Jobs.begin(), Jobs.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    int n = Jobs.size();
    int maxDeadline = -1;
    for(int i = 0; i<n; i++) maxDeadline = max(maxDeadline, Jobs[i][1]);
    vector<int> hash(maxDeadline,-1);

    int cnt = 0, totalProfit = 0;

    for(int i = 0; i<n; i++) {
        for(int j = Jobs[i][1] - 1; j>=0; j--) {
        if(hash[j] == -1) {
            cnt++;
            hash[j] = Jobs[i][0];
            totalProfit += Jobs[i][2];
            break;
        }
        }
    }

    return {cnt,totalProfit}; // O(N log N + N^2) - TC, SC - O(maxDeadline)
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