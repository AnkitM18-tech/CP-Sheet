#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    private:
        vector<int> rank, size, parent;
    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1, 1);
    
            for(int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }
    
        int findUltimateParent(int node) {
            if(node == parent[node]) return node;
    
            return parent[node] = findUltimateParent(parent[node]);
        }
    
        bool find(int u, int v) {
            return (findUltimateParent(u) == findUltimateParent(v));
        }
    
        void unionByRank(int u, int v) {
            // Get the ultimate parents of both nodes
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
    
            // Return if nodes already belong to the same component
            if(ulp_u == ulp_v) return;
    
            /* Otherwise, join the node to the other 
            node having higher ranks among the two */
            if(rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if(rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            } else {
                /* If both have same rank, join any node to the 
                other and increment the rank of the parent node */
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
    
        void unionBySize(int u, int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);
    
            if(ulp_u == ulp_v) return;
    
            if(size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

/*
    Time Complexity: O(1)
    The actual time complexity of UnionByRank() and findPar() methods is O(4α), 
    which is very small and close to 1. This 4α term has a long mathematical derivation 
    not required for an interview.

    Space Complexity: O(2N) (where N is the number of nodes)
    The Disjoint Set Data structure uses a parent and a rank array each of size N.
*/

#define P pair<int,int>

class PrimsAlgorithm{
    public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> visited(V, 0);

        pq.push({0,0});

        int sum = 0;

        // run for all edges at worst case - e
        while(!pq.empty()) {
            // TC = log (pq-size)
            auto p = pq.top();
            pq.pop();

            int node = p.second;
            int wt = p.first;

            if(visited[node] == 1) continue;
            visited[node] = 1;

            sum += wt;

            // E
            for(auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWt = it[1];

                if(visited[adjNode] == 0) {
                    // log E
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return sum;
    }
    /*
        Time Complexity: O(ElogE) (where E is the number of edges in the graph)
        In the worst case, the min-heap will store all the E edges, and insertion 
        operation on 
        the min-heap takes O(logE) time taking overall O(ElogE) time.

        Space Complexity: O(E + V) (where V is the number of nodes in the graph)
        The min-heap will store all edges in worst-case taking O(E) space and the 
        visited array takes O(V) space.
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

/*
    Spanning Tree:
        A spanning tree is a subset of a weighted graph in which there are N nodes(i.e. all the nodes present in the original graph) and N-1 edges and all nodes are reachable from each other.

    All the spanning trees are subgraphs of the main graph, containing all the N nodes and N-1 edges to connect all nodes. For a particular spanning tree, the sum of edge weights of all its edges is called Weight of that spanning tree.

    Note: A graph may have multiple spanning trees

    Minimum Spanning tree:
        Among all possible spanning trees of a graph, the minimum spanning tree is the one for which the sum of all the edge weights is the minimum.

    Algorithms for finding the Minimum Spanning Tree for a given graph:
        There are two algorithms that come into picture when finding the Minimum spanning tree for a given graph:

        Prim's Algorithm
        Kruskal Algorithm
        Use Cases:
            The concept of finding the Minimum spanning tree for a given graph plays a huge role in daily life:

            Telecommunications Networks: Determining the most efficient way to lay out cables to connect all phone exchanges with the minimum total cable length.
            Computer Networks: Finding the optimal way to connect multiple computers or routers in a Local Area Network (LAN) or Wide Area Network (WAN) to minimize the amount of networking hardware and cabling needed.
            Transportation Networks: Creating the most cost-effective road/railway network that connects all cities without redundant routes.
            Water Supply Networks: Ensuring an efficient layout of pipelines that connect all areas with the least possible construction cost and maintenance effort.
*/