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

class ArrayQueue {
private:
    int* arr;
    int start, end;
    int currentSize, maxSize;

public:
    ArrayQueue() {
        arr = new int[10];
        start = -1;
        end = -1;
        currentSize = 0;
        maxSize = 10;
    }
    
    void push(int x) {
        if(currentSize == maxSize) {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }

        // If the queue is empty, initialize start and end
        if(end == -1) {
            start = 0;
            end = 0;
        } else {
            // Circular increment of end
            end = (end + 1) % maxSize;
        }

        arr[end] = x;
        currentSize++;
    }
    
    int pop() {
        if(start == -1) {
            cout << "Queue Empty\nExiting..." << endl;
            exit(1);
        }

        int popped = arr[start];

        if(currentSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % maxSize;
        }

        currentSize--;
        return popped;
    }
    
    int peek() {
        if(start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    
    bool isEmpty() {
        return (currentSize == 0);
    }
};

class QueueStack {
    queue<int> q;
    
public:
    QueueStack() {
    }
    
    void push(int x) { // O(n)
        int size = q.size();
        q.push(x);

        // Move elements before new element to back
        for(int i = 0; i<size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
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