#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->right = new Node(5);

    return 0;
}

/* 

    Root Node: The topmost node of a binary tree from which all other nodes stem out. This serves as the entry point for traversing the tree structure.

    Children Nodes: Nodes directly connected to a parent node. In a binary tree, a parent node can have zero, one, or two children nodes, each situated to the left or right of the parent node.

    Leaf Nodes: Nodes that do not have any children. These nodes lie on the outermost ends of the tree branches and are the terminal points of the traversal.

    Ancestors: Nodes that lie on the path from a particular node to the root node. They are the nodes encountered while moving upwards from a specific node through its parent nodes until reaching the root of the tree.

    Full Binary Tree: Also known as a Strict Binary Tree, where every node has either zero or two children. No node of this tree has just a single child; all internal nodes have exactly two children or no children if they are leaf nodes.

    Complete Binary Tree: A specialised form of Binary Tree where all levels are filled completely except possibly the last level, which is filled from left to right. All levels of the tree, except possibly the last one, are fully filled. If the last level is not completely filled, it is filled from left to right, ensuring that nodes are positioned as far left as possible.

    Perfect Binary Tree: A type of Binary Tree where all leaf nodes are at the same level and the number of leaf nodes is maximised for that level. Every node in a perfect binary tree has either zero or two children. This means that every internal node (non-leaf node) has exactly two children and all leaf nodes are at the same level

    Balanced Binary Tree: A type of Binary Tree where the heights of the two subtrees of any node differ by at most one. This property ensures that the tree remains relatively well-balanced, preventing the tree from becoming highly skewed or degenerate.

    Degenerate Tree: A Binary Tree where the nodes are arranged in a single path leaning to the right or left. The tree resembles a linked list in its structure where each node points to the next node in a linear fashion.

*/