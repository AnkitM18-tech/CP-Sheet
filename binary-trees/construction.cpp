#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

bool uniqueBinaryTree(int a, int b){
    // Return false if both traversals are the same 
    // or if they are preorder and postorder
    return !(a == b || (a == 1 && b == 3) || (a == 3 && b == 1));
    // O(1) - TC and SC
    /*
        1. When provided with just preorder and postorder traversals, 
        it is not possible to uniquely reconstruct a binary tree. 
        This is because multiple trees can produce the same preorder and postorder 
        sequences, leaving room for ambiguity.

        2. Preorder traversal starts with the root node and explores the 
        left subtree before the right subtree. 
        This traversal identifies the root and helps in constructing 
        the tree structure. In contrast, inorder traversal processes 
        nodes by visiting the left subtree first, followed by the root, 
        and then the right subtree. This approach clearly separates the 
        left and right subtrees, enabling a unique reconstruction of the 
        binary tree.

        3. Postorder traversal visits nodes in the left subtree, 
        then the right subtree, and finally the root node. 
        The last element represents the root, while preceding elements 
        identify subtrees. Inorder traversal provides a clear division 
        between left and right subtrees. This combination allows for 
        the unique construction of the binary tree.

        4. Inorder traversal is crucial for constructing a unique binary tree. 
        Preorder and postorder traversals alone do not provide explicit division 
        between left and right subtrees, 
        leading to multiple possible structures for nodes with a single child.

        5. For a full binary tree, where every node has either zero or 
        two children, the structure is fixed. Preorder and postorder 
        traversals provide sufficient information to uniquely reconstruct 
        the tree due to the absence of single-child nodes.
    */
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> inMap;

    // Populate the map with indices
    // of elements in the inorder traversal
    for(int i = 0; i<inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    // O(N) -TC and SC = O(N + H)
}

TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
    // Base case: If the start indices
    // exceed the end indices, return null
    if(preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }

    // Create a new TreeNode with value
    // at the current preorder index
    TreeNode* root = new TreeNode(preorder[preStart]);

    // Find the index of the current root
    // value in the inorder traversal
    int inRoot = inMap[root->data];

    // Calculate the number of
    // elements in the left subtree
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);

    return root;
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