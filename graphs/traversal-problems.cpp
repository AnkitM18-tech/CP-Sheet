#include<bits/stdc++.h>
using namespace std;

class NumberOfProvince {
private:
    void bfs(int node, vector<int> adjList[], int vis[]) {
    vis[node] = 1;
    queue<int> q;
    q.push(node);

    while(!q.empty()) {
        int i = q.front();
        q.pop();

        for(auto it: adjList[i]) {
        if(!vis[it]) {
            vis[it] = 1;
            q.push(it);
        }
        }
    }
    }

    void dfs(int node, vector<int> adjList[], int vis[]) {
    vis[node] = 1;

    for(auto it: adjList[node]) {
        if(!vis[it]) {
        dfs(it, adjList, vis);
        }
    }
    }
public:
    int numProvinces(vector<vector<int>> adj) {
        int V = adj.size();
        vector<int> adjList[V];

        // Convert adjacency matrix to adjacency list
        for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(adj[i][j] == 1 && i != j) {
            adjList[i].push_back(j);
            adjList[j].push_back(i);
            }
        }
        }

        int vis[V] = {0};

        int cnt = 0;

        for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            cnt++;

            bfs(i,adjList, vis);
            // dfs(i, adjList, vis);
        }
        }

        return cnt;
    }
    // TC = O(V^2) + O(V + E), SC = O(V + E)
};

class NumberOfIslands{
private:
    /* Function to determine if the cell
        is valid (within grid's boundaries) */
    bool isValid(int i, int j, int n, int m) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;

        return true;
    }

    void bfs(int i ,int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        vis[i][j] = true;

        queue<pair<int, int>> q;

        q.push({i,j});

        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()) {
            pair<int,int> cell = q.front();
            q.pop();

            int row = cell.first;
            int col = cell.second;

            for(int delRow = -1; delRow <= 1; delRow++) {
                for(int delCol = -1; delCol <= 1; delCol++) {
                    int newRow = row + delRow;
                    int newCol = col + delCol;

                    if(isValid(newRow, newCol,n,m) && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = true;
                        q.push({newRow, newCol});
                    }
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == '1') {
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;

        // TC = O(N * M)
        /*
        Running a nested loop to traverse every cell of grid takes O(N*M) time.
        In total, the traversal will be performed on grids taking overall at 
        most of O(9*N*M) time.

        SC = O(N*M)
        */
    }
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