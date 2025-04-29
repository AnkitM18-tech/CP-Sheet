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

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(!root) return ans;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
    int size = q.size();
    vector<int> level;

    for(int i = 0; i<size; i++) {
        TreeNode* node = q.front();
        level.push_back(node->data);
        q.pop();

        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
    }
    ans.push_back(level);
    }
    return ans;
    // TC = O(N), SC = O(N)
}

void recursionLeft(TreeNode* root, int level, vector<int>& ans) {
    if(root == NULL) return;

    if(ans.size() == level) {
    ans.push_back(root->data);
    }
    recursionLeft(root->left, level+1, ans);
    recursionLeft(root->right, level+1, ans);
}

void recursionRight(TreeNode* root, int level, vector<int>& ans) {
    if(root == NULL) return;

    if(ans.size() == level) {
    ans.push_back(root->data);
    }
    recursionRight(root->right, level+1, ans);
    recursionRight(root->left, level+1, ans);
    // TC = O(N) and SC = O(H)
}

vector<int> rightSideView(TreeNode* root) {
    // Brute
    vector<int> ans;
    /*
    vector<vector<int>> levelTraversal = levelOrder(root);

    for(auto level : levelTraversal) {
        ans.push_back(level.back());
    }

    return ans;
    */
    // Optimal
    recursionRight(root,0,ans);
    return ans;
}

vector<int> leftSideView(TreeNode* root) {
    // Brute
    vector<int> ans;
    /*
    vector<vector<int>> levelTraversal = levelOrder(root);

    for(auto level : levelOrder) {
    ans.push_back(level.front());
    }

    return ans;
    */
    // Optimal
    recursionLeft(root,0,ans);
    return ans;
}

bool getPathToCertainNode(TreeNode* root, vector<int>& arr, int x) {
    if(!root) return false;

    arr.push_back(root->data);

    if(root->data == x) return true;
    if(getPathToCertainNode(root->left, arr, x) || getPathToCertainNode(root->right, arr, x)) {
        return true;
    }

    arr.pop_back();
    return false;
}

vector<vector<int>> allRootToLeaf(TreeNode* root) {
    vector<vector<int>> allPaths;
    vector<int> currentPath;

    dfs(root, currentPath, allPaths);

    return allPaths;
    // TC = O(N) and SC = O(N) - skewed tree
    /*
        vector<int> arr;
        if(root == NULL) return arr;
        getPathToCertainNode(root, arr, x);
        return arr;
    */
}

void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& allPaths) {
    if(!node) return;
    path.push_back(node->data);

    if(!node->left && !node->right) {
        allPaths.push_back(path);
    } else {
        dfs(node->left, path, allPaths);
        dfs(node->right, path, allPaths);
    }
    // backtrack by removing the last node from path
    path.pop_back();
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) {
        return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left == NULL) {
        return right;
    } else if(right == NULL) {
        return left;
    } else {
        // Both left and right are not null, we found our result
        return root;
    }
    // TC = O(N) and SC = O(N)
}

int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;

    int ans = 0;

    queue<pair<TreeNode*,int>> q;
    q.push({root, 0});

    while(!q.empty()) {
        int size = q.size();
        int mini = q.front().second;

        // Store the first and last positions 
        // of nodes in the current level
        int first = 0, last = 0;

        for(int i = 0; i<size; i++) {
            // Calculate current position relative
            // to the minimum position in the level
            int cur_id = q.front().second - mini;
            TreeNode* node = q.front().first;
            q.pop();

            // If this is the first node in the level, 
            // update the 'first' variable
            if(i == 0) first = cur_id;

            // If this is the last node in the level,
            // update the 'last' variable
            if (i == size - 1) {
                last = cur_id;
            }

            if(node->left) q.push({node->left, cur_id * 2 + 1});
            if(node->right) q.push({node->right, cur_id * 2 + 2});
        }
        ans = max(ans,last-first+1);
    }
    return ans;
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