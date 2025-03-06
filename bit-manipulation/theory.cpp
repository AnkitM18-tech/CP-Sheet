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

void swapNumbers(int &a, int &b) {
    a = a ^ b; // 5 ^ 6
    b = a ^ b; // (5 ^ 6) ^ 6
    a = a ^ b; // (5 ^ 6) ^ 5
    // TC - O(1) - SC
}

bool isBitSet(int n, int i) {
    return (n & (1 << i)) != 0 | ((n >> 1) & 1 == 0);
}

bool setBit(int n, int i) {
    return (n | (1 << i));
}

int clearBit(int n, int i) {
    return (n & ~(1 << i));
}

int toggleBit(int n, int i) {
    return (n ^ (1 << i));
}

int removeLastSetBit(int n) {
    return n & (n-1);
}

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n-1)) == 0);
}

int countSetBits(int n) {
    int cnt = 0;
    /*
    // O(log N)
    while(n > 0) {
        cnt += (n & 1);
        n >>= 1;
    }
    */
   //  O(K) Where K is the number of set bits.
    while (n) {
        n &= (n - 1);
        cnt++;
    }
    return cnt;
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