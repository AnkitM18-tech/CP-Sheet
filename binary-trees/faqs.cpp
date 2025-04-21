#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;

    if(root == NULL) return result;

    queue<TreeNode* > nodesQueue;
    nodesQueue.push(root);

    bool leftToRight = true;
    while(!nodesQueue.empty()) {
        int size = nodesQueue.size();

        vector<int> row(size);

        for(int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            int index = leftToRight ? i : (size-i-1);

            row[index] = node->data;

            if(node->left) {
                nodesQueue.push(node->left);
            }

            if(node->right) {
                nodesQueue.push(node->right);
            }
        }

        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
    // TC - O(N) and SC - O(N)
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