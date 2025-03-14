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

ListNode* deleteTail(ListNode* &head) {
    if(head == NULL || head->next == NULL) {
        return NULL;
    }

    ListNode* temp = head;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head; // O(N)
}

ListNode* deleteKthNode(ListNode* &head, int k) {
    if(head == NULL) return NULL;

    if(k == 1) {
        ListNode* temp = head;
        head = temp->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    ListNode* temp = head;
    ListNode* prev = NULL;
    
    while(temp != NULL) {
        cnt++;
        if(cnt == k) {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

ListNode* deleteNodeWithValueX(ListNode* &head, int X) {
    if(head == NULL) return head;

    if(X == head->val) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp != NULL) {
        if(temp->val == X) {
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head; // O(N)
}

ListNode* insertAtHead(ListNode* &head, int X) {
    ListNode* newNode = new ListNode(X);
    newNode->next = head;
    head = newNode;
    return head; // O(1)
    // return new ListNode(X, head);
}

ListNode* insertAtTail(ListNode* &head, int X) {
    ListNode* newNode = new ListNode(X);
    if(head == NULL) return newNode;

    ListNode* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;

    return head; // O(N)
}

ListNode* insertAtKthPosition(ListNode* &head, int X, int K) {
    if(head == NULL) {
        if(K == 1) return new ListNode(X);
        else return head;
    }

    if(K == 1) return new ListNode(X,head);

    int cnt = 0;
    ListNode* temp = head;

    while(temp != NULL) {
        cnt++;
        if(cnt == K-1) {
            ListNode* newNode = new ListNode(X, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head; // O(N)
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