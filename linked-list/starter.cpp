#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    public:
        int val;
        ListNode* next;

        ListNode() {
            val = 0;
            next = nullptr;
        }

        ListNode(int val1) {
            val = val1;
            next = nullptr;
        }

        ListNode(int val1, ListNode* next1) {
            val = val1;
            next = next1;
        }
};

vector<int> LLTraversal(ListNode *head) {
    vector<int> ans;
    ListNode* current = head;
    while(current != nullptr) {
        ans.push_back(current->val);
        current = current->next;
    }
    return ans; // O(N) - SC & TC
}

ListNode* deleteHead(ListNode* &head) {
    if(head == nullptr) return nullptr;
    ListNode* temp = head;
    head = head->next;
    delete temp;
    return head; // O(1)
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