#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
    }
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }
};

ListNode *reverse(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* temp = head;
    ListNode* next = NULL;

    while(temp != NULL) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }

    return prev;
}

int addHelper(ListNode* temp) {
    if(temp == NULL) return 1;

    int carry = addHelper(temp->next);

    temp->val += carry;

    if(temp->val < 10) return 0;

    temp->val = 0;
    return 1;
}

ListNode *addOne(ListNode *head) {
    /*
    // Brute - O(3N)
    head = reverse(head);

    ListNode* current = head;
    int carry = 1;

    while(current != NULL) {
        int sum = current->val + carry;

        carry = sum / 10;
        current->val = sum % 10;

        if(carry == 0) break;

        if(current->next == NULL && carry != 0) {
            current->next = new ListNode(carry);
            break;
        }

        current = current->next;
    }

    head = reverse(head);

    return head;
    */
    // Optimal
    int carry = addHelper(head);

    if(carry == 1) {
        ListNode* newNode = new ListNode(1);
        newNode->next = head;
        head = newNode;
    }
    return head; // O(N) - TC and SC
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