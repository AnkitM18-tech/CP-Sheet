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

class CourseScheduleII {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
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
    vector<int> findOrder(int N, vector<vector<int>> arr) {
        vector<int> adj[N];
        for(auto it : arr) {
            int u = it[0], v = it[1];

            adj[v].push_back(u);
        }

        vector<int> topo = topoSort(N, adj);
        if(topo.size() < N) return {};

        return topo;
    }
};

class AlienDictionary {
private:
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> inDegree(V, 0);

        for(int i = 0 ; i < V; i++) {
            for(auto it : adj[i]) {
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
	string findOrder(string dict[], int N, int K) {
		vector<int> adj[K];

        for(int i = 0; i < N - 1; i++) {
            string s1 = dict[i];
            string s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for(int ptr = 0; ptr < len; ptr++) {
                if(s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> topo = topoSort(K, adj);
        string ans;

        // for(int i = 0; i < K; i++) {
        //     ans.push_back('a' + topo[i]);
        //     ans.push_back(' ');
        // }
        for(auto it : topo) {
            ans.push_back('a' + it);
            ans.push_back(' ');
        }

        return ans;
	}
    // TC = O(K + N), SC = O(K + N)
    /*
    Follow-up question for interview:

    When is the ordering of letters not possible:
        If every character matches and the largest word appears before the 
        shortest word: For example, if “abcd” appears before “abc”, 
        we can say the ordering is not possible.
    If there exists a cyclic dependency between the characters: 
        For example, in the dictionary: dict: {“abc”, “bat”, “ade”} 
        there exists a cyclic dependency between 'a' and 'b' 
        because the dictionary states 'a' < 'b' < 'a', which is not possible.
    */
};

class ShortestPathInDAG {
private:
    void topoSort(int node, vector<pair<int, int>> adj[], 
    vector<bool>& vis, stack<int>& st) {
        vis[node] = 1;

        for(auto it : adj[node]) {
            int v = it.first;

            if(!vis[v]) {
                topoSort(v, adj, vis, st);
            }
        }

        /* Add the current node to stack 
        once all the nodes connected to it 
        have been processed */
        st.push(node);
    }

public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];

        for(int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj[u].push_back({v, wt});
        }

        vector<bool> vis(N, false);
        stack<int> st;

        for(int i = 0; i < N; i++) {
            if(!vis[i]) {
                topoSort(i, adj, vis, st);
            }
        }

        vector<int> dist(N, 1e9);
        // Distance of source node to itself is zero
        dist[0] = 0;

        while(!st.empty()) {
            int node = st.top();
            st.pop();

            for(auto it : adj[node]) {
                int v = it.first, wt = it.second;

                if(dist[node] + wt < dist[v]) {
                    dist[v] = wt + dist[node];
                }
            }
        }

        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
    // TC = SC = O(N + M)
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