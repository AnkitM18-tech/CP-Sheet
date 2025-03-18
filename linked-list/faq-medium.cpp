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

ListNode *reverseLL(ListNode* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* newHead = reverseLL(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

bool isPalindrome(ListNode* head) {
    /*
    // Brute - O(2N) - TC & O(N) - SC
    stack<int> st;
    ListNode* temp = head;

    while(temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;

    while(temp != NULL) {
        if(temp->val != st.top()) {
            return false;
        }
        st.pop();

        temp = temp->next;
    }

    return true;
    */
    // Optimal
    if(head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* newHead = reverseLL(slow->next);
    ListNode* first = head;
    ListNode* second = newHead;

    while(second != NULL) {
        if(first->val != second->val) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLL(newHead);
    return true;
    // O(N/2 + N/2 + N/2 + N/2), 
    // which simplifies to O(2N), ultimately reducing to O(N)   
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