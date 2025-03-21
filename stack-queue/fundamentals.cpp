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

// TC - O(N),  SC - O(2N)
class StackQueue {
private:
    stack<int> st1,st2;

public:
    StackQueue() {
    }
    
    void push(int x) {
        while(!st1.empty()) {
            st2.push(st1.top());
            st1.pop();
        }

        st1.push(x);

        while(!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }
    
    int pop() {
        if(st1.empty()) {
            cout << "Stack is empty";
            return -1;
        }

        int topEle = st1.top();
        st1.pop();

        return topEle;
    }
    
    int peek() {
        if(st1.empty()) {
            cout << "Stack is empty";
            return -1;
        }

        return st1.top();
    }
    
    bool isEmpty() {
        return st1.empty();
    }
};

// TC - O(1),  SC - O(2N)
class StackQueue2 {
private:
    stack<int> input, output;

public:
    StackQueue2() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if(output.empty()) {
            cout << "Queue is empty, can't pop." << endl;
            return -1;
        }

        int x = output.top();
        output.pop();
        return x;
    }
    
    int peek() {
        if(output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        if(output.empty()) {
            cout << "Queue is empty, can't peek." << endl;
            return -1;
        }

        return output.top();
    }
    
    bool isEmpty() {
        return input.empty() && output.empty();
    }
};

bool isMatched(char open, char close) {
    if ((open == '(' && close == ')') || (open == '{' && close == '}') ||
        (open == '[' && close == ']')) {
        return true;
    }

    return false;
}

bool isValid(string str) {
    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            st.push(str[i]);
        } else {
            if (st.empty()) return false;

            char ch = st.top();
            st.pop();

            if (!isMatched(ch, str[i])) {
                return false;
            }
        }
    }
    return st.empty();
    // TC, SC = O(N)
}

struct Node {
    int val;
    Node* next;
    Node(int d) {
        val = d;
        next = NULL;
    }
};

class LinkedListStack {
// O(1) for push, pop, size, isEmpty, peek operation TC
// SC = O(N)
private:
    Node* head;
    int size;
public:
    LinkedListStack() {
        head = NULL;
        size = 0;
    }
    
    void push(int x) {
        Node* element = new Node(x);
        element->next = head;
        head = element;
        size++;
    }
    
    int pop() {
        if(head == NULL) return -1;

        int value = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;

        return value;
    }
    
    int top() {
        if(head == NULL) return -1;

        return head->val;
    }
    
    bool isEmpty() {
        return size == 0;
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