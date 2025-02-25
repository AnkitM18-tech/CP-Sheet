#include<bits/stdc++.h>
using namespace std;

long long floorSqrt(long long n)  {
    /*
    // Linear
    long long ans = 0;
    for(long long i = 1; i<=n; i++) {
    long long sq = i * i;
    if(sq <= n * 1ll) {
        ans = i;
    } else {
        break;
    }
    }
    return ans; // O(N ^ 1/2)
    */
    long long low = 1, high = n;
    while(low <= high) {
    long long mid = (low + high)/2;
    long long sq = mid * mid;
    if(sq <= n * 1ll) {
        low = mid + 1;
    } else {
        high = mid - 1;
    }
    }
    return high; // O(log N)
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