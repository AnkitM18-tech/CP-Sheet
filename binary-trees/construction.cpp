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

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int,int> inorderMap;
    for(int i = 0; i < inorder.size(); i++) {
        inorderMap[inorder[i]] = i;
    }

    return buildTreeHelper(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    // TC = O(N * log N) and SC = O(N + log N)
}

TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, unordered_map<int,int>& inorderMap) {
    if(inStart > inEnd || postStart > postEnd) {
        return NULL;
    }

    int rootValue = postorder[postEnd];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndexInorder = inorderMap[rootValue];
    int leftSubtreeSize = rootIndexInorder - inStart;

    root->left = buildTreeHelper(inorder,inStart,rootIndexInorder - 1, postorder,postStart, postStart+leftSubtreeSize-1,inorderMap);
    root->right = buildTreeHelper(inorder,rootIndexInorder + 1, inEnd, postorder, postStart + leftSubtreeSize, postEnd - 1, inorderMap);

    return root;
}

string serialize(TreeNode* root) {
    if(root == NULL) return "";
    stringstream ss;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        if(current == NULL) {
            ss << "#,";
        } else {
            ss << current->data << ",";
            q.push(current->left);
            q.push(current->right);
        }
    }
    return ss.str();
}

TreeNode* deserialize(string data) {
    if(data.empty()) return NULL;

    stringstream s(data);
    string str;
    getline(s, str, ',');
    // Read the root value from the serialized data
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        // Read the value of the left child from the serialized data
        getline(s, str, ',');
        if(str != "#") {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        // Read the value of the right child from the serialized data
        getline(s, str, ',');
        if(str != "#") {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    // Return the reconstructed root of the tree
    return root;
    // TC = O(N) = SC
}

static void inorder(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

vector<int> getInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* current = root;

    while(current != nullptr) {
        if(current->left == nullptr) {
            // Add current node's value and move to right child
            inorder.push_back(current->data); 
            current = current->right;
        } else {
            // Find predecessor
            TreeNode* prev = current->left;
            while(prev->right && prev->right != current) {
                prev = prev->right;
            }
            /* Establish a temporary link and move to the
            left child */
            if(prev->right == NULL) {
                prev->right = current;
                current = current->left;
            } else {
                /* Remove the temporary link, add current node's value
                and move to the right child */ 
                prev->right = NULL;
                inorder.push_back(current->data);
                current = current->right;
            }
        }
    }
    return inorder;
    // TC = O(2N), SC = O(1)
}

vector<int> preorder(TreeNode* root) {
    vector<int> Preorder;
    TreeNode* current = root;
    while (current != NULL) {
        /* 
    Iterate until the current node becomes null
    If the current node has no left child
    Add the value of the current node to the preorder list
    */
        if (current->left == NULL) {
            Preorder.push_back(current->data);
            current = current->right;
        } else {
            /* 
    If the current node has a left child create a pointer 
    to traverse to the rightmost node in the left subtree
    or until we find a node whose right child is not yet processed
    */ 
            TreeNode* prev = current->left;
            while (prev->right && prev->right != current) {
                prev = prev->right;
            }
            /* 
    If the right child of the rightmost node is null 
    set the right child of the rightmost node to the current node
    Add the value of the current node to the preorder list
    and move to the left child
    */
            if (prev->right == NULL) {
                prev->right = current;
                Preorder.push_back(current->data);
                current = current->left;
            } else {
                /* If the right child of the rightmost node is not null
    Reset the right child to null and move to the right child */
                prev->right = NULL;
                current = current->right;
            }
        }
    }
    return Preorder;
    // TC = O(2N), SC = O(1)
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