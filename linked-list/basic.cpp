#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;
    int carry = 0;

    while((l1 != NULL || l2 != NULL) || carry) {
        int sum = 0;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;

        ListNode* node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return dummy->next; // O(max(M,N)) - size of l1 and l2
}

ListNode* oddEvenList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    /*
    // Brute
    vector<int> arr;
    ListNode* temp = head;

    /*Traverse the list, skipping one node, 
    and store values in the vector
    while(temp != NULL && temp->next != NULL) {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }

    /*If there's an even number 
    of nodes, add the value
        of the last node
    if(temp != NULL) {
        arr.push_back(temp->val);
    }

    // Reset temp
    temp = head->next;

    /*Traverse the list again, skipping one node 
    and store values 
    in the vector
    while(temp != NULL && temp->next != NULL) {
        arr.push_back(temp->val);
        temp = temp->next->next;
    }

    /* If there's an odd number
    of nodes, add the 
    value of the last node
    if(temp != NULL) {
        arr.push_back(temp->val);
    }

    // Reset temp
    temp = head;
    int i = 0;

    while(temp != NULL) {
        temp->val = arr[i];
        temp = temp->next;
        i++;
    }

    return head; // O(2N)
    */
    // Optimal
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* firstEven = head->next;

    while(even && even->next) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = firstEven;
    return head; // O(N)
}

ListNode *sortList(ListNode *head) {
    /*
    // Brute
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    ListNode* temp = head;

    while(temp != NULL) {
        if(temp->val == 0) cnt0++;
        else if (temp->val == 1) cnt1++;
        else if (temp->val == 2) cnt2++;

        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(cnt0 > 0) {
            temp->val = 0;
            cnt0--;
        } else if(cnt1 > 0) {
            temp->val = 1;
            cnt1--;
        } else if(cnt2 > 0) {
            temp->val = 2;
            cnt2--;
        }
        temp = temp->next;
    }

    return head; // O(2N)
    */
    // Optimal
    if(head == NULL || head->next == NULL) return head;

    ListNode* zeroHead = new ListNode(-1);
    ListNode* oneHead = new ListNode(-1);
    ListNode* twoHead = new ListNode(-1);

    // Traversing the LL
    ListNode* zero = zeroHead;
    ListNode* one = oneHead;
    ListNode* two = twoHead;
    ListNode* temp = head;

    while(temp != NULL) {
        if(temp->val == 0) {
            zero->next = temp;
            zero = temp;
        } else if(temp->val == 1) {
            one->next = temp;
            one = temp;
        } else if(temp->val == 2) {
            two->next = temp;
            two = temp;
        }

        temp = temp->next;
    }
    
    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = NULL;

    ListNode* newHead = zeroHead->next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead; // O(N)
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == NULL) return head;

    /*
    // Brute
    int cnt = 0;
    ListNode* temp = head;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    if(cnt == n) {
        ListNode* newHead = head->next;
        head->next = NULL;
        delete head;
        return newHead;
    }

    int res = cnt - n;
    temp = head;

    while(temp != NULL) {
        res--;
        if(res == 0) {
            break;
        }
        temp = temp->next;
    }
    ListNode* delNode = temp->next;
    temp->next = temp->next->next;
    delNode->next = NULL;
    delete delNode;
    return head;
    // O(L) + O(L-N) We are calculating the length of 
    // the linked list and then iterating up to the (L-N)th 
    // node of the linked list, where L is the total length 
    // of the list and 
    // N is the position of the node to delete.
    */
    // Optimal
    ListNode* fastPtr = head;
    ListNode* slowPtr = head;

    for(int i = 0; i<n; i++) {
        fastPtr = fastPtr->next;
    }

    if(fastPtr == NULL) return head->next;

    while(fastPtr->next != NULL) {
        fastPtr = fastPtr->next;
        slowPtr = slowPtr->next;
    }

    ListNode* delNode = slowPtr->next;
    slowPtr->next = slowPtr->next->next;
    delNode->next = NULL;
    delete delNode;
    return head; // O(N)
}

ListNode* reverseList(ListNode* head) {
    /*
    // Method-1 - Iterative - TC - O(2N) & SC - O(N) 
    ListNode* temp = head;
    stack<int> st;

    while(temp != NULL) {
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        temp->val = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;

    // Method-1 - Iterative - Optimal
    ListNode* temp = head;
    ListNode* prev = NULL;

    while(temp != NULL) {
        ListNode* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev; // O(N)
    */
    // Recursive - O(N)
    if(head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* newHead = reverseList(head->next);
    ListNode* front = head->next;

    front->next = head;
    head->next = NULL;

    return newHead;
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