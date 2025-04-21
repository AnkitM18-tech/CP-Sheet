#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    /*
    // Recursive - TC = O(N), N = Number of nodes 
    // & SC = O(h), h = height of tree
    if(root == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + max(left,right);
    */
    // Iterative - O(N) - TC & SC - O(w)
    if(root == NULL) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while(!q.empty()) {
        int size = q.size();

        for(int i = 0; i<size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        level++;
    }
    return level;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    if(p->data != q->data) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    // TC = O(N), SC = O(h)
}

int getHeight(TreeNode *root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return max(leftHeight,rightHeight) + 1;
}

bool isBalanced(TreeNode *root){
    /*
        // for every node of tree - heights of left and right
        // subtrees is <= 1
    	//Brute - TC = O(N^2) SC = O(N)
        //  For each node in the Binary Tree, 
        // all other nodes are traversed to calculate its height, 
        // resulting in a nested traversal structure, 
        // leading to O(N) operations for each of the N nodes, 
        // hence O(N * N) = O(N^2)
        if(root == NULL) return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        if(abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    */
    // Optimal
    return dfsHeight(root) != -1;
    // TC = O(N) = SC
}

int dfsHeight(TreeNode* root) {
    if(root == NULL) return 0;

    int leftHeight = dfsHeight(root->left);
    if(leftHeight == -1) return -1;
    
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight,rightHeight) + 1;
}

int getHeight(TreeNode* root) {
    if(root == nullptr) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

int height(TreeNode* root, int& diameter) {
    if(!root) return 0;

    int lh = height(root->left, diameter);
    int rh = height(root->right, diameter);

    diameter = max(diameter, lh+rh);
    return 1 + max(lh,rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    /*
    // Brute - O(N^2) - TC and SC - O(H)

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    int currentDiameter = leftHeight + rightHeight;

    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));
    */
    // Optimal - O(N)
    // each node is visited once, and 
    // its height is calculated during the postorder traversal.
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

int findMaxPathSum(TreeNode* root, int& maxi) {
    if(root == NULL) return 0;

    // Calculate max path sum for left and right subtree
    // taking care of negative sum, in that case we take 0
    int leftMaxPath = max(0, findMaxPathSum(root->left,maxi));
    int rightMaxPath = max(0, findMaxPathSum(root->right,maxi));

    // update the overall maximum path sum including current node
    maxi = max(maxi,leftMaxPath + rightMaxPath + root->data);

    // return the max sum considering only one branch - left or right 
    // with current node
    return max(leftMaxPath,rightMaxPath) + root->data;
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;

    findMaxPathSum(root,maxi);

    return maxi;
    // TC = O(N)
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