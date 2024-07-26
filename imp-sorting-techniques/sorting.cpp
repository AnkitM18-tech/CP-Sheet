#include<bits/stdc++.h>
using namespace std;

// select minimums and swap
/*
Observation

step 1 ->
swap b/w index 0 and min-index [0 - n-1]
step 2 ->
swap b/w index 1 and min-index [1 - n-1]
step 3 ->
swap b/w index 2 and min-index [2 - n-1]
... so on till n-2, because the last swap will happen there.

swapping starts from 0 till n-2

for(int i=0; i<=n-2; i++) {
    min_index = i;
    for(int j=i;j<=n-1; j++) {
        if(arr[j] < arr[min_index]){
            min_index = j;
        }
    }
    swap(arr[min_index], arr[i]);
}

TC ->

First iteration j loop runs for n times, then n-1, n-2 .. till 2 

so TC nearly equals = O(N * (N+1)/2) = O(N^2) - best, worst, avg TC

*/
void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int min_index = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

// push the maximum to the last by adjacent swaps
/*

Take two elements, compare and swap and move on to the next two. After each adjacent swap cycle till we reach the end, the maximum element will be moved to the last.

step - 1:
index 0,1 compare swap till n-1 [0 - n-1]
step - 2:
index 0,1 compare swap till n-2 [0 - n-2]
... likewise we do till 1, because last swap will happen there. no need to swap single element.

key thing to notice is we should not run the inner loop till the last index, otherwise it will throw run time error since index n is not available for comparison.

for(int i=n-1;i>0;i--){
    for(int j=0;j<=i-1;j++){
        if(arr[j] > arr[j+1]){
            swap(arr[j],arr[j+1])
        }
    }
}

TC ->

similar to selection sort, 1st time it runs n times, then gradually decrease by 1. n-1,n-2,...,1, so nearly equals = n + n-1 + n-2 + .. + 1 = O(N^2) - it is the worst case and average case complexity.

If the array is in ascending order, then no need to run the loop for n times, if no swap takes place in the first loop, then it is already in correct order. so in this case TC = O(N). - best case scenario

*/
void bubbleSort(int arr[], int n){
    for(int i=n-1;i>0;i--){
        int didSwap = 0;
        for(int j=0;j<=i-1;j++){
            int temp;
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                // if numbers swap, then making the flag 1.
                didSwap = 1;
            }
        }
        // if at any time swap didn't happen, then flag remains 0 and we break out of the loop.
        if(didSwap == 0){
            break;
        }
        // for testing purpose only
        cout << "runs\n";
    }
}

// takes an element and put it in its correct place / order.
/*

starting from index 0 -> go towards right and check if the elements are in correct position or not for that element window.(window = index 0 to till the element picked)

so start from the right and then come comparing to the left until there are no elements to be swapped.

the last swap will happen at index 1 when it will get compared with 0 index. inner loop till 0

for(int i=0;i<=n-1;i++){
    int j = i;
    while(j>0 && arr[j-1] > arr[j){
        swap(arr[j],arr[j-1]);
        j--;
    }
}

TC ->

first time - 0 swaps + second time - 1 swaps + third time - 2 swaps ... = similar to summation of 0 till n = O(N^2) - worst case and average case TC.

Best case scenario is O(N) - Linear Time

*/
void insertionSort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
            cout << "runs\n";
        }
    }
}

// Divide and Merge
/*
Algorithm hypothetically divides the array into 2 parts and keeps on doing it until we have divided into single elements in the array then we compare and sort them and merge back into a singular array.This method will be performed for both the sides of splited array.
For merging we will take two poiters and compare both sorted sides and then merge them into a single array.

mergeSort(arr,low,high){
    if(low >= high) return;
    mid = (low + high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

merge(arr,low,mid,high){
    temp = [];
    left = low;
    right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.add(arr[left]);
            left++;
        } else {
            temp.add(arr[right]);
            right++;
        }
    }
    // if any element left in the left array, we add it to the array
    while(left <= mid) {
        temp.add(arr[left]);
        left++;
    }
    // if any element left in the right array, we add it to the array
    while(right <= high) {
        temp.add(arr[right]);
        right++;
    }
    for(int i = low -> high) {
        arr[i] = temp[i-low];
    }
}

TC ->

Since the array is getting split into 2 at every step, the TC will be nearly equals log(base 2)N

eg - array of size 16, getting split into 8,8. Then the array with size 8 gets split into 4,4. till 1,1. so that's 4 steps -> log(16) base 2 = 4.

Merging case requires at the worst case, N comparisons = O(N), it can be fewer in split arrays.

So we can say that it takes about = O(N log N) TC. N = number of elements in the array. base is 2. 

SC ->

In the algorithm we are using indices, so separate spaces.

We are only using a temp array in every merge step, so it will take at max N spaces in the worst case. so SC = O(N)

*/
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low, right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        } else {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high) {
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }
}

void mergeSort(vector<int> &arr, int low,int high){
    if(low == high) return;
    int mid = (low + high)/2;
    mergeSort(arr, low,mid);
    mergeSort(arr, mid+1,high);
    merge(arr,low,mid,high);
}

int findPartitionIndex(vector<int> &arr, int low,int high){
    int pivot = low;
    int i=low,j=high;
    while(i < j){
        while(arr[i] <= arr[pivot] && i <= high-1){
            i++;
        }
        while(arr[j] > arr[pivot] && j >= low+1){
            j--;
        }
        if(i < j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    return j;
}
// can sort any data structure in ascending order, with some tweaks we can sort in decreasing order as well.
/*
    TC -> O(NlogN)
    SC -> O(1)
    It doesn't use any extra temp array for sorting like merge sort.

- pick a pivot (it can be any element of your choice, 1st,last,median or random number) and place it in its correct place in the sorted array. so if we pick every element and put them in their correct places then the array is sorted.
- smaller on the left and larger on the right.

repeat these steps for both the sides till we reach a step where there is a single element in the array, which are sorted by default and eventually we will sort the array.

we will make indices pointing to low and high end of the array.
pivot = arr[low]
then we iterate from low end using variable i if the index element is greater than the pivot we halt and we start from high using variable j if the index element is less than the pivot we halt and we swap the indices i and j till the point i and j cross path. then we swap the pivot and the index at which we stopped swapping (element < pivot).

Now the pivot is in the correct place. and everything on the left is < pivot and everything on the right is > pivot. So pivot is the partition index.

so the new (hypothetical) arrays which need to be sorted are [low,partition-1] and [partition+1,high]. then we can perform the quick sort on both of the sides.

int findPartition(arr,low,high){
    int pivot = low;
    i = low; j = high;
    while(i<j){
        while(arr[i] <= arr[pivot] && i <= high-1){
            i++;
        }
        while(arr[j] > arr[pivot] && j >= low+1){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

since we can exceed the size boundary if we equals to low and high.we need to be careful. and do low+1 so if we decrease by 1 it will stop at low. and similarly high - 1 if we increase by 1 it will stop at high.

and <= and > -> if we have other elements same as the pivot, so we need to decide on which side we should keep it. so if we want to keep it  on the left side then we can do arr[i] <= arr[pivot] and arr[j] > arr[pivot]. and right side array will be vice-versa.

quickSort(arr,low,high){
    if(low < high){
        partition_index = findPartition(arr,low,high);
        quickSort(arr,low,partition-1);
        quickSort(arr,partition+1,high);
    }
}

TC = O(NlogN) -> because we are partitioning the array, and then rearranging it. similar to merge sort (not equal halves but similar height of split tree log2N) and the array is being traversed for the entire length. i -> low to high and j -> high to low.

SC = we are only using recursion stack space, no extra space is used so O(1).

*/
// divide and conquer algorithm
void quickSort(vector<int> &arr,int low, int high) {
    if(low < high){
        int partition_index = findPartitionIndex(arr,low,high);
        quickSort(arr,low,partition_index-1);
        quickSort(arr,partition_index+1,high);
    }
}

/*

In the iterative method, we usually select a range(using a loop), and for each range, we repeatedly swap(using another loop) the adjacent elements(if arr[i] > arr[i+1]) until the maximum element in that range reaches the end.

The flow of the algorithm goes like this: in the first iteration, we select the range 0 to n-1 and swap adjacent elements(if arr[i] > arr[i+1]) until the maximum element reaches the (n-1)th index. Similarly, in the second iteration, the second maximum element reaches the (n-2)th index. So, the sorting basically occurs in the backward direction.  After (n-1) such iterations we get the sorted array.

Now, in the recursive approach, we will just select the range recursively instead of using any loop. This is the only change we will do the recursive bubble sort algorithm and the rest of the part will be completely the same as it was in the case of iterative bubble sort.

The approach will be the following:

First, call the recursive function with the given array and the range of n(size of the array).
Inside that recursive function, repeatedly swap 2 adjacent elements if arr[j] > arr[j+1].
Here, the maximum element of the unsorted array reaches the end of the unsorted array after each recursive call.
Each time after step 2, call the recursion again decreasing the range by 1.
The recursion will continue until the range(i.e. the size) of the array is reduced to 1.
Base Case: if(n == 1) return;

Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.

Reason: If we carefully observe, we can notice that the recursion call, is occurring for n times, and for each recursion call, the loop j runs from 0 to n-2. For, the range of size n, the inner loop runs n-1 times, for the range of size n-1, the inner loop runs n-2 times, and so on. So, the total steps will be approximately the following: (n-1) + (n-2) + (n-3) + ……..+ 3 + 2 + 1. The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(N) auxiliary stack space.

Optimized approach (Reducing time complexity for the best case):
The best case occurs if the given array is already sorted. We can reduce the time complexity to O(N) by just adding a small check inside the recursive function. 

We will check in the first recursion call if any swap is taking place. If the array is already sorted no swap will occur and we will return from the recursion call. 
Thus the number of recursions will be just 1. And our overall time complexity will be O(N).



*/
void recursiveBubbleSort(vector<int> &arr,int n){
    // Base Case: range == 1.
    if (n == 1) return;

    int didSwap = 0;
    for (int j = 0; j <= n - 2; j++) {
        if (arr[j] > arr[j + 1]) {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
            didSwap = 1;
        }
    }

    // if no swapping happens.
    if (didSwap == 0) return;

    //Range reduced after recursion:
    recursiveBubbleSort(arr, n - 1);
}

/*

Approach: 
In the iterative method, we did the following:

Take an element from the unsorted array(using an outer loop).
Place it in its corresponding position in the sorted part(using an inner loop).
Shift the remaining elements accordingly.
Now, in the recursive approach, we will just select the element recursively instead of using any loop. This is the only change we will do the recursive insertion sort algorithm and the rest of the part will be completely the same as it was in the case of iterative insertion sort.

The approach will be the following:

First, call the recursive function with the given array, the size of the array, and the index of the selected element(let's say i).
Inside that recursive function, take the element at index i from the unsorted array.
Then, place the element in its corresponding position in the sorted part(using swapping).
After that, Shift the remaining elements accordingly.
Finally, call the recursion increasing the index(i) by 1.
The recursion will continue until the index reaches n(i.e. All the elements are covered).
Base Case: if(i == n) return;

Time Complexity: O(N2), (where N = size of the array), for the worst, and average cases.

Reason: If we carefully observe, we can notice that the recursion call will occur for n times, and for each i, inside the recursive function, the loop j runs from i to 1 i.e. i times. For, i = 1, the loop runs 1 time, for i = 2, the loop runs 2 times, and so on. So, the total steps will be approximately the following: 1 + 2 + 3 +……+ (n-2) + (n-1). The summation is approximately the sum of the first n natural numbers i.e. (n*(n+1))/2. The precise time complexity will be O(n2/2 + n/2). Previously, we have learned that we can ignore the lower values as well as the constant coefficients. So, the time complexity is O(n2). Here the value of n is N i.e. the size of the array.

Space Complexity: O(N) auxiliary stack space.

Best Case Time Complexity: 

The best case occurs if the given array is already sorted. And if the given array is already sorted, the recursion calls will only occur and inside the recursive function, the loop will run for 0 times(as each element is already present in its correct position). So, our overall time complexity in the best case will boil down to O(N), where N = size of the array.

*/
void recursiveInsertionSort(vector<int> &arr,int i, int n){
    // Base Case: i == n.
    if (i == n) return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    recursiveInsertionSort(arr, i + 1, n);
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    /*
    int arr[N];
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    insertionSort(arr,N);
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    */
    vector<int> arr(N);
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    // quickSort(arr,0,arr.size()-1);
    // recursiveBubbleSort(arr,N);
    recursiveInsertionSort(arr,0,N);
    for(int i=0;i<N;i++){
        cout << arr[i] << " ";
    }
    return 0;
}