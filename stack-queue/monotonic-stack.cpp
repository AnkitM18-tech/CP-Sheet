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

vector<int> findNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--) {
        int ele = arr[i];

        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;

        st.push(i);
    }

    return ans;
}

vector<int> findPSEE(vector<int>& arr) {
    int n = arr.size();

    vector<int> ans(n);

    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }
    return ans;
}
int sumSubarrayMins(vector<int> &arr) {
    int n = arr.size();
    int sum = 0, mod = (1e9 + 7);
    /*
    // Brute - O(N^2)
    for(int i = 0; i<n; i++) {
        int mini = arr[i];
        for(int j = i; j<n; j++) {
            mini = min(arr[j],mini);
            sum = (sum + mini) % mod;
        }
    }
    */
    // Optimal - SC, TC - O(N)
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);

    for(int i = 0; i<n; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;

        int val = (freq * arr[i] * 1LL) % mod;

        sum = (sum + val) % mod;
    }
    return sum;
}

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;

        st.push(i);
    }
    return ans;
}

vector<int> findPSEE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] > arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }
    return ans;
}

vector<int> findNGE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}

vector<int> findPGEE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }
    return ans;
}

long long sumSubArrayMins(vector<int> &arr) {
    vector<int> nse = findNSE(arr);
    vector<int> psee = findPSEE(arr);
    int n = arr.size();
    long long sum = 0;

    for(int i = 0; i<n; i++) {
        int left = i - psee[i];
        int right = nse[i] - i;
        long long freq = left * right * 1LL;
        long long val = (freq * arr[i] * 1LL);

        sum += val;
    }

    return sum;
}

long long sumSubarrayMaxs(vector<int> &arr) {
    vector<int> nge = findNGE(arr);
    vector<int> pgee = findPGEE(arr);
    int n = arr.size();
    long long sum = 0;

    for(int i = 0; i<n; i++) {
        int left = i - pgee[i];
        int right = nge[i] - i;
        long long freq = left * right * 1LL;
        long long val = (freq * arr[i] * 1LL);

        sum += val;
    }

    return sum;
}

long long subArrayRanges(vector<int> &nums) {
    
    /*
    // Brute = O(N^2)
    int n = nums.size();
    long long sum = 0;
    for(int i = 0; i<n; i++) {
    int smallest = arr[i], largest = arr[i];
    for(int j = i; j<n; j++) {
        smallest = min(smallest, arr[j]);
        largest = max(largest,arr[j]);
        sum += (largest - smallest);
    }
    }
    return sum;
    */
    // Optimal - O(N)
    return (sumSubarrayMaxs(nums) - sumSubArrayMins(nums));
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