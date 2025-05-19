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