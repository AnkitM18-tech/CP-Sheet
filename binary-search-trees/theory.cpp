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

class KthLargestSmallest {
private:
    int k;
    int result;

    void inorder(TreeNode* node) {
        if(node) {
            inorder(node->left);
            if(--k == 0) {
                result = node->data;
                return;
            }
            inorder(node->right);
        }
    }

    void reverseInorder(TreeNode* node) {
        if(node) {
            reverseInorder(node->right);
            if(--k == 0) {
                result = node->data;
                return;
            }
            reverseInorder(node->left);
        }
    }

    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
    }

    int kthLargest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        reverseInorder(root);
        return result;
    }

public:
    void inorderTraversal(TreeNode* node, vector<int>& values) {
        if(node) {
            inorderTraversal(node->left, values);
            values.push_back(node->data);
            inorderTraversal(node->right, values);
        }
    }
    // Inorder traversal of a BST is always sorted
    vector<int> kLargesSmall(TreeNode* root,int k){
        /*
        // Brute - TC = O(N) and SC = O(N)
        vector<int> values;
        inorderTraversal(root, values);

        int kthSmallest = values[k-1];
        int kthLargest = values[values.size() - k];

        return {kthSmallest, kthLargest};
        */
        // Optimal - O(N) - TC, SC = O(H)
        return {kthSmallest(root, k), kthLargest(root, k)};
    }
};

bool validate(TreeNode* node, long min, long max) {
    if(!node) return true;

    if(node->data <= min || node->data >= max) return false;

    bool leftIsValid = validate(node->left, min, node->data);
    bool rightIsValid = validate(node->right, node->data, max);

    return leftIsValid && rightIsValid;
}

bool isBST(TreeNode* root){
    return validate(root, LONG_MIN, LONG_MAX);
    // TC = O(N), SC = O(N) - recursive stack
}

bool getPath(TreeNode* root, vector<int>& path, int x) {
    if(!root) return false;

    path.push_back(root->data);
    if(root->data == x) return true;

    if(getPath(root->left, path, x) || getPath(root->right, path, x)) return true;

    path.pop_back();
    return false;
}

TreeNode* lca(TreeNode* root, int p, int q){
    /*
    // Brute
    // TC = O(N + log(2N)), where N is the number of nodes. 
    // Finding the root-to-node paths using DFS is O(N), 
    // and iterating through arrays is O(min(P1, P2)).
    // O(log2 N) = SC

    vector<int> path1, path2;

    if(!getPath(root, path1, p) || !getPath(root, path2, q)) return NULL;

    int i = 0;
    while(i < path1.size() && i < path2.size() && path1[i] == path2[i]) i++;
    return new TreeNode(path1[i-1]);
    */
    
    // Optimal - TC = O(H) and SC = O(H)
    if(root == NULL) return NULL;
    int curr = root->data;

    if(curr < p && curr < q) return lca(root->right, p, q);

    if(curr > p && curr > q) return lca(root->left, p, q);

    return root;

}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    /*
    // Brute
    if(preorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);

    stack<TreeNode*> s;
    s.push(root);

    for(int i = 1; i < preorder.size(); i++) {
        TreeNode* node = s.top();
        TreeNode* child = new TreeNode(preorder[i]);
        
        // Adjust the stack and place the node in the right position
        while(!s.empty() && s.top()->data < preorder[i]) {
            node = s.top();
            s.pop();
        }

        // Insert node as left or right child
        if(node->data < preorder[i]) node->right = child;
        else node->left = child;

        s.push(child);
    }
    return root;
    // TC = O(N) = SC
    
    // Better - TC = O(N log N) + O(N), SC = O(N)
    vector<int> inorder = preorder;
    sort(inorder.begin(), inorder.end());
    
    unordered_map<int,int> inMap;
    for(int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }

    return buildTree(preorder, inMap, 0, preorder.size() - 1, 0, inorder.size() - 1);
    */
    // Optimal - TC = O(N), SC = O(h)
    int index = 0;
    return bstFromPreorderHelper(preorder, INT_MAX, index);
}

TreeNode* buildTree(const vector<int>& preorder, unordered_map<int,int>& inMap, int preStart, int preEnd, int inStart, int inEnd) {
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preorder, inMap, preStart + 1, preStart + numsLeft, inStart, inRoot - 1);
    root->right = buildTree(preorder, inMap, preStart + numsLeft + 1, preEnd, inRoot + 1, inEnd);

    return root;
}

TreeNode* bstFromPreorderHelper(vector<int>& preorder, int bound, int& index) {
    if(index == preorder.size() || preorder[index] > bound) return NULL;

    TreeNode* root = new TreeNode(preorder[index]);
    index++;

    // Recursively construct the left subtree
    // with the current value as the new bound
    root->left = bstFromPreorderHelper(preorder, root->data, index);
    // Recursively construct the right subtree
    // with the same bound as the parent's bound
    root->right = bstFromPreorderHelper(preorder, bound, index);

    return root;
}

vector<int> succPredBST(TreeNode* root, int key) {
    /*
                // Brute - TC = SC = O(N)
    vector<int> sortedList;
    inorderTraversal(root, sortedList);

    int predecessor = -1, successor = -1;

    for(int i = 0; i < sortedList.size(); i++) {
        if(sortedList[i] < key) predecessor = sortedList[i];
        else if (sortedList[i] > key) {
            successor = sortedList[i];
            break;
        }
    }
    return {predecessor, successor};

    // Better - TC = O(H) and SC = O(1)
    vector<int> result;
    TreeNode* succ = NULL;
    TreeNode* pred = NULL;

    while(root) {
        if(root->data == key) {
            if(root->right != NULL) {
                succ = findMin(root->right);
            }
            if(root->left) {
                pred = findMax(root->left);
            }
            break;
        } else if(root->data < key) {
            pred = root;
            root = root->right;
        } else {
            succ = root;
            root = root->left;
        }
    }

    if(pred) result.push_back(pred->data);
    else result.push_back(-1);

    if(succ) result.push_back(succ->data);
    else result.push_back(-1);

    return result;
    */
    // Optimal - O(N)
    int predecessor = -1;
    int successor = numeric_limits<int>::max();

    // Lambda function to traverse the tree and find successor and
    // predecessor
    function<void(TreeNode*)> traverse = [&](TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        if (node->data < key) {
            // Update predecessor and move to the right subtree
            predecessor = max(predecessor, node->data);
            traverse(node->right);
        } else if (node->data > key) {
            // Update successor and move to the left subtree
            successor = min(successor, node->data);
            traverse(node->left);
        } else {
            // If node's value equals key, find predecessor and successor in
            // subtrees
            if (node->left != nullptr) {
                // Find maximum value in left subtree for predecessor
                TreeNode* temp = node->left;
                while (temp->right != nullptr) {
                    temp = temp->right;
                }
                predecessor = temp->data;
            }

            if (node->right != nullptr) {
                // Find minimum value in right subtree for successor
                TreeNode* temp = node->right;
                while (temp->left != nullptr) {
                    temp = temp->left;
                }
                successor = temp->data;
            }
        }
    };

    traverse(root);

    // Return the result as a vector with predecessor and successor
    return {predecessor == -1 ? -1 : predecessor,
            successor == numeric_limits<int>::max() ? -1 : successor};
}

void inorderTraversal(TreeNode* node, vector<int>& sortedList) {
    if (!node) return;

    inorderTraversal(node->left, sortedList);
    sortedList.push_back(node->data);
    inorderTraversal(node->right, sortedList);
}

TreeNode* findMin(TreeNode* node) {
    while (node->left) node = node->left;
    return node;
}

TreeNode* findMax(TreeNode* node) {
    while (node->right) node = node->right;
    return node;
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