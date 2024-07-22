#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
void f(){
    if(cnt == 3) return;
    cout << cnt << endl;
    cnt++;
    f();
}

void printName(int i,int n){
    if(i>n) return;
    cout << "Ankit" << endl;
    printName(i+1,n);
} // TC = O(N), SC = O(N) 
// stack space is considered for recursion, internally the computer will use the stack space for storing the non-complete function calls.

void print1toN(int i, int n){
    if(i>n) return;
    cout << i << " ";
    print1toN(i+1,n);
}

void printNto1(int i){
    if(i<1) return;
    cout << i << " ";
    printNto1(i-1);
}

void print1toNBacktrack(int i){
    if(i<1) return;
    print1toNBacktrack(i-1);
    cout << i << " ";
}

void printNto1Backtrack(int i,int n){
    if(i>n) return;
    printNto1Backtrack(i+1,n);
    cout << i << " ";
}

int sumOfFirstNNumbersParameterised(int sum,int n){
    if(n == 0) return sum;
    sumOfFirstNNumbersParameterised(sum+n,n-1);
}

int sumOfFirstNNumbersFunctional(int n){
    if(n == 0) return 0;
    return n + sumOfFirstNNumbersFunctional(n-1);
}

int factorialOfN(int n){
    if(n < 2) return 1;
    return n * factorialOfN(n-1);
    // TC = O(N), SC = O(N) - auxillary space - stack space
}

void reverseArrayTwoPointer(int arr[],int l, int r){
    // using for loop -> one pointer on first element and one pointer on last element and swap, then we move towards the middle of the array
    if( l >= r) return;
    swap(arr[l],arr[r]);
    reverseArrayTwoPointer(arr,l+1,r-1);
}

void reverseArrayOneVariable(int arr[], int i, int n){
    if(i >= n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverseArrayOneVariable(arr,i+1,n);
}
// arrays are passed by reference, so we don't need to retrun the array. The changes made will be reflected.

string checkIfPalindrome(string &str, int i){
    if(i>=str.size()/2) return "true";
    if(str[i] != str[str.size()-i-1]) return "false";
    return checkIfPalindrome(str,i+1);
}
// TC -> O(N/2) we are iterating till N/2. SC -> O(N/2) auxilliary stack space is used.

int fibonacciSequence(int n){
    if(n <= 1) return n;
    return fibonacciSequence(n-1) + fibonacciSequence(n-2);
}

// TC -> O(2^n) exponential TC,nearly. because for each recursion we are making nearly 2 recursion calls. n = 2, n-1 = 2 ... 2^n

void fibonacciSequenceWithFor(int n){
    int n1 = 0,n2 = 1;
    int n3;
    cout << n1 << " " << n2 << " ";
    for(int i=2;i<=n;i++){
        n3 = n1 + n2;
        cout << n3 << " ";
        n1 = n2; n2 = n3;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int N;
        cin >> N;
        // string str;
        // cin >> str;
        /*
        int arr[N];
        for(int i=0;i<N;i++){
            cin >> arr[i];
        }
        // reverseArrayTwoPointer(arr,0,N-1);
        reverseArrayOneVariable(arr,0,N);
        for(int i=0;i<N;i++){
            cout << arr[i] << " ";
        }
        */
        // cout << checkIfPalindrome(str,0);
        cout << fibonacciSequence(N);
        // fibonacciSequenceWithFor(10);
        cout << "\n";
    }
    return 0;
}

/* 

When a function calls itself until a certain condition is met -> recursion
and we need to specify a certain condition, otherwise the function will keep on calling itself and eventually we will get segmentation fault / stack overflow error.
since the function calls are waiting in the memory for the called function to be completed. so they keep on getting stacked in the memory and eventually run out of memory.

segmentation fault / stack overflow error -> numerous function calls are waiting in the memory due to recursion.

In order to prevent stack overflow -> we need to specify a base condition for the function call to exit.

recursion tree ->

f() cnt = 0 -> f() cnt = 1 -> f() cnt = 2 -> f() cnt = 3 return
base condition met, now the function calls will get completed.

backtracking -> we perform the task of printing (here) after the function calls. so when the base condition is met, the function returns and then we print and return the function call to the previous function call.

 */

/* 

Reverse an array ->

using two pointers =>

f(l,r) {
    if(l>=r) return;
    swap(arr[l],att[r]);
    f(l+1,r-1);
}

using a single pointer/ variable =>

f(i) {
    if(i >= n/2) return;
    swap(arr[i],arr[n-i-1]);
    f(i+1);
}

recursion => is to identify which task recursion needs to do, here swapping elements.

*/

/* 

Check If Palindrome

f(str,i){
    int length = str.length();
    if(i >= length/2) return "True";
    if(str[i] != str[length-i-1) return "False";
    f(str,i+1);
}

*/

/*

Multiple Recursion calls

Fibonacci Series

0 1 1 2 3 5 8 ...
first 2 fibonacci numbers are - 0 and 1
then next fibonacci number = sum of previous two fibonacci numbers

f(n) = f(n-1) + f(n-2);

first the f(n-1) recursion will happen and then f(n-2) will happen. They don't performed simultaneously.one after the other

In case of multiple recursion calls, one recursion call happens at a time. One recursion call will go then the result come back and then  the next recursion call will happen.

*/