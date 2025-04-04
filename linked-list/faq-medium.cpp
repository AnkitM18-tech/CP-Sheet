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

ListNode* middleOfLinkedList(ListNode* head) {
    /*
    // Brute - O(N/2) + O(N)
    ListNode* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt += 1;
        temp = temp->next;
    }

    int midPos = (cnt/2) + 1;

    ListNode* midNode = head;
    for(int i = 1; i<midPos; i++) {
        midNode = midNode->next;
    }

    return midNode;
    */
    // odd length = fast ends at last node
    // even length = fast ends at null
    // If one pointer is moving 2x fast than the other
    // then when the fast reaches the end , the slow is at the
    // middle - Tortoise Hare Algorithm
    // Optimal
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow; // O(N/2)
}

bool hasCycle(ListNode *head) {
    /*
    // Brute - TC - O(N * 2 * log(N)), SC - O(N)
    ListNode* temp = head;

    unordered_map<ListNode*, int> nodeMap;

    while(temp != NULL) {
        if(nodeMap.find(temp) != nodeMap.end()) {
            return true;
        }

        nodeMap[temp] = 1;
        temp = temp->next;
    }

    return false;
    */
    // Optimal - O(N)
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) return true;
    }

    return false;
    // The reason this complexity is O(N) and not 
    // slower is due to the fact that each step of the 
    // algorithm decreases the gap between the fast and slow pointers 
    // (when they are within the loop) by one node. 
    // Thus, the maximum number of steps required for them to meet 
    // is directly related to the 
    // number of nodes in the list.
}

ListNode *findStartingPoint(ListNode *head) {
    /*
    // Brute - O(N) - SC and TC
    ListNode* temp = head;
    unordered_map<ListNode*, int> nodeList;

    while(temp != NULL) {
        if(nodeList.count(temp) != 0) return temp;
        nodeList[temp] = 1;
        temp = temp->next;
    }

    return NULL;
    */
    // Optimal - O(N)
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}

int findLength(ListNode* slow, ListNode* fast) {
    fast = fast->next;
    int cnt = 1;

    while(slow != fast) {
        cnt++;
        fast = fast->next;
    }
    return cnt;
}

int findLengthOfLoop(ListNode *head) {
    /*
    // Brute - O(N) - TC & SC
    unordered_map<ListNode*, int> nodeList;
    ListNode* temp = head;

    int cnt = 0;

    while(temp != NULL) {
        if(nodeList.find(temp) != nodeList.end()) {
            int loopLength = cnt - nodeList[temp];

            return loopLength;
        }

        nodeList[temp] = cnt;
        temp = temp->next;
        cnt++;
    }

    return 0;
    */
    // Optimal - O(N)
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return findLength(slow,fast);
        }
    }
    return 0;
}

ListNode* deleteMiddle(ListNode* head) {
    /*
    // Brute - O(N + N/2)
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    ListNode* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    int middle = cnt/2;

    temp = head;

    for(int i = 1; i<middle; i++) {
        temp = temp->next;
    }

    if(temp->next != NULL) {
        ListNode* middleNode = temp->next;
        temp->next = temp->next->next;
        middleNode->next = NULL;
        delete middleNode;
    }
    return head;
    */
    // Optimal - O(N/2)
    if(head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }
    
    ListNode* slow = head;
    ListNode* fast = head;
    fast = head->next->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* middleNode = slow->next;
    slow->next = slow->next->next;
    middleNode->next = NULL;
    delete middleNode;
    return head;
}

ListNode* collisionPoint(ListNode *smallerListHead, ListNode *longerListHead, int len) {
    ListNode *temp1 = smallerListHead;
    ListNode *temp2 = longerListHead;
    
    // Adjust the pointers to same level
    for(int i = 0; i < len; i++) temp2 = temp2-> next;
    
    while(temp1 != temp2) {
        temp1 = temp1-> next;
        temp2 = temp2-> next;
    }
    
    return temp1;
}

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    /*
    // Brute - O(N) - SC , TC - O(N+M)
    unordered_set<ListNode*> nodeSet;
    while(headA != NULL) {
        nodeSet.insert(headA);
        headA = headA->next;
    }

    while(headB != NULL) {
        if(nodeSet.find(headB) != nodeSet.end()) return headB;
        headB = headB->next;
    }

    return NULL;
    
    // Better - O(N + M)
    int n1 = 0, n2 = 0;
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while (temp1 != NULL) {
        n1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        n2++;
        temp2 = temp2->next;
    }

    if (n1 < n2) {
        return collisionPoint(headA, headB, n2 - n1);
    }
    return collisionPoint(headB, headA, n1 - n2);
    */
    // Optimal - O(N + M)
    if(headA == NULL || headB == NULL) return NULL;

    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while(temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;

        if(temp1 == NULL) temp1 = headB;
        if(temp2 == NULL) temp2 = headA;
    }

    return temp1;
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