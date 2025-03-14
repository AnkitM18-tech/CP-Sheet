#include<bits/stdc++.h>
using namespace std;

// Creating a LL
class Node {
public:
    int data;
    Node* next;

public:
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};

// Function to convert an array to a linked list
Node* arrayToLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;

    // Create head of the linked list
    Node* head = new Node(arr[0]);
    Node* current = head;

   /* Iterate through the array 
   and create linked list nodes*/
    for (int i = 1; i < size; i++) {
        current->next = new Node(arr[i]);
        current = current->next;
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// To calculate length of linked list
int lengthOfLinkedList(Node* head) {
    int length = 0;
    Node* current = head;
    
    // Count the nodes
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    
    return length;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int arr2[] = {1, 2, 3, 4, 5};
    vector<int> arr = {2, 5, 8, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    /*Assigning values to 
    the nodes*/
    Node* y1 = new Node(arr[0], nullptr);
    Node* y2 = new Node(arr[1], nullptr);
    Node* y3 = new Node(arr[2], nullptr);
    Node* y4 = new Node(arr[3], nullptr);

    /**Linking of
     * Nodes*/
    y1->next = y2;
    y2->next = y3;
    y3->next = y4;

    /**Printing Nodes with their 
     * values and data*/
    cout << y1->data << " " << y1->next << "\n";
    cout << y2->data << " " << y2->next << "\n";
    cout << y3->data << " " << y3->next << "\n";
    cout << y4->data << " " << y4->next << "\n";

    // Convert array to linked list
    Node* head = arrayToLinkedList(arr2, size);

    // Print the linked list
    printLinkedList(head);

    return 0;
}