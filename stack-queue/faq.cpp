#include<bits/stdc++.h>
using namespace std;

class MinStackBrute {
private:
    // pair stores the val and the minimum val till time
    stack<pair<int,int>> st;
public:
    MinStackBrute() {
    }

    void push(int value) {
        if(st.empty()) {
            st.push({value,value});
            return;
        }
        int mini = min(getMin(),value);
        st.push({value,mini});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
    // TC - O(1) and SC - O(2N)
};

class MinStackOptimal {
private:
    stack<int> st;
    int mini = INT_MAX;
public:
    MinStackOptimal() {
    }

    void push(int value) {
        if(st.empty()) {
            mini = value;
            st.push(value);
            return;
        }
        if(value > mini) {
            st.push(value);
        } else {
            st.push(2 * value - mini);
            mini = value;
        }
    }

    void pop() {
        if(st.empty()) return;

        int x = st.top();
        st.pop();
        if(x < mini) {
            mini = 2 * mini - x;
        }
    }

    int top() {
        if(st.empty()) return -1;

        int x = st.top();

        if(mini < x) return x;

        return mini;
    }

    int getMin() {
        return mini;
    }
    // O(1) - TC and SC = O(N)
};

vector<int> maxSlidingWindow(vector<int> &arr, int k) {
    /*
    // Brute - TC = O((N-K)*K) and SC = O(N-K)
    int n = arr.size();
    vector<int> ans;

    for(int i = 0; i <= n-k; i++) {
        maxi = arr[i];
        for(int j = i; j < i+k; j++) {
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
    */
    // Optimal - TC = O(2N) and SC = O(N-K) + O(K)
    int n = arr.size();

    vector<int> ans;
    deque<int> dq;

    for(int i = 0; i < n; i++) {
        if(!dq.empty() && dq.front() <= (i-k)) {
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= (k-1)) {
            ans.push_back(arr[dq.front()]);
        }
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