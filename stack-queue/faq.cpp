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