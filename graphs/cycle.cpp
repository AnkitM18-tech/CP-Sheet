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

class BipartiteGraph{
    private:
        bool bfs(int start, vector<int> adj[], vector<int>& color) {
            queue<int> q;
            // Add initial node to queue
            q.push(start);
    
            color[start] = 0;
    
            while(!q.empty()) {
                int node = q.front();
                q.pop();
    
                for(auto it : adj[node]) {
                    // If not already colored
                    if(color[it] == -1) {
                        // Color it with opposite color.
                        color[it] = !color[node];
                        q.push(it);
                    } else if(color[it] == color[node]) return false;
                }
            }
            return true;
        }
    
        bool dfs(int node, int col, vector<int> adj[], vector<int>& color) {
            color[node] = col;
    
            for(auto it : adj[node]) {
                if(color[it] == -1) {
                    if(!dfs(it, !col, adj, color)) return false;
                } else if(color[it] == col) return false;
            }
            return true;
        }
    public:
        bool isBipartite(int V, vector<int> adj[])  {
            vector<int> color(V, -1);
    
            for(int i = 0; i < V; i++) {
                // If not colored, start the traversal
                if(color[i] == -1) {
                    // Return false if graph is not bipartite
                    // if(!bfs(i, adj, color)) return false;
    
                    if(!dfs(i, 0, adj, color)) return false;
                }
            }
            /* Return true if each 
            component is bipartite */
            return true;
        }
        /*
        Time Complexity: O(V+E) (where V is the number of nodes and E is the number of edges in the graph)
        The BFS Traversal takes O(V+E) time.
    
        Space Complexity: O(V)
        The color array takes O(V) space and queue space for BFS is O(V) for the worst case.
        */
};

class TopologicalSort{
    private:
        void dfs(int node, vector<int> adj[], vector<int>& vis, stack<int>& st) {
            vis[node] = 1;
    
            for(auto it : adj[node]) {
                if(vis[it] == 0) dfs(it, adj, vis, st);
            }
    
            /* Add the current node to stack 
            once all the nodes connected to it 
            have been processed */
            st.push(node);
        }
    public:
        vector<int> topoSort(int V, vector<int> adj[]){
            vector<int> vis(V, 0);
            vector<int> ans;
            stack<int> st;
    
            for(int i = 0; i < V; i++) {
                if(!vis[i]) dfs(i, adj, vis, st);
            }
    
            while(!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
    
            return ans;
            /*
                // BFS - Kahn's Algorithm
    
                vector<int> inDegree(V, 0);
    
                for(int i = 0; i < V; i++) {
                    for(auto it : adj[i]) inDegree[it]++;
                }
    
                queue<int> q;
    
                for(int i = 0; i < V; i++) {
                    if(inDegree[i] == 0) q.push(i);
                }
    
                while(!q.empty()) {
                    int node = q.front();
                    ans.push_back(node);
                    q.pop();
    
                    for(auto it : adj[node]) {
                        inDegree[it]--;
                        if(inDegree[it] == 0) q.push(it);
                    }
                }
    
                return ans;
            */
        }
        /*
    
        Time Complexity: O(V+E) (where V and E represent the number of nodes and 
        edges in the graph)
        A simple DFS traversal takes O(V+E) time.
    
        Space Complexity: O(V)
        The stack will store at most V nodes taking O(V) space and the array to 
        store the topological sort takes O(V) space.
        
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