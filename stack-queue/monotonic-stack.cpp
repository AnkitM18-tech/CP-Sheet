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

vector<int> nextGreaterElements(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n,-1);

    /*
    // Brute - O(N^2) - TC, SC - O(N)
    for(int i = 0; i<n; i++) {
        int ele = arr[i];
        for(int j = i+1; j<i+n; j++) {
            int ind = j % n;

            if(arr[ind] > ele) {
                ans[i] = arr[ind];
                break;
            }
        }
    }
    return ans;
    */
    // Optimal - O(N)
    stack<int> st;

    for(int i = 2*n - 1; i>=0; i--) {
        int ind = i % n;
        int ele = arr[ind];

        while(!st.empty() && st.top() <= ele) {
            st.pop();
        }

        if(i < n) {
            if(st.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = st.top();
            }
        }

        st.push(ele);
    }
    return ans;
}

vector<int> asteroidCollision(vector<int> &asteroids){
    int n = asteroids.size();

    // List implementation of stack
    vector<int> st;

    for(int i = 0; i<n; i++) {
    if(asteroids[i] > 0) {
        st.push_back(asteroids[i]);
    } else {
        while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
            st.pop_back();
        }

        if(!st.empty() && st.back() == abs(asteroids[i])) {
            st.pop_back();
        } else if(st.empty() || st.back() < 0) {
            st.push_back(asteroids[i]);
        }
    }
    }
    return st;
    // TC , SC = O(N)
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