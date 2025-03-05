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
    // TC = SC - O(logN)
}

int binaryToDecimal(string binary) {
    int n = binary.size();
    int num = 0, val = 1;

    for(int i = n - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            num = num + val;
        }
        val = val * 2;
    }
    return num; // O(N)
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        string N;
        cin >> N;
        cout << binaryToDecimal(N);
    }
    return 0;
}