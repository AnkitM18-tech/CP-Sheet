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

ListNode * removeDuplicates(ListNode *head) {
    ListNode* temp = head;

    while(temp != NULL && temp->next != NULL) {
        ListNode* nextNode = temp->next;

        while(nextNode != NULL && nextNode->val == temp->val) {
            ListNode* duplicateNode = nextNode;
            nextNode = nextNode->next;
            delete duplicateNode;
        }

        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next;
    }

    return head; // O(N)
    // O(n) and not O(n^2) because each node in the doubly linked list 
    // is visited exactly once. The outer loop traverses each distinct 
    // node, and the inner loop skips over consecutive duplicates in a 
    // single pass, ensuring a total linear traversal of the list. 
    // Thus the combined process does not create nested iterations 
    // and remains efficient
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