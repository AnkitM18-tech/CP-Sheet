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

void deleteGivenNode(ListNode* node) {
    ListNode* prev = node->prev;
    ListNode* next = node->next;

    // tail
    if(next == nullptr) {
        prev->next = nullptr;
        node->prev = nullptr;
        delete node;
        return;
    }

    prev->next = next;
    next->prev = prev;

    node->next = nullptr;
    node->prev = nullptr;

    delete node;
    // O(1)
}

ListNode* insertBeforeHead(ListNode* head, int X) {
    ListNode* newHead = new ListNode(X,head,nullptr);
    head->prev = newHead;
    return newHead; // O(1)
}

ListNode* insertBeforeTail(ListNode* head, int X) {
    if(head->next == nullptr) {
        ListNode* newHead = new ListNode(X,head,nullptr);
        head->prev = newHead;
        return newHead;
    }

    ListNode* tail = head;
    while(tail->next != NULL) {
        tail = tail->next;
    }

    ListNode* prev = tail->prev;
    ListNode* newNode = new ListNode(X,tail,prev);

    prev->next = newNode;
    tail->prev = newNode;

    return head; // O(N)
}

ListNode* insertBeforeKthPosition(ListNode* head, int X, int K) {
    if(K == 1) {
        ListNode* newHead = new ListNode(X,head,nullptr);
        head->prev = newHead;
        return newHead;
    }

    ListNode* temp = head;
    int cnt = 0;
    while(temp != nullptr) {
        cnt++;
        if(cnt == K) break;
        temp = temp->next;
    }

    ListNode* prev = temp->prev;

    ListNode* newNode = new ListNode(X,temp,prev);
    prev->next = newNode;
    temp->prev = newNode;

    return head; // O(N)
}

void insertBeforeGivenNode(ListNode* node, int X) {
    ListNode* prev = node->prev;

    ListNode* newNode = new ListNode(X,node,prev);
    prev->next = newNode;
    node->prev = newNode;

    return; // O(1)
    // constant number of pointer updates are being performed 
    // regardless of 
    // the size of the Doubly Linked List.
}

ListNode* arrayToLinkedList(vector<int> &nums) {
    if(nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* prev = head;

    for(int i = 1; i<nums.size(); i++) {
        ListNode* temp = new ListNode(nums[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }

    return head; // O(N) - SC & TC
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