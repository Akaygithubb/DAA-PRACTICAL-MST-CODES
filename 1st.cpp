#include <iostream>
using namespace std;

// Template Stack class
template <typename T>
class Stack {
private:
    int maxSize;    // Maximum size of the stack
    int topIndex;   // Index of the top element
    T* arr;         // Dynamic array to store stack elements

public:
    // Constructor to initialize stack with a given size
    Stack(int size) {
        maxSize = size;
        arr = new T[maxSize];
        topIndex = -1; // Initializing topIndex to -1 indicates an empty stack
    }

    // Destructor to release allocated memory
    ~Stack() {
        delete[] arr;
    }

    // Method to check if the stack is empty
    bool isEmpty() const {
        return topIndex == -1;
    }

    // Method to check if the stack is full
    bool isFull() const {
        return topIndex == maxSize - 1;
    }

    // Method to push an element onto the stack
    void push(const T& element) {
        if (isFull()) {
            cout << "Stack is full. Cannot push " << element << "." << endl;
        } else {
            arr[++topIndex] = element;
            cout << "Pushed " << element << " onto the stack." << endl;
        }
    }

    // Method to pop an element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
        } else {
            cout << "Popped " << arr[topIndex--] << " from the stack." << endl;
        }
    }

    // Method to get the top element of the stack
    T top() const {
        if (isEmpty()) {
            cout << "Stack is empty. No top element." << endl;
            return T(); // Return default-constructed value if stack is empty
        } else {
            return arr[topIndex];
        }
    }
};

// Main function to test the Stack class
int main() {
    Stack<int> stack(5); // Creating a stack of integers with size 5

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Top element: " << stack.top() << endl; // Should display 30

    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl; // Should display 20

    stack.pop();
    stack.pop();

    stack.pop(); // Should display "Stack is empty. Cannot pop."

    return 0;
}
