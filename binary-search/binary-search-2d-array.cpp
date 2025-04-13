#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while(low <= high) {
    int mid = (low + high);
    if(arr[mid] >= x) {
        ans = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> & mat) {
    int row = mat.size();
    int col = mat[0].size();
    int maxCnt = 0, index = -1;
    /*
    // Linear Search - O(N * M)
    for(int i = 0; i < row; i++) {
    int cnt = 0;
    for(int j = 0; j < col; j++) {
        cnt += mat[i][j];
    }
    if(cnt > maxCnt) {
        maxCnt = cnt;
        index = i;
    }
    }
    return index;
    */
    // Binary Search - O(N * log M)
    for(int i = 0; i < row; i++) {
    int cnt = col - lowerBound(mat[i], col, 1);
    if(cnt > maxCnt) {
        maxCnt = cnt;
        index = i;
    }
    }
    return index;
}

bool binarySearch(vector<int> &mat, int target) {
    int n = mat.size();
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(mat[mid] == target) return true;
        else if(mat[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &mat, int target){
    int row = mat.size(), col = mat[0].size();
    if(row == 0 || col == 0) {
        return false;
    }
    /*
    // Brute - O(N * M)

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            if(mat[i][j] == target) {
                return true;
            }
        }
    }

    return false;
    
    // Better - O(N + log(M))
    for(int i = 0; i<row; i++) {
        // Check if there is a possibility that
        // the target can be found in current row
        if(mat[i][0] <= target && target <= mat[i][col-1]) {
            return binarySearch(mat[i], target);
        }
    }
    return false;
    */
    // Optimal - O(log(N*M))
    int low = 0, high = row * col - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        // row and col calculation
        int m = mid / col;
        int n = mid % col;

        if(mat[m][n] == target) return true;
        else if(mat[m][n] < target) low = mid + 1;
        else high = mid - 1;
    }
    return false;
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