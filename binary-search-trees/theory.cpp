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

vector<int> floorCeilOfBST(TreeNode* root,int key){
    int floor = -1, ceil = -1;
    TreeNode* current = root;

    // Floor
    while(current) {
        if(current->data == key) {
            floor = current->data;
            break;
        } else if(current->data < key) {
            floor = current->data;
            current = current->right;
        } else {
            current = current->left;
        }
    }

    // Ceil
    current = root;
    while(current) {
        if(current->data == key) {
            ceil = current->data;
            break;
        } else if(current->data > key){
            ceil = current->data;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return {floor,ceil};
    // TC = O(H)
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);

    if(val < root->data) {
        root->left = insertIntoBST(root->left, val);
    } else if(val > root->data) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
    // TC = O(H), for balanced BST O(log N)
}

TreeNode* connector(TreeNode* root) {
    // Case 1: If the node has no left child,
    // return the right subtree to bypass the node.
    if(!root->left) return root->right;
    // Case 2: If the node has no right child,
    // return the left subtree to bypass the node.
    else if(!root->right) return root->right;

    TreeNode* leftchild = root->left;
    TreeNode* leftmost_child_in_right_subtree = root->right;

    // Traverse to the leftmost node in the right subtree.
    while(leftmost_child_in_right_subtree->left) {
        leftmost_child_in_right_subtree = leftmost_child_in_right_subtree->left;
    }

    // Attach the left subtree to the leftmost node in the right subtree.
    leftmost_child_in_right_subtree->left = leftchild;

    // Return the right subtree as the new root of the modified tree.
    return root->right;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return NULL;

    // If the node to be deleted is the root node,
    // use the connector function to replace the root.
    if(root->data == key) return connector(root);

    TreeNode* node = root;
    while(node) {
        if(node->data > key) {
            if(node->left && node->left->data == key) {
                node->left = connector(node->left);
                break;
            } else {
                node = node->left;
            }
        } else {
            if(node->right && node->right->data == key) {
                node->right = connector(node->right);
                break;
            } else {
                node = node->right;
            }
        }
    }
    return root;
    // TC = O(H) = SC
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