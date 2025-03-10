#include<bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    /*
    // Brute - O(N^2)
    for(int i = 0; i<n; i++) {
        int num = arr[i];
        for(int j = i+1; j<n; j++) {
            if(arr[j] > num) {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;
    */
    // Optimal - O(N) - TC & SC
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        int ele = arr[i];
        while (!st.empty() && st.top() <= ele) {
            st.pop();
        }

        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(ele);
    }

    return ans;
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