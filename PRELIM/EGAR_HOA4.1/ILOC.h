#ifndef ILOC_H
#define ILOC_H

#include <iostream>
#include <string>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};


template <typename T>
Node<T>* topNode = nullptr;

// Push
template <typename T>
void push(T value) {
    Node<T>* newNode = new Node<T>;
    newNode->data = value;
    newNode->next = topNode<T>;
    topNode<T> = newNode;

    std::cout << "Push: " << value << std::endl;
}

// Pop
template <typename T>
T pop() {
    if (topNode<T> == nullptr) {
        std::cout << "Stack Underflow!\n";
        return T();
    }

    Node<T>* temp = topNode<T>;
    T value = temp->data;
    topNode<T> = temp->next;
    delete temp;

    std::cout << "Pop: " << value << std::endl;

    return value;
}

// isEmpty
template <typename T>
bool isEmpty() {
    return topNode<T> == nullptr;
}

// clear the stack
template <typename T>
void clearStack() {
    while (!isEmpty<T>()) {
        pop<T>();
    }
}

// BALANCED SYMBOLS FUNCTION
bool isBalanced(const std::string& expression) {

    clearStack<char>(); // reset stack

    for (int i = 0; i < expression.length(); i++) {

        char ch = expression[i];

        // Opening symbols
        if (ch == '(' || ch == '[' || ch == '{') {
            push<char>(ch);
        }

        // Closing symbols
        else if (ch == ')' || ch == ']' || ch == '}') {

            if (isEmpty<char>()) {
                return false;
            }

            char open = pop<char>();

            if ((ch == ')' && open != '(') ||
                (ch == ']' && open != '[') ||
                (ch == '}' && open != '{')) {
                return false;
            }
        }
    }

    return isEmpty<char>();
}

#endif