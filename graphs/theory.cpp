#include<bits/stdc++.h>
using namespace std;

/* 

Data structures can be broadly classified into two types:

- Linear: Linear data structures are those where data elements are arranged in a sequential(linear) manner. Example: Arrays, Linked List, Stacks, Queues, etc.
- Non-linear: Non-linear data structures are those where data elements are not arranged in a sequential manner. They form a hierarchical or interconnected structure. Example: Trees, Graphs, etc.

A graph is a non-linear data structure consisting of nodes that have data and are connected to other nodes through edges. Graphs have a wide-ranging application in real life. These include analysis of electrical circuits, finding the shortest routes between two places, building navigation systems like Google Maps, even social media using graphs to store data about each user, etc.

Node(Vertex):

- Nodes are fundamental units of a graph, representing entities or objects. They store the data.
- Nodes are circles represented by number (ordering does not matter).
- They are also referred as vertices.

Edges(Links):

- Edges are connection between nodes, representing relationships or interactions between the nodes.
- Edges are represented by a horizontal line connecting two nodes. Edges can also be termed as pair of vertices.

Edges can be of two types:
- Directed Edges: Edges that have direction, indicating a one-way relationship. Each edge is represented as an ordered pair (u, v), meaning there is a connection from vertex u to vertex v.
- Undirected Edges: Edges that do not have a direction, indicating a two-way relationship. Each edge is represented as an unordered pair {u, v}, meaning there is a mutual connection between vertex u and vertex v.

Directed graph: A graph where all the edges are directed edges, i.e., unidirectional in nature. It contains an ordered pair of vertices. It implies each edge is represented by a directed pair . Therefore, and represent two different edges.

Undirected graph: A graph where all the edges are undirected edges, i.e., bidirectional in nature. In an undirected graph, the pair of vertices representing any edge is unordered. Thus, the pairs (u, v) and (v, u) represent the same edge.

Note: An undirected graph can be converted to a directed graph by converting all the undirected edges into directed edges. An undirected edge between two nodes u and v can be represented as pair of two directed edges, one from node u to v, and other from node v to u.

Components of a graph:
It is not necessary that all the nodes in the graph are connected to each other. Here, comes the concept of a component in the graph. A component of a graph is a group of nodes which are connected to each other directly or indirectly and which are not connected any node from any other group.

Path in a graph:
A path in a graph is a sequence of vertices where each adjacent pair of vertices is connected by an edge. A path always contain unique nodes, i.e., a node cannot appear twice in a path.
It can be of two types:

Simple Path: A path where no vertex is repeated.
Closed Path (Cycle): A path that starts and ends at the same vertex, with no other repetitions of vertices and edges.

Note:
1 2 3 2 1 is not a path, because a node can't appear twice in a path.
1 3 5 is not a path, as adjacent nodes must have an edge and there is no edge between 1 and 3.
Degree of a node in graph:
The degree of a node in a graph is a measure of the number of edges connected to that node.

For an undirected graph:
Degree: The degree of a vertex is the total number of edges connected to it.

Property: The total degree of a graph (sum of degrees of all the nodes) is equal to twice of the number of edges. This is because every edge is associated/connected to two nodes.
Hence, Total degree of graph = 2+2+3+2+3 = 2 X E (where E = 6)

For a directed graph:
In directed graphs, edges have directions (from one vertex to another), hence, there are two types of degrees:
In-degree: The in-degree of a vertex is the number of incoming edges to that vertex.
Out-degree: The out-degree of a vertex is the number of outgoing edges from that vertex.

Edge Weight:
Some graphs have edges that have weights associated to them. It is often referred to as the cost of the edge.

Based on whether the edges in graph are weighted or unweighted, the graphs can be divided into two types:
Weighted Graphs: Having edges that have weights associated with them.
Unweighted Graphs: Having edges that do not have weights associated with them.

Note: In applications, weight may be a measure of the cost of a route. For example, if vertices A and B represent towns in a road network, then weight on edge AB may represent the cost of moving from A to B, or vice versa.

*/

/* 

In the question, it will be mentioned whether the graph is directed or undirected.

The first line contains two space-separated integers n and m denoting the number of nodes and the number of edges respectively.
Next m lines contain two integers u and v representing an edge between u and v. In the case of an undirected graph, if there is an edge between u and v, it means there is an edge between v and u as well.
Note: There is no upper bound on the value of m.

The first hurdle while solving any graph problem is how to represent the graphs in the programming languages. The two most commonly used representations for graphs are:

Adjacency Matrix
Adjacency Lists

Adjacency Matrix:
An adjacency matrix of a graph is a two-dimensional array of size n x n, where n is the number of nodes in the graph, with the property that a[i][j] = 1 if the edge (vᵢ, vⱼ) is in the set of edges, and a[i][j] = 0 if there is no such edge.
Consider the example of the following input:
Input:
    5 6
    1 2
    1 3
    2 4
    3 4 
    3 5 
    4 5

Explanation:
    Number of nodes, n = 5
    Number of edges, m = 6
Next m lines represent the edges.

Adjacency List:
This is a node-based representation. In this representation, each node is associated with a list of nodes adjacent to it. Normally an array is used to store the nodes. The array provides random access to the adjacency list for any particular node.

To create an adjacency list, an array of size n+1 must be created, where n is the number of nodes. 

Weighted Graph Representation:

For adjacency matrix: The weight of the edge between node u and node v can be stored at the location a[u][v].

For adjacency list: Earlier in the adjacency list, a list of integers was stored in each index, but for weighted graphs, a list of pairs (adjacent node, edge weight) will be stored for each node - vector<pair<int,int>> adjList[n+1]

*/

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        // Adjacency Matrix Way
        // Taking the input 
        int n, m;
        cin >> n >> m;
        
        // Adjacency matrix to store the graph - 1 based indexing
        // int adj[n+1][n+1];

        // adjacency list for undirected graph
        vector<int> adj[n+1];
        
        // Add all the edges in the graph 
        for(int i = 0; i < m; i++) {
            // Taking the input
            int u, v;
            cin >> u >> v;
            
            // Adding the edges - matrix
            // adj[u][v] = 1;
            
            /* This statement will be removed 
            in the case of directed graph */
            // adj[v][u] = 1;

            // Adding the edges - List
            adj[u].push_back(v);
            /* This statement will be removed 
            in the case of directed graph */
            adj[v].push_back(u);
        }
        /*  
            Adjacency Matrix -
            Space Complexity: O(N^2) The space needed to represent a graph using its adjacency matrix is N² locations. It is a costly method as n² locations are consumed. It is preferred for dense graphs where the number of edges is more.

            Note: For directed graphs, if there is an edge between u and v it means the edge only goes from u to v, i.e., v is the neighbor of u, but vice versa is not true.
            
            Adjacency List -
            Space Complexity: O(2xE) The space needed to represent a graph using its adjacency matrix is N² locations. This representation is much better than the adjacency matrix for sparse graphs (where the number of edges is less), as matrix representation consumes n² locations, and most of them are unused.

            Note: For directed graphs, if there is an edge between u and v it means the edge only goes from u to v, i.e., v is the neighbor of u, but vice versa is not true. Thus, The space needed to represent a directed graph using its adjacency list is E (O(E)) locations, where E denotes the number of edges, as here each edge data appears only once
        */
    }
    return 0;
}