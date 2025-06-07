#include<bits/stdc++.h>
using namespace std;

#define P pair<int,int>

class DijkstraAlgorithm{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        /*
        // Using Priority Queue
        priority_queue<P, vector<P>, greater<P>> pq;

        vector<int> dist(V, 1e9);

        dist[S] = 0;

        pq.push({0, S});

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                if(dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
        */
        // Using Set
        set<P> st;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        st.insert({0, S});

        while(!st.empty()) {
            int dis = st.begin()->first;
            int node = st.begin()->second;

            st.erase(st.begin());

            for(auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                if(dis + edgeWt < dist[adjNode]) {
                    if(dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    dist[adjNode] = dis + edgeWt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }

    /*
        Time Complexity: O((V+E)*logV) (where V and E represent the number of nodes 
        and edges of the graph)

        Each node is processed once in the priority queue and deletion and 
        insertion operation takes O(logV) time making it overall O(V*logV) in the 
        worst case.
        For each vertex, all its edges are relaxed. This operation involves updating 
        the priority queue, which takes O(logV) making it overall O(E*logV) for E edges 
        in the worst case.

        Space Complexity: O(V)

        The priority queue will store distances to all nodes in worst case leading to 
        O(V) space.
        The distance array takes O(V) space.

        Why Min Heap is used instead of Queue data structure?
        Even if a Queue data structure is used, the shortest path can be found, but it 
        will act like a brute 
        force solution as all paths are explored, and out of them the shortest one 
        is picked.

        On the other hand, using the Minimum Heap data structure ensures that the 
        shortest path among all the paths is always explored first so that unnecessary 
        iterations can be saved.
    */
};

#define P pair<int,int>

class PrintShortestPath{
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
        vector<P> adj[n+1];

        for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1);

        /* Marking each node as 
        its own parent initially */
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        dist[1] = 0;

        pq.push({0, 1});

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int dis = it.first;
            int node = it.second;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edgeWt = it.second;

                if(dis + edgeWt < dist[adjNode]) {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjNode});
                    parent[adjNode] = node;
                }
            }
        }

        if(dist[n] == 1e9) return {-1};

        vector<int> path;
        // Start from the destination node
        int node = n;

        /* Iterate backwards from destination 
        to source through the parent array */
        while(parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }

        path.push_back(1);

        reverse(path.begin(), path.end());
        path.insert(path.begin(), dist[n]);

        return path;

        /*
            Time Complexity: O((N+M)*logN)

            Each node is processed once in the priority queue and deletion and 
            insertion operation takes O(logN) time making it overall O(N*logN) in the 
            worst case.
            For each vertex, all its edges are relaxed. This operation involves 
            updating the priority queue, which takes O(logV) making it overall O(M*logN) 
            for E edges in the worst case.
            Reconstructing the path involves tracing the parent array, which takes O(N) 
            in the worst case (since we may trace back through all vertices).

            Space Complexity: O(N)

            The priority queue will store distances to all nodes in worst case leading 
            to O(N) space.
            The distance array and parent array takes O(N) space each.
            The path array will store O(N) nodes in the worst case.
        */
    }
};

class ShortestDistanceInBinaryMaze{
private:
    vector<int> delRow = {-1, 0 ,1, 0};
    vector<int> delCol = {0, -1, 0, 1};

    bool isValid(int& row, int& col, int& n, int& m) {
        if(row < 0 || row >= n) return false;
        if(col < 0 || col >= m) return false;

        return true;
    }
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,pair<int, int> destination) {
        // edge case
        if(source.first == destination.first && source.second == destination.second) return 0;

        // uniform 1 step increment, so we don't need priority_queue. thus removing logV complexity
        queue<pair<int, pair<int,int>>> q;

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        // Distane of source from itself is zero
        dist[source.first][source.second] = 0;

        q.push({0, {source.first, source.second}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                /* Checking the validity of the cell and 
                updating if a shorter distance is found */
                if(isValid(newRow, newCol, n, m) && grid[newRow][newCol] == 1 && dis + 1 < dist[newRow][newCol]) {
                    dist[newRow][newCol] = dis + 1;

                    // Return the distance is the destination is reached
                    if(newRow == destination.first && newCol == destination.second) return dis + 1;
                    q.push({1 + dis, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
    /*
        Time Complexity: O(N*M) (where N and M are the dimensions of the grid)
        A simple BFS traversal takes O(V+E) time where V and E represent the number of 
        cells and number of edges.
        Because, V = N*M and E = 4*N*M, the overall time complexity is O(N*M).

        Space Complexity: O(N*M) The distance array takes O(N*M) space and the queue 
        space can go upto O(N*M) in the worst case.
    */
};

#define P pair <int, pair<int,int>>

class PathWithMinimumEffort {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    bool isValid(int& row, int& col, int& n, int& m) {
        if(row < 0 || row >= n) return false;
        if(col < 0 || col >= m) return false;
        return true;
    }
public:
    int MinimumEffort(vector<vector<int>> &heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));
        priority_queue<P, vector<P>, greater<P>> pq;

        // Mark the initial position as 0
        maxDiff[0][0] = 0;

        // starting point
        pq.push({0, {0,0}});

        while(!pq.empty()) {
            auto p = pq.top();
            int diff = p.first;

            int row = p.second.first;
            int col = p.second.second;
            pq.pop();

            if(row == n - 1 && col == m - 1) return diff;

            for(int i = 0; i < 4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(isValid(newRow, newCol, n, m)) {
                    int currDiff = abs(heights[newRow][newCol] - heights[row][col]);
                    if(max(currDiff, diff) < maxDiff[newRow][newCol]) {
                        maxDiff[newRow][newCol] = max(currDiff, diff);
                        pq.push({max(currDiff, diff), {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
    /*
        Time Complexity: O(N*M*log(N*M))

        The algorithm processes each cell and explores its neighbors using a 
        priority queue taking O(4*N*M) time.
        The priority queue operations (insertion and extraction) are logarithmic 
        in nature making overall complexity as O(4*N*M*log(N*M)).
        Space Complexity: O(N*M)

        Matrix to store maximum differences for each cell takes O(N*M) space.
        Priority queue will store N*M elements in worst case contributing to O(N*M) 
        space.
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