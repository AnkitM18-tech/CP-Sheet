#include<bits/stdc++.h>
using namespace std;

/*
Never jump directly to the optimised solution.

we should always drive the interview.
Ask for test cases, edge cases, brute force method first and then go towards the better and optimal solution

Brute Force ->

sort the array and return the last element of the array

TC -> O(NlogN) -> quick sort or merge sort.

Optimal Solution ->
take the first element as largest and run a loop and compare with each element of the array and return the largest.
TC -> O(N) since we are only running the loop once for 0 to n-1
*/
int largestElementInArray(int arr[], int n){
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i] > largest) largest = arr[i];
    }
    return largest;
}

/*
second largest or smallest element in the array
Brute Force ->

sort the array and return the second last element of the array

there can be multiple largest elements in the array.
so we can compare first and return the second largest element.

i = n-2;i>=0;i--
if(arr[i] != largest) {
    second = arr[i];
    break;
}
TC = sorting took -> NlogN, then the comparison at the worst case takes O(N) or it doesn't exist.

better approach would be ->
first pass ->

largest = arr[0];
for(i=1;i<n;i++){
    if(arr[i] > largest) largest = arr[i]
}

second pass ->
sLargest = -1;
for(i=1;i<n;i++){
    if(arr[i] > sLargest && arr[i] != largest) sLargest = arr[i]
}
TC = O(2N)

Optimal Solution ->

largest = arr[0], sLargest = -1 / INT_MIN if the array contains negative numbers.
for(i=1;i<n;i++){
    if(arr[i] > largest){
        sLargest = largest;
        largest = arr[i];
    } else if(arr[i] < largest && arr[i] > sLargest) {
        sLargest = arr[i];
    }
}

TC = O(N)

*/
int secondLargestElementInArray(int arr[], int n){
    int largest = arr[0],sLargest = INT_MIN;
    for(int i=1;i<n;i++){
        if(arr[i] > largest){
            sLargest = largest;
            largest = arr[i];
        } else if(arr[i] < largest && arr[i] > sLargest) {
            sLargest = arr[i];
        }
    }
    return sLargest;
}

int secondSmallestElementInArray(int arr[], int n){
    int smallest = arr[0], sSmallest = INT_MAX;
    for(int i=1;i<n;i++){
        if(arr[i] < smallest){
            sSmallest = smallest;
            smallest = arr[i];
        } else if(arr[i] > smallest && arr[i] < sSmallest) {
            sSmallest = arr[i];
        }
    }
    return sSmallest;
}

/*

Just traverse from start to end and check if the previous element is less than = the current element or not.

TC = O(N)

*/
bool checkIfArrayIsSorted(int arr[], int n){
    for(int i=1;i<n;i++){
        if(arr[i-1] <= arr[i]){
            continue;
        } else {
            return false;
        }
    }
    return true;
}

/*

Array given is a sorted array
so we need to return the size of the array in the end and remove duplicates in-place.

Brute Force ->
using a set data structure
set<int> st;
for(int i=0;i<n;i++){
    st.insert(arr[i]);
}

index = 0;
for(auto it: st){
    arr[index] = it;
    index++;
}
return index;

TC = NlogN for st.insert + N for assigning values back to array
SC = O(N) extra space set

Optimal Approach ->
2 pointer approach

we take the first element and then traverse the array to find the next element != first element and then put that element next in the array.

int i = 0;
for(int j=1;j<n;j++){
    if(arr[j] != arr[i]){
        i++;
        arr[i] = arr[j];
    }
}
return i+1;

returns size of array

TC = O(N), SC = O(1)

*/
int removeDuplicatesFromSortedArray(int arr[], int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

/*

Left rotate an array by 1 element
[1,2,3,4,5] => [2,3,4,5,1]

TC = O(N), SC = O(1)

*/
void rotateArrayLeftByOnePosition(int arr[], int n){
    int temp = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

/*

[1,2,3,4,5,6] , d = 2
=> [3,4,5,6,1,2]
if d = 6 => [1,2,3,4,5,6] it will be the original array. so anything above the size of the array we can break it down into size + extra_rotations, so that we just need to perform the extra rotation only to get the desired result.

d = 13 = 6 + 6 + 1, we can say that multiple of [size] rotations can be performed to get the original array.

so no matter what is the number of d, we need to perform d % N rotations.

Brute Force ->

- put d % n elements in the temp array
temp[] = [1,2]
for(int i=0;i<d;i++){
    temp.push_back(arr[i]);
}

- shifting from d till n
for(int i=d;i<n;i++){
    arr[i-d] = arr[i];
}

- putting temp array elements in the array, number of places occupied = n-d = 3, (0,1,2) and index 3 till end we need to add temp.
j = 0
for(int i=n-d;i<n;i++){
    arr[i] = temp[j];
    j++;
}

we can remove j, and do it like i-(n-d). so now i-(n-d) becomes 0 since we are starting from n-d, then 1,2 ..

TC = O(d) + O(n-d-1) + O(d) = O(n+d)
SC = O(d)

to get rid of the extra space O(d) => 
we need observation and that would be our optimal solution

reverse the left part and right part and if we reverse the entire array now we will get the desired array.

reverse(a,a+d);
reverse(a+d,a+n);
reverse(a,n);

So the TC = O(2N) - TC slightly increased but we got rid of the extra space temp array.

*/
void reverse(int arr[],int start, int end){
    while(start <= end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void rotateArrayLeftByDPlaces(int arr[], int n, int d){
    d = d % n;
    /*
    // put the first d elements in a temp array
    int temp[d];
    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }
    // shifting the array
    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }
    // putting the temp array elements at the back
    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }
    */
   // stl has inbuilt reverse function as well we can directly use that or we can create a manual reverse function.
    //    reverse(arr,arr+d);
    //    reverse(arr+d,arr+n);
    //    reverse(arr,arr+n);
   reverse(arr,0,d-1);
   reverse(arr,d,n-1);
   reverse(arr,0,n-1);
}

void rotateRightDPlaces(int arr[], int n, int d){
    d = d % n;
    /*
    // put the first d elements in a temp array
    int temp[d];
    for(int i=n-d;i<n;i++){
        temp[i-(n-d)] = arr[i];
    }
    // shifting the array
    for(int i=n-d-1;i>=0;i--){
        arr[i+d] = arr[i];
    }
    // putting the temp array elements at the back
    for(int i=0;i<d;i++){
        arr[i] = temp[i];
    }
    */
    reverse(arr,n-d,n-1);
    reverse(arr,0,n-d-1);
    reverse(arr,0,n-1);
}

/*
Move all zeros to the end of the array

1 0 2 0 2 0 3 3 4 => 1 2 2 3 3 4 0 0 0

Brute Force ->

First iterate through the array and put all the non-zero numbers in a temp array/list.
Then store the non-zero numbers in the original array and then put the 0s in the end.

temp[] -> vector
for(int i=0;i<n;i++){
    if(arr[i] != 0) temp.push_back(arr[i]);
}
for(int i=0;i<temp.size();i++){
    arr[i] = temp[i];
}
for(int i=temp.size();i<n;i++){
    arr[i] = 0;
}

N = total numbers;x = non zero elements
TC = O(N) + O(x) + O(N-x) = O(2N)
SC = O(x) => O(N) worst case if the array doesn't contain any zeros.

Optimal Solution =>

2 pointer approach

one pointer pointing to the first zero, and one pointer pointing to the first non-zero element next to 0. we iterate through the array and swap the 0s with non-zero elements. if both the pointer are at 0, we don't swap.

step-1
find the first 0 element - O(x)

j = -1
for(int i=0;i<N;i++){
    if(arr[i] == 0) j=i;
    break;
}

step-2 - O(N-x)
for(int i=j+1;i<N;i++){
    if(arr[i] != 0){
        swap(arr[i],arr[j]);
        j++;
    }
}

TC = O(N), SC = O(1)

*/

void moveZerosToTheEndBrute(int arr[], int n){
    // step - 1
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i] != 0) temp.push_back(arr[i]);
    }
    // step - 2
    for(int i=0;i<temp.size();i++){
        arr[i] = temp[i];
    }
    // step - 3
    for(int i=temp.size();i<n;i++){
        arr[i] = 0;
    }
}

void moveZerosToTheEndOptimal(int arr[],int n){
    int j = -1;
    // step - 1
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    // j == -1 means no-non zero numbers, so we will run the loop step - 2 if we have a 0 in the array.
    if(j == -1) return;
    // step - 2
    for(int i = j+1;i<n;i++){
        if(arr[i] != 0){
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

/*
Iterate through the array and find the first occurence of the given element.
TC = O(N)

Variations -> find last occurence of element = iterate from last element. Find all occurences of element = iterate and store the occurences in a temp array and return.
*/
int linearSearch(int arr[],int n, int k){
    for(int i=0;i<n;i++){
        if(arr[i] == k) return i;
    }
    return -1;
}

/*
Union of two sorted arrays
arr1 = [1,1,2,3,4,5], arr2 = [2,3,4,4,5]
union[] = [1,2,3,4,5] - add both the arrays and put no repeated elements

Brute Force ->
since we have to return unique elements, map or set data structures are helpful.

we just iterate through both the arrays and put elements in the set. In this way we will get all unique elements from both arrays. we can simply put them in the union array.

set<int> st;
for(int i=0;i<n1;i++){
    st.insert(arr1[i]);
}
for(int i=0;i<n2;i++){
    st.insert(arr2[i]);
}
union[st.size()];
int i=0;
for(auto it: st){
    union[i] = it;
    i++;
}
n = size of set which is varying, x = N1 + N2 - worst case

TC = O(N1log n) + O(N2log n) + O(x)
SC = O(N1 + N2) -> worst case for the external set => each element distinct + O(N1 + N2) = used to return the union array.

For the optimal approach, we will use 2 pointer approach.

we keep a pointer i in the first array, and another pointer j in the second array.

then we compare both the numbers, and put the smallest element in the union array.then we move the pointer of that array whose element was included in the union array. then we keep on checking if the elements in both the arrays are present in the union array or not and we keep on adding them in the sorted manner. if the iteration in one of the arrays is over, then we stop comparing, we will just iterate over the other array and add the extra elements in the union array.

TC = O(N1 + N2) - iterating over the two arrays
SC = O(N1 + N2) - only for returning the answer, no extra space used for algorithm.

*/

vector<int> unionOfSortedArrayBrute(int arr1[],int n1, int arr2[], int n2){
    set<int> st;
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    vector<int> unionArray;
    for(auto it: st){
        unionArray.push_back(it);
    }
    return unionArray;
}

vector<int> unionOfSortedArrayOptimal(int arr1[],int n1,int arr2[],int n2){
    int i=0,j=0;
    vector<int> unionArray;
    while(i<n1 && j<n2){
        if(arr1[i] <= arr2[j]){
            if(unionArray.size() == 0 || unionArray.back() != arr1[i]){
                unionArray.push_back(arr1[i]);
            }
            i++;
        }else {
            if(unionArray.size() == 0 || unionArray.back() != arr2[j]){
                unionArray.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArray.back() != arr2[j]){
            unionArray.push_back(arr2[j]);
        }
        j++;
    }
    while(i<n1){
        if(unionArray.back() != arr1[i]){
            unionArray.push_back(arr1[i]);
        }
        i++;
    }
    return unionArray;
}

/*
Intersection of two sorted arrays
arr1 = [1,1,2,3,4,5], arr2 = [2,3,4,4,5]
intersection[] = [2,3,4,5] - common elements from both the arrays, repeatation is allowed.

Brute Force ->
iterate over the elements of two arrays and check for every element in one array if there is an element present in the other array as well. If present then we put that into the visited array mapped to any one of the arrays and put it into intersection array, else we move forward. We are keeping track of the elements we visited.We won't consider the visited elements

for each i we are looping over the elements of second array, and marking them as visited.If any of the arrays are exhausted then the looping stops and we get the final array.

arr1 - n1, arr2 - n2, vis[n2] - visited array of size n2
vis[n2] = {0};
ans = []

for(i = 0 to n1){
    for(j = 0 to n2){
        if(arr1[i] == arr2[j] && vis[j] == 0){
            ans.add(arr2[j]);
            vis[j] = 1;
            break;
        }
        if(arr2[j] > arr1[i]) break;
    }
}

TC = O(N1 * N2)
SC = O(N2) - depending upon the array for which we have mapped the visited array, SC will change. It is better to take the visited array for the smaller array.

Optimal solution =>

2 pointer approach ->

one pointer for each array.
if one element in not present in the another array or the other array element is >(since we are matching the first array numbers with the second), then we can move ahead for that pointer. if a number got it's corresponding match then we can add that to ans array and move ahead for both pointers. If any array is exhausted then we can stop the iteration there, we don't have any element to compare.

TC = O(n1+n2) - worst case scenario
SC = O(n1+n2) to return the answer in worst case scenario

*/

vector<int> arrayIntersectionBrute(int a[],int n1, int b[], int n2){
    vector<int> intersectionArray;
    vector<int> visited(n2,0);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(a[i] == b[j] && visited[j] == 0){
                intersectionArray.push_back(b[j]);
                visited[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return intersectionArray;
}

vector<int> arrayIntersectionOptimal(int a[], int n1, int b[], int n2){
    vector<int> intersectionArray;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(a[i] == b[j]){
            intersectionArray.push_back(b[j]);
            i++;
            j++;
        }else if(b[j] > a[i]) {
            i++;
        }else if(b[j] < a[i]){
            j++;
        }
    }
    return intersectionArray;
}

/*
Missing Numbers
arr = [1,2,4,5] of size N - 1 is given and N = 5 given.
we have to find find the missing number

Brute Force ->
We do a linear search on the array and find the missing number

for(i=0;i<n;i++){
    flag = 0;
    for(j=0;j<n-1;j++){
        if(arr[j] == i) {
            flag = 1;
            break;
        }
    }
    if(flag == 0) return i;
}

TC = O(N^2) in the worst case. The inner loop will find 1,2 at the front and break out of loop. So it's a hypothetical situation.
SC = O(1)

Better Approach ->
Use Hashing -
hash array of size N+1.
Then we will iterate the array and increase the corresponding count of the element in the hashing array. Whichever element has 0 count, that is the missing number.

hash[N+1] = {0};
for(i=0;i<n-1;i++){
    hash[arr[i]] = 1;
}
for(i=1;i<n;i++){
    if(hash[i] == 0) return i;
}

TC = O(N) + O(N) = O(2N)
SC = O(N+1)

Optimal Solution ->
sum and xor

SUM ->
sum of 1 to N = N*(N+1)/2
sum of array elements = using loop.
sum of 1 to N - array elements sum = missing number.

sum = N*(N+1)/2;
s2 = 0;
for(i=0;i<n-1;i++){
    s2 = s2 + arr[i];
}
return sum - s2;
TC = O(N), SC = O(1)

XOR ->
a ^ a = 0
a^a ^ b^b = 0
0 ^ a = a

xor1 = 1^2^3^4^5;
xor2 = iterate the array then = 1^2^4^5;

now xor1 ^ xor2 = 3 answer.

xor1 = 0, xor2 = 0
for(i = 1 -> N){
    xor1 = xor1^i;
}

for(i = 0;i<n-1;i++){
    xor2 = xor2^arr[i];
}

return xor1 ^ xor2;

TC = O(2N)

we can still do better we can remove the xor1 loop and put that inside xor2 loop like ->

for(i = 0;i<n-1;i++){
    xor2 = xor2^arr[i];
    xor1 = xor1 ^ (i+1); // will be from 1 to index+1
}
xor1 = xor1 ^ N;

TC = O(N)

XOR approach will do a bit better, because if the N = 10^5 then the sum approach N * N+1/2 will be nearly equal to 10^10. so we need a bigger data type than int. so it will be slightly slower than xor approach.

XOR of all numbers won't be that big.

*/
int missingNumber(int arr[],int n){
    int xor1 = 0, xor2 = 0;
    for(int i=0;i<n-1;i++){
        xor1 = xor1 ^ arr[i];
        xor2 = xor2 ^ (i+1);
    }
    xor2 = xor2 ^ n;
    return xor1 ^ xor2;
}

/*
Maximum Consecutive 1's

we will be given an array of 0s and 1s.

arr = [1,1,0,0,0,1,1,1,0,1]

we need to return the maximum consecutive 1's , here ans = 3

maxi = 0;
cnt = 0;
for(i = 0 -> n){
    if(arr[i] == 1) {
        cnt++;
        if(cnt > maxi) maxi = cnt;
    } else {
        cnt = 0;
    }
}

TC = O(N)

*/
int maximumConsecutive1s(int arr[], int n){
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(arr[i] == 1){
            cnt++;
            maxi = max(maxi,cnt);
        } else {
            cnt = 0;
        }
    }
    return maxi;
}

/*
find the number that appears once and other numbers are present twice.

an array is given in which, each element has 2 occurrences except for one element, we need to return that element.

arr[] = {1,1,2,3,3,4,4};

Brute Force ->

We iterate over the array and find out the number of occurrences for a number and return that number.

for(i=0 -> n){
    num = arr[i];
    cnt = 0
    for(j=0 -> n){
        if(arr[j] == num){
            cnt++;
        }
    }
    if(cnt == 1) return num;
}

TC = O(N^2); SC = O(1)

Better Approach ->

use hashing -

first we need to find the maximum number from the array for the hash array size.

maxi = arr[0];
for(i=0;i<n;i++){
    maxi = max(maxi,arr[i]);
} - O(N)

hash[maxi] = {0};

for(i=0;i<n;i++){
    hash[arr[i]]++;
} - O(N)

for(i=0;i<n;i++){
    if(hash[arr[i]] == 1){
        return arr[i];
    }
} - O(N)

TC = O(3N), SC - O(maxi) = depends on the input, the maximum number out of it.

If we are running the array till the max number only, then in some cases it might be better wrt TC, but if the number is large then the total array iteration is better.

but array can't be used everywhere because if the data type is big and there are negative numbers we need to use maps.

the code will be same but we just need to replace array with map.

ordered map -> TC = N log M
M = size of map, N = length of array
unordered map -> TC = O(N^2) - worst case, best case = O(N)

map<int,int> mpp;

for(i=0;i<n;i++){
    mpp[arr[i]]++;
}

for(auto it: mpp){
    if(it.second == 1) return it.first;
} - will run for N/2 + 1 because every number is present 2 times and one number is present 1 time. - O(N/2 + 1)

Total TC = O(Nlog(N/2 + 1)) + O(N/2 + 1)
SC = O(N/2 + 1)

Optimal Solution ->

XOR operation

xor = 0;
for(int i=0;i<n;i++){
    xor = xor ^ arr[i];
}
return xor;

because all elements that appear twice will give 0 and then the element that appears once will return itself after xoring.

TC = O(N), SC = O(1)

*/

int getSingleElement(int arr[], int n){
    int xor1 = 0;
    for(int i=0;i<n;i++){
        xor1 = xor1 ^ arr[i];
    }
    return xor1;
}

/*
Longest Subarray with sum k, only positive numbers in the array

subarray - contiguous part of the array

{1,2,3,1,1,1,1,4,2,3} - we need to return the length of the subarray, whose elements add upto k = 3.
ans = 3 {1,1,1}, where other possible subarrays are -> {1,2}, {3}

Brute Force Solution =>

Generating all subarrays and check their sum

-> we start from an element and then keep on adding the next elements till the end of the array in iterations.

we keep a pointer 'i' on one initial element and another pointer j will start from i till the end of the array.

subarrays will be formed - (i,j)

length = 0;
for(i=0;i<n;i++){
    for(j=i;j<n;j++){
        sum = 0;
        for(k=i;k<=j;k++){
            sum += arr[k];
            if(sum == cummulative) length = max(length,j-i+1);
        }
    }
}
return length;

TC = O(N^3) nearly, no extra space we are using.

optimizing brute force method ->

we can just add the sub array elements while iterating through the it with j pointer, no need for an extra loop.

for(i=0;i<n;i++){
    sum = 0;
    for(j=i;j<n;j++){
        sum += arr[j];           
        if(sum == cummulative) length = max(length,j-i+1);
    }
}

TC can be dragged down to nearly O(N^2) with this approach.

Better Solution ->

Hashing =>

[-,-,-,-,-,-,-,-]

If there exists a subarray with sum k as one of the - as the last element.

sum = k, we can calculate the prefix sum for every element = x, so the we can get the sum except for the subarray as x-k.

suppose till index 5, sum (prefix) is x.
if we need to see there is x-k sum is there or not, we need to hash it.

we create a hashmap and hash the sum at each index.

sum = 0, length = 0

we iterate over the array, and calculate the prefix sum at each index and hash it.

whenever we find prefixsum = required sum, we modify the length as that subarray.

and if we get another subarray with sum k, then we check from the previous hash if the corresponding sum - k is present or not and if it's length is greater than current length then modify else leave it as it is.

This approach has an edge case where if we have 0s, then the sum index can get updated.

This same approach is the better solution if the array contains positives only and it is the best solution if the array contains positives,zeros and negatives.

TC = O(N*1) - best case and O(N^2) in the worst case if we use unordered_map. O(NlogM) if we use ordered_map without collisions.

we are storing prefix sum for every index
SC = O(N) - worst case if every index contains a prefixsum.

For Positives and zeros Optimal Solution ->
2 pointer approach

we start from the beginning of the array, and move towards the end and calculate the sum, if it equals the sum k, then update the length. if it exceeds the sum then we move the behind pointer so that the sum decreases.likewise we continue till end.


*/

int longestSubArrayWithSumK(int arr[], int n, int k){
    map<int,int> preSumMap;
    int sum = 0;
    int maxLen = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        if(sum == k){
            maxLen = max(maxLen,i+1);
        }
        int rem = sum - k;
        if(preSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum) == preSumMap.end()){
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int longestSubArrayWithSumKOptimalForPositive(int arr[], int n, int k){
    int left = 0, right = 0;
    int sum = arr[0];
    int maxLen = 0;
    while(right < n){
        while(left <= right && sum > k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxLen;
}
// TC = O(2N) at worst case, bexause the inner while loop is not running every turn, it will only run once sum > k which doesn't happen at every turn. SC = O(1) , no extra space.

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N1,N2;
        cin >> N1 >> N2;
        int arr[N1]; int arr2[N2];
        for(int i=0;i<N1;i++) cin >> arr[i]; 
        for(int i=0;i<N2;i++) cin >> arr2[i]; 
        cout << longestSubArrayWithSumK(arr,N1,8);
        // moveZerosToTheEndOptimal(arr,N);
        // vector<int> unionArray = arrayIntersectionOptimal(arr1,N1,arr2,N2);
        // for(int i=0;i<N;i++) cout << arr[i] << " ";
        // for(auto it: unionArray) cout << it << " ";
        cout << "\n";
    }
    return 0;
}

/*
if we are defining an array of size n inside main(), max size can be 10^6

array can contain a single data type => int, char, double, string, pair<int,int>..

int arr[6]; by default there will be garbage values in the array.

if we define it outside of int main() globally, it will be initilized with 0 for every element. max_size can be 10^7

*/