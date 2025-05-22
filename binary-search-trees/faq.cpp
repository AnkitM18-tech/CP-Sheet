#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BSTIterator{
    private:
    /*
        // Brute
        vector<int> values;
        int index;

        void inorderTraversal(TreeNode* node) {
            if(node == NULL) return;
            inorderTraversal(node->left);
            values.push_back(node->data);
            inorderTraversal(node->right);
        }
    */
        // Optimum - O(H)- traversal, O(1) - next and hasNext, SC - O(H)
        stack<TreeNode*> myStack;

        void pushAll(TreeNode* node) {
            while(node) {
                myStack.push(node);
                node = node->left;
            }
        }
	public:
		BSTIterator(TreeNode* root){
			// inorderTraversal(root);
            // index = -1;
            pushAll(root);
		}
		
		bool hasNext(){
			// return index + 1 < values.size();
            return !myStack.empty();
		}
		
		int next(){
            // return values[++index];
            TreeNode* temp = myStack.top();
            myStack.pop();
            pushAll(temp->right);
            return temp->data;
		}
};


class BSTIterator {
    private:
        stack<TreeNode*> st;
        bool reverse;

        void pushAll(TreeNode* node) {
            while(node) {
                st.push(node);
                node = reverse ? node->right : node->left;
            }
        }
    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }

        bool hasNext() {
            return !st.empty();
        }

        int next() {
            TreeNode* node = st.top();
            st.pop();
            if(!reverse) pushAll(node->right);
            else pushAll(node->left);
            return node->data;
        }
};

class TwoSumBST{	
	public:
		bool twoSumBST(TreeNode* root, int k){
            /*
			// Brute force - TC = O(2N), SC = O(N)
            vector<int> sortedElements;
            inorderTraversal(root, sortedElements);

            int left = 0, right = sortedElements.size() - 1;

            while(left < right) {
                int sum = sortedElements[left] + sortedElements[right];
                if(sum == k) return true;
                else if(sum < k) left++;
                else right--;
            }
            return false;
            */
            // Optimal - TC = O(N), SC = O(2 * H)
            if(!root) return false;

            BSTIterator left(root, false); // normal inorder
            BSTIterator right(root, true); // reverse inorder

            int i = left.next();
            int j = right.next();

            while(i < j) {
                if(i + j == k) return true;
                else if (i + j < k) i = left.next();
                else j = right.next();
            }
            return false;
		}
    private:
        void inorderTraversal(TreeNode* node, vector<int>& inorder) {
            if(!node) return;
            inorderTraversal(node->left, inorder);
            inorder.push_back(node->data);
            inorderTraversal(node->right, inorder);
        }
};

class BSTWithTwoNodesSwapped {
public:
    void recoverTree(TreeNode* root) {
        /*
       // Brute - TC = O(2N + N*log N), SC = O(N) + O(H)
       collectInorder(root);
       sort(inorderValues.begin(), inorderValues.end());
       restoreInorder(root);
       */
       // Optimal - O(N) = TC and SC
        TreeNode* first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if(!node) return;

            inorder(node->left);

            if(prev && prev->data > node->data) {
                if(!first) {
                    first = prev;
                    middle = node;
                } else {
                    last = node;
                }
            }

            prev = node;
            inorder(node->right);
        };

        inorder(root);

        if(first && last) {
            swap(first->data, last->data); // Non-adjacent
        } else if(first && middle) {
            swap(first->data, middle->data); // adjacent
        }
    }
private:
    vector<int> inorderValues;
    int index = 0;

    void collectInorder(TreeNode* root) {
        if(!root) return;
        collectInorder(root->left);
        inorderValues.push_back(root->data);
        collectInorder(root->right);
    }

    void restoreInorder(TreeNode* root) {
        if(!root) return;
        restoreInorder(root->left);
        root->data = inorderValues[index++];
        restoreInorder(root->right);
    }
};

class LargestBSTInBinaryTree {
	public:
        tuple<int, bool, int, int> isBSTAndSize(TreeNode* node, int minValue, int maxValue) {
            // Base case: if node is nullptr, it is a valid BST of size 0.
            if(!node) return make_tuple(0, true, INT_MAX, INT_MIN);

            auto [leftSize, isLeftBST, leftMin, leftMax] = isBSTAndSize(node->left, minValue, node->data);
            auto [rightSize, isRightBST, rightMin, rightMax] = isBSTAndSize(node->right, node->data, maxValue);

            // Check if the current node is a valid BST node.
            if(isLeftBST && isRightBST && leftMax < node->data && node->data < rightMin) {
                int size = leftSize + rightSize + 1;
                return make_tuple(size, true, min(node->data, leftMin), max(node->data, rightMax));
            } else {
                return make_tuple(max(leftSize, rightSize), false, INT_MIN, INT_MAX);
            }
        }

        struct NodeValue {
            int minNode, maxNode, maxSize;
            NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}
        };

        NodeValue largestBSTSubtreeHelper(TreeNode* node) {
            if(!node) return NodeValue(INT_MAX, INT_MIN, 0);

            NodeValue left = largestBSTSubtreeHelper(node->left);
            NodeValue right = largestBSTSubtreeHelper(node->right);

            if(left.maxNode < node->data && node->data < right.minNode) {
                return NodeValue(min(node->data, left.minNode), max(node->data, right.maxNode), left.maxSize + right.maxSize + 1);
            }

            return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
        }

		int largestBST(TreeNode* root){
            /*
			// Brute - TC = O(N*N)
            return get<0>(isBSTAndSize(root, INT_MIN, INT_MAX));
            */
            // Optimal - TC = O(N), SC = O(N)
            return largestBSTSubtreeHelper(root).maxSize;
		}
};



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