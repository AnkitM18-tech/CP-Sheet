#include<bits/stdc++.h>
using namespace std;



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