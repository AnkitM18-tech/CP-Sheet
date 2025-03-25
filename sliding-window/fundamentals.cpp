#include<bits/stdc++.h>
using namespace std;

void slidingWindowSum(const vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0;

    // Calculate the sum of the initial window
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
    }

    // Print the sum of the first window
    cout << "Sum of window 1: " << sum << endl;

    // Slide the window across the array
    for (int i = k; i < n; ++i) {
        sum = sum - arr[i - k] + arr[i]; // Update the sum
        cout << "Sum of window " << i - k + 2 << ": " << sum << endl;
    }
}

// Function to find the longest subarray with sum <= K
int longestSubarrayWithSum(vector<int>& arr, int K) {
    int n = arr.size();
    int maxLength = 0; // Initialize the maximum length to 0
    int sum = 0;       // Initialize the current sum to 0
    int left = 0;      // Left pointer for the sliding window

    // Iterate over the array using the right pointer
    for (int right = 0; right < n; right++) {
        sum += arr[right]; // Add the current element to the sum

        // Shrink the window from the left if sum exceeds K
        // if replaces while - TC = O(N) instead of O(N)
        while (sum > K) {
            sum -= arr[left]; // Subtract the leftmost element from the sum
            left++;           // Move the left pointer to the right
        }

        // Update the maximum length if the current window is valid
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength; // Return the maximum length of the valid subarray
}

// Helper function to find the number of subarrays with at most sum S
int atMost(vector<int>& A, int S) {
    if (S < 0) return 0;
    int res = 0, i = 0;

    // Sliding window approach to count subarrays
    for (int j = 0; j < A.size(); j++) {
    // Include A[j] in the current window  
        S -= A[j];  
        while (S < 0) {
        // Shrink the window if the sum exceeds S
            S += A[i++];  
        }
        // Count all subarrays ending at j
        res += j - i + 1; 
    }

    return res;
}

int numSubarraysWithSum(vector<int>& A, int S) {
        return atMost(A, S) - atMost(A, S - 1);
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