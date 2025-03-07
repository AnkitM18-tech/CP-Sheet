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