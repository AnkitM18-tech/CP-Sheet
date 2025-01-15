#include<bits/stdc++.h>
using namespace std;

void pattern1(int num) {
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

void pattern2(int num) {
    
}
int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    cin >> n;
    pattern1(n);

    return 0;
}

