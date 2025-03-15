#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    public:
        int val;
        ListNode* next;
        ListNode* prev;

        ListNode() {
            val = 0;
            next = nullptr;
            prev = nullptr;
        }

        ListNode(int val1) {
            val = val1;
            next = nullptr;
            prev = nullptr;
        }

        ListNode(int val1, ListNode* next1, ListNode* prev1) {
            val = val1;
            next = next1;
            prev = prev1;
        }
};

ListNode * deleteHead(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* temp = head;
    head = temp->next;
    head->prev = nullptr;
    temp->next = nullptr;
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