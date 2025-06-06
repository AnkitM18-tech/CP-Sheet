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