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

ListNode* deleteTail(ListNode* head) {
    if(head == NULL || head->next == NULL) return NULL;

    ListNode* temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    ListNode* newTail = temp->prev;
    newTail->next = nullptr;
    temp->prev = nullptr;

    delete temp;
    return head; // O(1)
}

ListNode* deleteKthElement(ListNode* head, int k) {
    if(head == nullptr) return head;
    int cnt = 0;
    ListNode* temp = head;

    while(temp != nullptr) {
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }
    
    // k larger than length
    if(temp == nullptr) return head;

    ListNode* prev = temp->prev;
    ListNode* next = temp->next;

    // If node to be deleted is only node in list
    if(prev == nullptr && next == nullptr) {
        delete temp;
        return nullptr;
    } 
    // If node to be deleted is head of list
    else if(prev == nullptr) {
        head = next;
        head->prev = nullptr;
        temp->next = nullptr;
    }
    // If node to be deleted is tail of list
    else if(next == nullptr) {
        prev->next = nullptr;
        temp->prev = nullptr;
    }
    // If node to be deleted is in middle of list
    else {
        prev->next = next;
        next->prev = prev;
        temp->next = NULL;
        temp->prev = NULL;
    }

    // free memory
    delete temp;

    return head; // O(k)
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