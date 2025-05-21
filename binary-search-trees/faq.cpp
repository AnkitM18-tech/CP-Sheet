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