#include<bits/stdc++.h>
using namespace std;

double power(double x, int n) {
    if(n == 0) return 1.0;
    if(n == 1) return x;

    if(n % 2 == 0) {
        return power(x*x, n/2);
    }
    return x * power(x,n-1);
}

double myPow(double x, int n) {
    /*
    // Brute
    if(n == 0) return 1.0;
    if(n < 0) {
    x = 1/x;
    n = -n;
    }
    double ans = 1;
    for(int i = 0; i<n; i++) {
    ans *= x;
    }
    return ans; // O(n)
    */
    // Optimal
    // -1 * INT_MIN - exceeds the positive int boundary
    int num = n;

    if(num < 0) {
    return (1.0 / power(x, -1 * num));
    }
    return power(x,n); // O(log N)
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