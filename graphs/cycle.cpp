#include<bits/stdc++.h>
using namespace std;

class DetectCycleInUndirectedGraph{
private:
    bool bfs(int i, vector<int> adj[], vector<int>& vis) {
        queue<pair<int,int>> q;

        q.push({i, -1});

        vis[i] = 1;

        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for(auto it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;

                    q.push({it, node});
                } else if(it != parent) return true;
            }
        }
        return false;
    }

    bool dfs(int i, vector<int> adj[], vector<int>& vis, int previous) {
        vis[i] = 1;

        for(auto it : adj[i]) {
            if(!vis[it]) {
                if(dfs(it, adj, vis, i)) return true;
            } else if(it != previous) return true;
        }

        return false;
    }
public:
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);

        bool ans = false;

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                ans = bfs(i, adj, vis);

                if(ans) break;
            }
        }
        return ans;
        /*
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        
        return false;
        */
    }
    /*
        Time Complexity: O(V + E)
        (where V is the number of nodes and E is the number of edges in the graph)
        Traversing the complete graph overall which taken O(V+E) time.

        Space Complexity: O(V)
        Visited array takes O(V) space and in the worst case queue will store all 
        nodes taking O(V) space.
    */
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