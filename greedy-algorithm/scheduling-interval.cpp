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