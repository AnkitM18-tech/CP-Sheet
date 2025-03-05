#include<bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string result = "";

    while(n != 0) {
        if(n % 2 == 1) result += '1';
        else result += '0';

        n = n / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        cout << decimalToBinary(N);
    }
    return 0;
}