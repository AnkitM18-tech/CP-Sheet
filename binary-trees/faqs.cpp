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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;

    if(root == NULL) return result;
    // Map to store the nodes at each vertical distance and level
    // map<int, map<int, priority_queue<int,vector<int>, greater<int>>>> nodesMap;
    map<int, map<int,multiset<int>>> nodes;

    queue<pair<TreeNode* , pair<int,int>>> q;
    q.push({root, {0,0}}); // {node,{x,y}}

    // Perform BFS
    while(!q.empty()) {
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first;
        int y = p.second.second;

        // Add the node's value to the map at the correct x and y
        // nodesMap[x][y].push(node->data);
        nodes[x][y].insert(node->data);

        if(node->left != NULL) {
            q.push({node->left, {x-1,y+1}});
        }

        if(node->right != NULL) {
            q.push({node->right, {x+1,y+1}});
        }
    }

    // Prepare the result by sorting keys and compiling nodes
    /*
    for(auto& p: nodesMap) {
        vector<int> column;
        for(auto& q : p.second) {
            while(!q.second.empty()) {
                column.push_back(q.second.top());
                q.second.pop();
            }
        }
        result.push_back(column);
    }
    */
    for(auto &p: nodes) {
        vector<int> col;
        for(auto &q: p.second) {
            col.insert(col.end(), q.second.begin(),q.second.end());
        }
        result.push_back(col);
    }
    return result;
    // TC = O(N * log2N * log2N * log2N)
    // SC = O(N + N/2)
}

vector<int> topView(TreeNode *root){
    vector<int> ans;
    if(root == NULL) return ans;

    // Map to store the top view nodes based on their vertical positions
    map<int,int> mpp;
    // Queue for BFS traversal, each element is a pair containing 
    // node and its vertical position
    queue<pair<TreeNode*, int>> q;
    q.push({root,0});

    while(!q.empty()) {
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end()) {
            mpp[line] = node->data;
        }

        if(node->left) q.push({node->left, line-1});
        if(node->right) q.push({node->right, line+1});
    }

    for(auto it : mpp) ans.push_back(it.second);
    return ans;
    // TC = O(N*log N), SC = O(N)
}

vector <int> bottomView(TreeNode *root){
    vector<int> ans;
    if(root == NULL) return ans;

    map<int,int> mpp;
    queue<pair<TreeNode*,int>> q;
    q.push({root,0});

    while(!q.empty()) {
    auto it = q.front();
    q.pop();
    TreeNode* node = it.first;
    int line = it.second;
    mpp[line] = node->data;

    if(node->left) q.push({node->left, line-1});
    if(node->right) q.push({node->right, line+1});
    }

    for(auto it : mpp) {
    ans.push_back(it.second);
    }
    return ans;
    // TC = O(N), SC = O(N)
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