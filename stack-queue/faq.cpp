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