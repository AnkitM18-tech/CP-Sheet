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

bool isLeaf(TreeNode* root) {
    return (!root->left && !root->right);
}

void addLeftBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* current = root->left;
    while(current) {
        if(!isLeaf(current)) {
            res.push_back(current->data);
        }
        if(current->left) {
            current = current->left;
        } else {
            current  =current->right;
        }
    }
}

void addRightBoundary(TreeNode* root, vector<int>& res) {
    TreeNode* current = root->right;
    vector<int> temp;
    while(current) {
        if(!isLeaf(current)) {
            temp.push_back(current->data);
        }
        if(current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    for(int i = temp.size()-1; i>=0; i--) {
        res.push_back(temp[i]);
    }
}

void addLeaves(TreeNode* root, vector<int>& res) {
    if(isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if(root->left) {
        addLeaves(root->left, res);
    }
    if(root->right) {
        addLeaves(root->right, res);
    }
}

vector <int> boundary(TreeNode* root){
    vector<int> result;
    if(!root) {
        return result;
    }
    if(!isLeaf(root)) {
        result.push_back(root->data);
    }
    addLeftBoundary(root, result);
    addLeaves(root,result);
    addRightBoundary(root,result);

    return result;
    // TC = O(N) and SC = O(N)
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