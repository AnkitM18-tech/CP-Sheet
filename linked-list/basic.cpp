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