#include<bits/stdc++.h>
using namespace std;

class ArrayStack {
private:
    int* stackArray;
    int capacity;
    int topIndex;

public:
    // Constructor
    ArrayStack(int size = 1000) {
        capacity = size;
        stackArray = new int[capacity];
        topIndex = -1;
    }

    ~ArrayStack() {
        delete[] stackArray;
    }
    
    void push(int x) {
        if(topIndex >= capacity - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        stackArray[++topIndex] = x;
    }
    
    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }
    
    int top() {
        if(isEmpty()) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }
    
    bool isEmpty() {
        return topIndex == -1;
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