#include <bits/stdc++.h>

class Stack {
private:
    std::vector<int> stack;

public:
    Stack();
    ~Stack();

    // Adds an element to the top of the stack
    void push(int val);

    // Removes the top element from the stack
    void pop();

    // Returns top of the element without removing it
    int peek();

    // Checks if the stack is empty
    bool isEmpty();

    // Returns the number of elements in the stack
    int size();

    // Displays all elements in the stack
    void display();
};

Stack::Stack() {}

Stack::~Stack() {}

void Stack::push(int val) {
    stack.push_back(val);
}

void Stack::pop() {
    if (isEmpty()) {
        return;
    }
    stack.pop_back();
}

int Stack::peek() {
    return stack.back();
}

bool Stack::isEmpty() {
    return (stack.size() == 0);
}

int Stack::size() {
    return (stack.size());
}

void Stack::display() {
    if (stack.empty()) {
        std::cout << "Stack is empty.\n";
        return;
    }

    std::cout << "Stack elements: ";

    for (int i=0; i < stack.size(); i++) {
        std::cout << stack[i];

        if (i < stack.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "\n";
}

int main() {
    Stack stack;

    stack.push(2);
    stack.push(5);
    stack.push(4);
    stack.push(10);
    stack.push(11);
    stack.push(3);
    stack.push(6);
    stack.pop();
    stack.display();
    return 0;
}