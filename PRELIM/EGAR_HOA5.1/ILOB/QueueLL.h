#ifndef QUEUELL_H
#define QUEUELL_H

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
void enqueue(Node<T>** Front, Node<T>** Back, T val) {
    Node<T>* newNode = new Node<T>();
    newNode->data = val;
    newNode->next = nullptr;

    if (*Front == nullptr) {
        *Front = newNode;
        *Back = newNode;
    } else {
        (*Back)->next = newNode;
        *Back = newNode;
    }
}

template <typename T>
T dequeue(Node<T>** Front, Node<T>** Back) {
    if (*Front == nullptr) {
        std::cout << "Queue is empty\n";
        return T();
    }

    Node<T>* deleteNode = *Front;
    T deletedData = deleteNode->data;

    *Front = (*Front)->next;
    if (*Front == nullptr) {
        *Back = nullptr;
    }

    delete deleteNode;
    return deletedData;
}

template <typename T>
void display(Node<T>* Front) {
    if (Front == nullptr) {
        std::cout << "Queue is empty\n";
        return;
    }

    Node<T>* current = Front;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
T FrontValue(Node<T>* Front) {
    if (Front == nullptr) {
        std::cout << "Queue is empty\n";
        return T();
    }
    return Front->data;
}

#endif