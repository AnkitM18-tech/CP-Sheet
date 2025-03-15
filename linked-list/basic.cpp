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