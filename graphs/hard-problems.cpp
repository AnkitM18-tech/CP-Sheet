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

class ShortestPathinUndirectedGraphWithUnitDistance {
private:
    void bfs(int src, vector<int> adj[], vector<int>& dist) {
        dist[src] = 0;
        queue<int> q;

        q.push(src);

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto adjNode : adj[node]) {
                if(dist[node] + 1 < dist[adjNode]) {
                    dist[adjNode] = 1 + dist[node];
                    q.push(adjNode);
                }
            }
        }
    }

public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){
        vector<int> adj[N];

        for(auto it : edges) {
            int u = it[0];
            int v = it[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> dist(N, 1e9);

        bfs(0, adj, dist);

        for(int i = 0; i < N; i++) {
            if(dist[i] == 1e9) dist[i] = -1;
        }

        return dist;
    }
    // TC = SC = O(N + M)
};

class WordLadderI {
public:
    int wordLadderLength(string startWord, string targetWord,vector<string> &wordList) {
        // Queue data structure to store pair:
        // {"word", steps to reach "word"}
        queue<pair<string, int>> q;
        q.push({startWord, 1});

        unordered_set<string> st(wordList.begin(), wordList.end());
        // erase starting word from set if it exists
        st.erase(startWord);

        while(!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(word == targetWord) return steps;

            for(int i = 0; i < word.size(); i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;

                    if(st.find(word) != st.end()) {
                        st.erase(word);
                        q.push({word, steps + 1});
                    }
                }

                word[i] = original;
            }
        }

        return 0;
    }

    // TC = O(N * M * 26), SC = O(N)
};

class WordLadderII{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,vector<string> &wordList) {
        vector<vector<string>> ans;

        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // erase starting word from set if exists
        q.push({beginWord});

        st.erase(beginWord);

        // set to store the words that must be deleted after a level traversal
        unordered_set<string> toErase;

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                vector<string> seq = q.front();
                string word = seq.back();
                q.pop();

                if(word == endWord) {
                    if(ans.empty()) {
                        ans.push_back(seq);
                    } else if(ans.back().size() == seq.size()) {
                        ans.push_back(seq);
                    }
                }

                for(int pos = 0; pos < word.size(); pos++) {
                    char original = word[pos];

                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        word[pos] = ch;

                        if(st.find(word) != st.end()) {
                            seq.push_back(word);
                            q.push(seq);

                            toErase.insert(word);
                            
                            // backtrack step
                            seq.pop_back();
                        }
                    }

                    word[pos] = original;
                }
            }

            for(auto it : toErase) st.erase(it);
            toErase.clear();

            if(!ans.empty()) break;
        }

        return ans;
    }
};

class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u]) parent[ulp_v] = ulp_u;
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class NumberOfOperationsToMakeNetworkConnected {
public:
    int solve(int n, vector<vector<int>> &Edge){
        int size = Edge.size();

        if(size < n - 1) return -1;
        DisjointSet ds(n);

        for(int i = 0; i < size; i++) {
            ds.unionByRank(Edge[i][0], Edge[i][1]);
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) count++;
        }

        return count - 1;
    }
    // TC = O(N + M), SC = O(N)
};

class DisjointSet {
public:
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class AccountsMerge{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> accounts){
        int n = accounts.size();

        DisjointSet ds(n);

        unordered_map<string, int> mapMailNode;
        
        // Iterate on all the accounts
        for(int i = 0; i < n; i++) {
            // Iterate on all the mails of the person
            for(int j = 1; j < accounts[i].size(); j++) {
                string mail = accounts[i][j];

                if(mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                } else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];

        for(auto it : mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;

        for(int i = 0; i < n; i++) {
            if(mergedMail[i].size() == 0) continue;

            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]) {
                temp.push_back(it);
            }

            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    // TC = O(N + E) + O(E*4a) + O(N*(ElogE + E)) E = no of emails
    // SC = O(N + E)
    
};

class NumberOfIslandsII{
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};

    bool isValid(int& i, int& j, int& n, int& m) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= m) return false;

        return true;
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
        DisjointSet ds(n * m);

        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;

        vector<int> ans;

        for(auto it : A) {
            int row = it[0];
            int col = it[1];

            if(vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;

            for(int ind = 0; ind < 4; ind++) {
                int newRow = row + delRow[ind];
                int newCol = col + delCol[ind];

                if(isValid(newRow, newCol, n, m) && vis[newRow][newCol] == 1) {
                    int nodeNo = row * m + col;
                    int adjNodeNo = newRow * m + newCol;

                    if(ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }

    /*
    Time Complexity: O(K*4ɑ)
    Each operation involves converting the sea cell to land cell 
    and merging the nodes (if possible) taking an overall O(4ɑ) time.
    Since, there are a total of K operations, the overall time complexity is O(K*4ɑ).

    Space Complexity: O(K) + O(N*M)
    The result list takes O(K) space. The visited array takes O(N*M) 
    space and the Disjoint set uses parent and rank/size array storing all 
    N*M nodes taking O(N*M) space.
    */
};

class MakeTheLargestIsland {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};

    bool isValid(int& i, int& j, int& n) {
        if(i < 0 || i >= n) return false;
        if(j < 0 || j >= n) return false;

        return true;
    }

    void addInitialIslands(vector<vector<int>>& grid, DisjointSet& ds, int n) {
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;

                for(int ind = 0; ind < 4; ind++) {
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newRow * n + newCol;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        DisjointSet ds(n * n);
        addInitialIslands(grid, ds, n);

        int ans = 0;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;

                set<int> components;

                for(int ind = 0; ind < 4; ind++) {
                    int newRow = row + delRow[ind];
                    int newCol = col + delCol[ind];

                    if(isValid(newRow, newCol, n) && grid[newRow][newCol] == 1) {
                        int nodeNo = newRow * n + newCol;
                        components.insert(ds.findUPar(nodeNo));
                    }
                }

                int sizeTotal = 0;

                for(auto it : components) {
                    sizeTotal += ds.size[it];
                }

                ans = max(ans, sizeTotal + 1);
            }
        }
        
        // Edge case - all 1s
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans, ds.size[ds.findUPar(cellNo)]);
        }

        return ans;
    }

    /*
        Time Complexity: O(N^2) Using nested loops, and within the loops, 
        all the operations take constant time.

        Space Complexity: O(N^2) The Disjoint set storing N^2 nodes 
        (cells) will take up 2*N^2 space due to parent and size arrays.
    */
};

class MostStonesRemovedWithSameRowOrColumn {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0, maxCol = 0;

        for(auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        DisjointSet ds(maxRow + maxCol + 1);
        // To store the nodes having a stone in Disjoint Set
        unordered_map<int, int> stoneNodes;

        for(auto it : stones) {
            int nodeRow = it[0];
            // Converted column number
            int nodeCol = it[1] + maxRow + 1;

            ds.unionBySize(nodeRow, nodeCol);

            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // To store connected components
        int k = 0;

        for(auto it : stoneNodes) {
            if(ds.findUPar(it.first) == it.first) k++;
        }

        return n - k;
    }

    /*
    Time Complexity: O(N) The given stones array is traversed multiple times. 
    Traversing the hashset will also take O(N) time.

    Space Complexity: O(Max Row number + Max Column number) 
    The Disjoint set will store the nodes using the parent and size/rank array which 
    will take (2*number of nodes) space. 
    Since, the number of nodes = max row number + max column number, 
    the overall space complexity is O(Max Row number + Max Column number).
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