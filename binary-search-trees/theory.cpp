#include<bits/stdc++.h>
using namespace std;

// Left Child < Node < Right Child
/* 
    In a Binary Search Tree, the maximum height is generally maintained at approximately log2(N), where N is the number of nodes. This is significantly more efficient than a plain Binary Tree, whose maximum height can reach N in the case of a skewed tree. This height difference greatly reduces the time required to search for a node in a BST compared to a simple Binary Tree.For instance, to find an element, you compare it with the BST's root node. If it matches, the search is successful. If the element is greater than the root, you search in the right subtree, which contains all greater values. The left subtree is ignored in this case since it only contains lesser values.

    Usage ->
    Database Indexing: BSTs are used in database indexing to quickly locate records based on keys.
    Symbol Tables: Used in compilers and interpreters to manage variable names and function definitions.
    Memory Management: Implementing data structures like heaps for efficient memory allocation and deallocation.
*/

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    while(root && root->data != val) {
        root = (root->data > val) ? root->left : root->right;
    }
    return root;
    // TC = O(logN)
}



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