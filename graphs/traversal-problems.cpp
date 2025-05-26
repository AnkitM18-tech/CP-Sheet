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