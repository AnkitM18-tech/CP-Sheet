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

bool searchMatrix(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();
    /*
    // Better - O(N * log(M))
    for(int i = 0; i < n; i++) {
        bool flag = binarySearch(matrix[i], target);

        if(flag) return true;
    }
    return false;
    */
    // Optimal - O(N + M)
    int row = 0, col = m - 1;
    while(row < n && col >= 0) {
        if(matrix[row][col] == target) return true;
        else if(matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int maxElement(vector<vector<int>> &arr, int col) {
    int n = arr.size();
    int maxi = INT_MIN;
    int index = -1;

    for(int i = 0; i < n; i++) {
        if(arr[i][col] > maxi) {
            maxi = arr[i][col];
            index = i;
        }
    }
    return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0, high = m - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        int row = maxElement(mat,mid);

        int left = mid - 1 >= 0 ? mat[row][mid-1] : INT_MIN;
        int right = mid + 1 < m ? mat[row][mid+1] : INT_MIN;

        if(mat[row][mid] > left && mat[row][mid] > right) {
            return {row,mid};
        } else if(left > mat[row][mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return {-1,-1};
    // O(N * log M)
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