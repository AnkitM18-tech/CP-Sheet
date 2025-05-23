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

void heapifyDown(vector<int> &arr, int ind) {
    int n = arr.size();
    int smallest_ind = ind;
    int leftChild_ind = 2 * ind + 1, rightChild_ind = 2 * ind + 2;

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

void buildMinHeap(vector<int> &nums) {
    int n = nums.size();
    // Iterate backwards on the non-leaf nodes
    for(int i = n/2 - 1; i >= 0; i--) {
        // Heapify each node downwards
        heapifyDown(nums,i);
    }
    return;
    // TC = O(N)
    // Each heapify call has a time complexity of O(h), where h is the height of the subtree, 
    // h = log(N). The heapify operation is performed for approximately N/2 non-leaf nodes.
    // Due to the variable height for all the subtrees, summing the total work done for all the 
    // nodes results in an overall time complexity of O(N) for building a heap.
    // SC = O(logN)
}

void buildMaxHeap(vector<int> &nums) {
    int n = nums.size();
    for(int i = n - 1; i >= 0; i--) {
        // Heapify each node downwards
        heapifyDown(nums,i);
    }
    // changes in heapifyDown - 
    // arr[leftChild_ind] > arr[smallest_ind]
    // arr[rightChild_ind] > arr[smallest_ind]
}

class MinHeap{
    private:
        vector<int> arr;
        int count;

        void heapifyUp(vector<int> &arr, int ind) {
            int parentInd = (ind - 1) / 2;

            if (ind > 0 && arr[parentInd] > arr[ind]) {
                swap(arr[parentInd], arr[ind]);
                heapifyUp(arr, parentInd);
            }
            return;
        }

        void heapifyDown(vector<int> &arr, int ind) {
            int n = arr.size();
            int smallestInd = ind;
            int leftChildInd = 2 * ind + 1, rightChildInd = 2 * ind + 2;

            if (leftChildInd < n && arr[leftChildInd] < arr[smallestInd]) {
                smallestInd = leftChildInd;
            }

            if (rightChildInd < n && arr[rightChildInd] < arr[smallestInd]) {
                smallestInd = rightChildInd;
            }

            if (smallestInd != ind) {
                swap(arr[smallestInd], arr[ind]);
                heapifyDown(arr, smallestInd);
            }
            return;
        }

        /*
        Time Complexity:

        Insert(val): Inserting and Heapifying upwards contribute to O(logN) time.
        Get Minimum(): Constant time operation, i.e., O(1).
        Extract Minimum(): Involves Heapifying downwards contributing to O(logN)
        time. Heap Size(): Constant time operation, i.e., O(1). Is Empty(): Constant
        time operation, i.e., O(1). Change Key(ind, val): Involves heapifying which
        takes O(logN) time.

        Space Complexity:

        O(N), because of the array used to store the elements.
        */

    public:
        void initializeHeap() {
            arr.clear();
            count = 0;
        }

        void insert(int key) {
            arr.push_back(key);
            heapifyUp(arr, count);
            count += 1;
            return;
        }

        void changeKey(int index, int new_val) {
            if (arr[index] > new_val) {
                arr[index] = new_val;
                heapifyUp(arr, index);
            } else {
                arr[index] = new_val;
                heapifyDown(arr, index);
            }
            return;
        }

        void extractMin() {
            int ele = arr[0];

            // Swap the top value with the value at last index
            swap(arr[0], arr[count - 1]);

            arr.pop_back();
            count = count - 1;
            heapifyDown(arr, 0);
            return;
        }

        bool isEmpty() { return count == 0; }

        int getMin() { return arr[0]; }

        int heapSize() { return count; }
};

class MaxHeap{
    private:
        vector<int> arr;
        int count;

        void heapifyUp(int ind) {
            int parentInd = (ind - 1)/2;
            if(ind > 0 && arr[ind] > arr[parentInd]) {
                swap(arr[ind], arr[parentInd]);
                heapifyUp(parentInd);
            }
            return;
        }

        void heapifyDown(int ind) {
            int n = arr.size();
            int largestInd = ind;

            int leftChildInd = 2 * ind + 1, rightChildInd = 2 * ind + 2;

            if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) {
                largestInd = leftChildInd;
            }

            if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) {
                largestInd = rightChildInd;
            }

            if(largestInd != ind) {
                swap(arr[ind], arr[largestInd]);
                heapifyDown(largestInd);
            }
            return;
        }

    public:

        void initializeHeap(){
            arr.clear();
            count = 0;
        }

        void insert(int key){
            arr.push_back(key);
            heapifyUp(count);
            count++;
            return;
        }

        void changeKey(int index, int new_val){
            if(arr[index] < new_val) {
                arr[index] = new_val;
                heapifyUp(index);
            } else {
                arr[index] = new_val;
                heapifyDown(index);
            }
            return;
        }

        void extractMax(){
            int ele = arr[0];

            swap(arr[0], arr[count-1]);
            arr.pop_back();
            count--;

            heapifyDown(0);
        }

        bool isEmpty(){
            return count == 0;
        }

        int getMax(){
            return arr[0];
        }

        int heapSize(){
            return count;
        }

        /*
        Time Complexity:

        Insert(val): Inserting and Heapifying upwards contribute to O(logN) time.
        Get Maximum(): Constant time operation, i.e., O(1).
        Extract Maximum(): Involves Heapifying downwards contributing to O(logN) time.
        Heap Size(): Constant time operation, i.e., O(1).
        Is Empty(): Constant time operation, i.e., O(1).
        Change Key(ind, val): Involves heapifying which takes O(logN) time.

        Space Complexity: 
        
        O(N), because of the array used to store the elements.
        */
};

bool isHeap(vector<int>& nums) {
    int n = nums.size();

    for(int i = n/2 - 1; i >= 0; i--) {
        int leftChildInd = 2 * i + 1, rightChildInd = 2 * i + 2;
        if(leftChildInd < n && nums[leftChildInd] < nums[i]) return false;
        if(rightChildInd < n && nums[rightChildInd] < nums[i]) return false;
    }
    return true;
    // TC = O(N/2), SC = O(1)
}

void heapifyDown(vector<int> &arr, int ind) {
    int n = arr.size();
    int largestInd = ind;
    int leftChildInd = 2 * ind + 1, rightChildInd = 2 * ind + 2;

    if(leftChildInd < n && arr[leftChildInd] > arr[largestInd]) largestInd = leftChildInd;
    if(rightChildInd < n && arr[rightChildInd] > arr[largestInd]) largestInd = rightChildInd;

    if(largestInd != ind) {
        swap(arr[largestInd], arr[ind]);
        heapifyDown(arr,largestInd);
    }
    return;
}

vector<int> minToMaxHeap(vector<int> &nums) {
    int n = nums.size();

    for(int i = n/2 - 1; i >= 0; i--) {
        heapifyDown(nums,i);
    }
    return nums;
}
/*
Time Complexity: O(N) (where N is the number of elements in the array)
Each heapify call has a time complexity of O(h), 
where h is the height of the subtree, h = log(N). 
The heapify operation is performed for approximately N/2 non-leaf nodes.

Due the variable height for all the subtrees, summing the total work done 
for all the nodes results in an overall time complexity of O(N) for building a heap.

Space Complexity: O(logN)
The recursive calls during heapify require stack space proportional to the height of 
the heap which will be of the order of log(N) in the worst-case.
*/

void heapifyDown(vector<int>& arr,int last, int ind) {
    int n = arr.size();
    int largestInd = ind;
    int leftChildInd = 2 * ind + 1, rightChildInd = 2 * ind + 2;

    if(leftChildInd <= last && arr[leftChildInd] > arr[largestInd]) largestInd = leftChildInd;
    if(rightChildInd <= last && arr[rightChildInd] > arr[largestInd]) largestInd = rightChildInd;

    if(largestInd != ind) {
        swap(arr[largestInd], arr[ind]);
        heapifyDown(arr,last,largestInd);
    }
    return;
}

void buildMaxHeap(vector<int>& nums) {
    int n = nums.size();

    for(int i = n/2 - 1; i >= 0; i--) {
        heapifyDown(nums,n-1,i);
    }
    return;
}

void heapSort(vector<int>&nums) {
    buildMaxHeap(nums);
    int last = nums.size() - 1;

    while(last > 0) {
        swap(nums[0], nums[last]);
        last--;

        if(last > 0) {
            heapifyDown(nums,last,0);
        }
    }
    return;
    /*
    Time Complexity: O(N*logN), where N is the size of the array
    Building a max-heap from the array takes O(N) iterations. Once done, 
    each node is placed at its correct index and the array is heapified 
    (which takes logN iterations) taking overall O(N*logN) time.

    Space Complexity: O(logN)
    Recursive stack space used while building the max-heap is O(logN). 
    Also, the depth of each heapify Down will take O(logN) space.
    */
}

int kthLargestElement(vector<int>& nums, int k) {
    // Brute Force - sort the array in descending order and return arr[k-1]
    // TC = O(N * log N), SC = O(1)
    // Better
    /*
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++) pq.push(nums[i]);

    for(int i = k; i < nums.size(); i++) {
        if(nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
    // TC = O(N * log K), SC = O(K)
    */
    // Optimal - Quick Select and Partition Algorithm
    if(k > nums.size()) return -1;

    int l = 0, r = nums.size() - 1;

    while(true) {
        int pivot = randomIndex(l,r);
        pivot = partitionAndReturnIndex(nums, pivot, l, r);

        if(pivot == k-1) return nums[pivot];
        else if(pivot > k-1) r = pivot - 1;
        else l = pivot + 1;
    }

    return -1;
}

int randomIndex(int &left, int &right) {
    int len = right - left + 1;
    return (rand() % len) + left;
}

int partitionAndReturnIndex(vector<int>& nums, int pivotIndex, int left, int right) {
    int pivot = nums[pivotIndex];
    // Swap the pivot with the left
    swap(nums[left], nums[pivotIndex]);

    // Index to mark the start of right portion
    int ind = left + 1;

    for(int i = left + 1; i <= right; i++) {
        if(nums[i] > pivot) {
            // Place the current element in the left portion
            swap(nums[ind], nums[i]);
            // Move the right portion index
            ind++;
        }
    }

    // Place the pivot at the correct index
    swap(nums[left], nums[ind-1]);
    // Return the index of pivot now
    return ind - 1;
    /*
        Time Complexity: O(N), where N is the size of the given array.
        In the average case (when the pivot is chosen randomly):
        Assuming the array gets divided into two equal parts, with every 
        partitioning step, 
        the search range is reduced by half. Thus, the time complexity is 
        O(N + N/2 + N/4 + ... + 1) = O(N).

        In the worst-case scenario (when the element at the left or right index are chosen 
        as pivot):
        In such cases, the array is divided into two unequal halves, and the search range 
        is reduced by one element with every partitioning step. Thus, the time complexity 
        is O(N + N-1 + N-2 + ... + 1) = O(N2). However, the probability of this worst-case 
        scenario is negligible.

        Space Complexity: O(1), as we are modifying the input array 
        in place and using only a constant amount of extra space.
    */
}

// left (elements > pivot) > pivot >= right (elements <= pivot)

class KthLargest {
    private:
      int k;
      priority_queue<int, vector<int>, greater<int>> pq;
    public:
      KthLargest(int k, vector<int>& nums) {
        // O(N log k)
        this->k = k;
        for(int i = 0; i < nums.size(); i++) {
          if(pq.size() < k) pq.push(nums[i]);
          else if(nums[i] > pq.top()) {
            pq.pop();
            pq.push(nums[i]);
          }
        }
      }
    
      int add(int val) {
        // O(log k)
        if(pq.size() < k) {
          pq.push(val);
        } else if(val > pq.top()){
          pq.pop();
          pq.push(val);
        }
        return pq.top();
      }
    };

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