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