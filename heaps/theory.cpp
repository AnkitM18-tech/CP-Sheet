#include<bits/stdc++.h>
using namespace std;

/* 
The heap property defines the relationship between a parent node and its child nodes in a heap. This property ensures that the structure of the heap remains consistent for efficient operations. The exact nature of this relationship depends on the type of heap. There are two types of heaps:
Min-Heap: The value of each parent node must be less than or equal to the values of its child nodes. This ensures that the smallest element is always at the root of the heap.
Max-Heap: The value of each parent node must be greater than or equal to the values of its child nodes. This ensures that the largest element is always at the root of the heap.

The internal implementation of a heap utilizes the array representation of a heap rather than the tree structure discussed earlier. This highlights the importance of understanding how an almost complete binary tree is represented using an array.

Indexing Technique to Represent the Tree
Root Node: The root of the tree is stored at index 0 (following the 0-based indexing).
Parent-Child Relationships: For a node at index i:
Left Child: The left child is located at index 2*i + 1.
Right Child: The right child is located at index 2*i + 2.
Parent: The parent is located at index ⌈i/2⌉ - 1 - ceil

Leaf Nodes
Leaf nodes are the nodes without any children, and they always appear in the last level (or partially in the second-last level if the last level is incomplete).

In an array representation of a binary tree with N elements
Range of Leaf Node Indices: Leaf Nodes start from the index ⌊N/2⌋ to n-1 (both inclusive).

Non-leaf Nodes
Non-leaf nodes are the nodes that have at least one child.

In an array representation of a binary tree with N elements
Range of Non-leaf Node Indices: Non-leaf Nodes start from the index 0 to ⌊N/2⌋ - 1 (both inclusive).

*/

void heapify(vector<int> &nums, int ind, int val) {
    // If the current value is replaced with a smaller value
    if(nums[ind] > val) {
        nums[ind] = val;
        heapifyUp(nums,ind);
    } else {
        // Else if the current value is replaced with a larger value
        nums[ind] = val;
        heapifyDown(nums,ind);
    }
}

void heapifyDown(vector<int> &arr, int ind) {
    int n = arr.size();
    int smallest_ind = ind;
    int leftChild_ind = 2 * ind + 1, rightChild_ind = 2*ind + 2;

    if(leftChild_ind < n && arr[leftChild_ind] < arr[smallest_ind]) {
        smallest_ind = leftChild_ind;
    }

    if(rightChild_ind < n && arr[rightChild_ind] < arr[smallest_ind]) {
        smallest_ind = rightChild_ind;
    }

    if(smallest_ind != ind) {
        swap(arr[smallest_ind], arr[ind]);
        heapifyDown(arr, smallest_ind);
    }
    return;
}

void heapifyUp(vector<int> &arr, int ind) {
    int parent_ind = (ind-1)/2;
    if(ind > 0 && arr[ind] < arr[parent_ind]) {
        swap(arr[ind], arr[parent_ind]);
        heapifyUp(arr,parent_ind);
    }
    return;
}
// TC = O(logN) SC = O(logN)

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