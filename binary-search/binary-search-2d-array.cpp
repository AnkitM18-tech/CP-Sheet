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