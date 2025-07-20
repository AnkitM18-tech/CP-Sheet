#include<bits/stdc++.h>
using namespace std;

class EventualSafeStates {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                inDegree[it]++;
            }
        }

        vector<int> ans;
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
    }

    bool dfsCheck(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(dfsCheck(it, adj, vis, pathVis, check)) {
                    return true;
                }
            } else if(pathVis[it]) {
                return true;
            }
        }

        check[node] = 1;
        pathVis[node] = 0;

        return false;
    }
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]){
        /*
        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);
        vector<int> check(V, 0);

        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }

        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(check[i] == 1) ans.push_back(i);
        }

        return ans;
        */
        vector<int> adjRev[V];
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                adjRev[it].push_back(i);
            }
        }

        vector<int> result = topoSort(V, adjRev);
        sort(result.begin(), result.end());
        return result;
    }
    // DFS - TC = O (V + E), SC = O(V)
    // BFS - TC = O(V + E) + O(V * log V), SC = O(V + E)
};

class CourseScheduleI {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                inDegree[it]++;
            }
        }

        vector<int> ans;
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
    }

public:
    bool canFinish(int N, vector<vector<int>> arr) {
        vector<int> adj[N];

        for(auto it: arr) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> topo = topoSort(N, adj);

        if(topo.size() < N) return false;

        return true;
    }
    // TC = SC = O(V + E)
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