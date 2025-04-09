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

double median(vector<int> &arr1, vector<int> &arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    /*
    // Brute
    vector<int> merged;
    int i = 0, j = 0;
    while(i < n1 && j < n2) {
    if(arr1[i] < arr2[j]) merged.push_back(arr1[i++]);
    else merged.push_back(arr2[j++]);
    }
    while(i < n1) merged.push_back(arr1[i++]);
    while(j < n2) merged.push_back(arr2[j++]);

    int n = n1 + n2;
    if(n % 2 == 1) {
    return (double)merged[n/2];
    }

    double median = ((double)merged[n/2] + (double)merged[(n/2)-1]) / 2.0;
    return median; // SC & TC - O(N1+N2)
    
    // Better
    int n = n1 + n2;
    
    // median calculation
    int ind2 = n/2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1element = -1, ind2element = -1;

    int i = 0, j = 0;
    while(i < n1 && j < n2) {
    if(arr1[i] < arr2[j]) {
        if(cnt == ind1) ind1element = arr1[i];
        if(cnt == ind2) ind2element = arr1[i];
        cnt++;
        i++;
    } else {
        if(cnt == ind1) ind1element = arr2[j];
        if(ant == ind2) ind2element = arr2[j];
        cnt++;
        j++;
    }
    }

    while(i<n1) {
    if(cnt == ind1) ind1element = arr1[i];
    if(cnt == ind2) ind2element = arr1[i];
    cnt++;
    i++;
    }
    while(j<n2) {
    if(cnt == ind1) ind1element = arr2[j];
    if(cnt == ind2) ind2element = arr2[j];
    cnt++;
    j++;
    }

    if(n%2 == 1) {
    return (double)ind2element;
    }

    return (double)((double)(ind1element + ind2element))/2.0;
    // TC = O(N1+N2)
    */
    // Optimal
    if(n1 > n2) return median(arr2,arr1);
    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;

    int low = 0, high = n1;
    while(low <= high) {
    int mid1 = (low + high) >> 1;
    int mid2 = left - mid1;

    int l1 = (mid1 > 0) ? arr1[mid1 - 1] : INT_MIN;
    int r1 = (mid1 < n1) ? arr1[mid1] : INT_MAX;
    int l2 = (mid2 > 0) ? arr2[mid2 - 1] : INT_MIN;
    int r2 = (mid2 < n2) ? arr2[mid2] : INT_MAX;

    if(l1 <= r2 && l2 <= r1) {
        if(n % 2 == 1) return max(l1,l2);
        else return (max(l1,l2) + min(r1,r2)) / 2.0;
    } else if(l1 > r2) {
        high = mid1 - 1;
    } else {
        low = mid1 + 1;
    }
    }
    return 0;
    // O(log(min(N1,N2))), where N1 and N2 are the sizes of two given arrays. 
    // As, binary search is being applied on the range [0, min(N1, N2)]
}

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size();
    // Brute
    vector<int> howMany(n-1,0);

    for(int gasStations = 1; gasStations <= k; gasStations++) {
        double maxSection = -1; int maxInd = -1;

        for(int i = 0; i<n-1; i++) {
        double diff = arr[i+1] - arr[i];
        double sectionLength = diff / (howMany[i] + 1);

        if(sectionLength > maxSection) {
            maxSection = sectionLength;
            maxInd = i;
        }
        }

        howMany[maxInd]++;
    }

    double maxAns = -1;
    for(int i = 0; i<n-1; i++) {
        double diff = arr[i+1] - arr[i];
        double sectionLength = diff / (howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
    // O(k*N) + O(N), N is size of the given array, 
    // k is number of gas stations to be placed. O(k*N) to insert k gas stations 
    // between the existing stations with maximum distance. 
    // Another O(N) for finding the answer i.e. the maximum distance.
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