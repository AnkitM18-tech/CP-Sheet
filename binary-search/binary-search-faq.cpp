#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int> &nums,int dist, int cows) {
    int n = nums.size();
    // no of cows
    int cntCows = 1;
    // position of last placed cow
    int last = nums[0];

    for(int i = 1; i<n; i++) {
        if(nums[i] - last >= dist) {
            cntCows++;
            last = nums[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    /*
    // Linear Search
    int range = nums[n-1] - nums[0];
    for(int i = 1; i<=range; i++) {
        if(canWePlace(nums,i,k) == false) {
            return (i-1);
        }
    }
    return range;
    // O(NlogN) + O(N *(max-min)), where N is size of the array, 
    // max is the maximum element in array, min is the minimum element in array.
    */
    // Optimal
    int low = 1, high = nums[n-1] - nums[0];
    while(low <= high) {
        int mid = (low + high)/2;
        if(canWePlace(nums,mid,k) == true) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
    // O(NlogN) + O(N *log(max-min)), where N is size of the array, 
    // max is the maximum element in array, min is the minimum element in array.
}

int countStudents(vector<int> &nums, int pages) {
    int n = nums.size();

    int students = 1;
    int pagesStudent = 0;

    for(int i=0; i<n; i++) {
        if(pagesStudent + nums[i] <= pages) {
            pagesStudent += nums[i];
        } else {
            students++;
            pagesStudent = nums[i];
        }
    }
    return students;
}

int findPages(vector<int> &nums, int m)  {
    int n = nums.size();

    if(m > n) return -1;

    int start = *max_element(nums.begin(),nums.end());
    int end = accumulate(nums.begin(),nums.end(),0);
    /* 
    // Linear Search
    for(int pages = start; pages <= end; pages++) {
        if(countStudents(nums,pages) == m) {
            return pages;
        }
    }
    return start;
    // O(N * (sum-max)), where N is size of the array, 
    // sum is the sum of all array elements, 
    // max is the maximum of all array elements.
    */
    while(start <= end) {
        int mid = (start + end)/2;
        int students = countStudents(nums,mid);
        if(students > m) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
    // O(N * log(sum-max)), where N is size of the array, 
    // sum is the sum of all array elements, 
    // max is the maximum of all array elements.
}

int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    /*
    // Linear Search
    for(int i = 0; i<n; i++) {
    if((i == 0 || arr[i-1] < arr[i]) && (i == n - 1 || arr[i] > arr[i+1])) {
        return i;
    }
    }
    return -1; // O( N)
    */
    // Binary Search
    // Edge Cases
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1, high = n - 2;
    while(low <= high) {
    int mid = (low + high)/2;
    if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) {
        return mid;
    }
    if(arr[mid] > arr[mid-1]) low = mid + 1;
    else high = mid - 1;
    }
    return -1; // O(logN)
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