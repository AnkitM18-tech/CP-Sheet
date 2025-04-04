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

vector<int> findNSE(vector<int>& arr) {
    int n = arr.size();

    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--) {
        int current = arr[i];

        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }
    return ans;
}

vector<int> findPSE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);

    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;

        st.push(i);
    }
    return ans;
}


int largestRectangleArea(vector<int> &heights) {
    /*
    // Brute - TC = O(3N) and SC = O(3N)
    vector<int> nse = findNSE(heights);
    vector<int> pse = findPSE(heights);

    int largestArea = 0;
    int currentArea = 0;

    for(int i = 0; i < heights.size(); i++) {
        currentArea = heights[i] * (nse[i] - pse[i] - 1);
        largestArea = max(largestArea, currentArea);
    }
    return largestArea;
    */
    // Optimal - SC = O(N) and TC = O(2N)
    int n = heights.size();

    stack<int> st;
    int largestArea = 0, area = 0;
    int nse,pse;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && heights[st.top()] >= heights[i]) {
            int ind = st.top();
            st.pop();

            pse = st.empty() ? -1 : st.top();
            nse = i;
            area = heights[ind] * (nse-pse-1);

            largestArea = max(largestArea, area);
        }
        st.push(i);
    }

    // Still there are elements
    while(!st.empty()) {
        nse = n;
        int ind = st.top();
        st.pop();
        pse = st.empty() ? -1 : st.top();

        area = heights[ind] * (nse-pse-1);
        largestArea = max(largestArea,area);
    }

    return largestArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> prefixSum(n,vector<int>(m));

    // Fill up the prefix sum matrix column wise
    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum += matrix[i][j];
            
            // If there is no base present
            if(matrix[i][j] == 0) {
                prefixSum[i][j] = 0;
                sum = 0;
            }
            // Store the height
            prefixSum[i][j] = sum;
        }
    }

    int maxArea = 0;

    for(int i = 0; i<n; i++) {
        int area = largestRectangleArea(prefixSum[i]);
        maxArea = max(area, maxArea);
    }

    return maxArea; // O(N*M) + O(2M * N) - TC, SC - O(N*M) + O(N)
}

vector<int> findPGE(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i<n; i++) {
        while(!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();
        }

        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();

        st.push(i);
    }
    return ans;
}

vector <int> stockSpan(vector<int> arr, int n) {
    /*
    // Brute = TC = O(N^2)
    vector<int> ans(n);

    for(int i = 0; i<n; i++) {
        int currentSpan = 0;

        for(int j = i; j >= 0; j--) {
            if(arr[j] <= arr[i]) {
                currentSpan++;
            } else break;
        }

        ans[i] = currentSpan;
    }
    return ans;
    */
    // Optimal - O(2N), SC - O(N)
    vector<int> PGE = findPGE(arr);
    vector<int> ans(n);

    for(int i = 0; i<n; i++) {
        ans[i] = i - PGE[i];
    }
    return ans;
}

int celebrity(vector<vector<int>> &M){
    /*
    // Brute - TC = O(N^2) + O(N) and SC = O(2N)
    int n = M.size();

    vector<int> knowMe(n,0);
    vector<int> iKnow(n,0);

    for(int i = 0; i<n; i++) {
        for(int j = 0; j<n; j++) {
            // if person i knows j
            if(M[i][j] == 1) {
                knowMe[j]++;
                iKnow[i]++;
            }
        }
    }

    for(int i = 0; i<n; i++) {
        if(knowMe[i] == n-1 && iKnow[i] == 0) {
            return i;
        }
    }

    return -1;
    */
    // Optimal - TC = O(2N)
    // there can only be one celebrity, as every one else 
    // will know him
    int n = M.size();
    int top = 0, down = n-1;

    while(top < down) {
        // if top knows down, not celebrity
        if(M[top][down] == 1) {
            top += 1;
        } 
        // if down knows top, not celebrity
        else if(M[down][top] == 1) {
            down -= 1;
        } 
        // if both doesn't know each other, not celebrity
        else {
            top++;
            down--;
        }
    }

    if(top > down) return -1;
    
    for(int i = 0; i<n; i++) {
        // i == j, we skip, because diagnal is 0
        if(i == top) continue;

        // not a celebrity
        if(M[top][i] == 1 || M[i][top] == 0) {
            return -1;
        }
    }

    return top;
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