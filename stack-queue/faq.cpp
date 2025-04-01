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

vector<int> findPrefixMax(vector<int> &height, int n) {
    vector<int> prefixMax(n);

    prefixMax[0] = height[0];

    for(int i = 1; i < n; i++) {
        prefixMax[i] = max(prefixMax[i-1], height[i]);
    }

    return prefixMax;
}

vector<int> findSuffixMax(vector<int> &height, int n) {
    vector<int> suffixMax(n);

    suffixMax[n-1] = height[n-1];

    for(int i = n-2; i >= 0; i--) {
        suffixMax[i] = max(suffixMax[i+1],height[i]);
    }

    return suffixMax;
}

int trap(vector<int> &height){
    /*
    // Brute - O(3N) = TC and SC = O(2N)
    int n = height.size();
    int total = 0;

    vector<int> leftMax = findPrefixMax(height,n);
    vector<int> rightMax = findSuffixMax(height,n);

    for(int i = 0; i < n; i++) {
        if(height[i] < leftMax[i] && height[i] < rightMax[i]) {
            total += min(leftMax[i], rightMax[i]) - height[i];
        }
    }
    return total;
    */
    // Optimal - O(N) and SC = O(1)
    int n = height.size();
    int leftMax = 0, rightMax = 0, total = 0;
    int left = 0, right = n-1;

    while(left < right) {
        if(height[left] <= height[right]) {
            if(leftMax > height[left]) {
                total += leftMax - height[left];
            } else {
                leftMax = height[left];
            }
            left++;
        } else {
            if(rightMax > height[right]) {
                total += rightMax - height[right];
            } else {
                rightMax = height[right];
            }
            right--;
        }
    }
    return total;
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