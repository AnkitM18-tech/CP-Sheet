#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode *prev;
    ListNode() {
        val = 0;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1) {
        val = data1;
        next = NULL;
        prev = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *prev1) {
        val = data1;
        next = next1;
        prev = prev1;
    }
};

ListNode * deleteAllOccurrences(ListNode* head, int target) {
    ListNode* temp = head;

    while(temp != NULL) {
        if(temp->val == target) {
            if(temp == head) {
                head = temp->next;
            }

            ListNode* prev = temp->prev;
            ListNode* next = temp->next;

            if(next != NULL) {
                next->prev = prev;
            }

            if(prev != NULL) {
                prev->next = next;
            }

            delete temp;
            temp = next;
        } else {
            temp = temp->next;
        }
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