#ifndef BST_SUPPLE
#define BST_SUPPLE

#include <iostream>

template <typename T>
class BinarySearchTree {
private:
    // Value stored in the current node
    T key;

    // Pointers to the left and right child subtrees
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

public:
    // Constructor
    BinarySearchTree(T value);

    // Destructor
    ~BinarySearchTree();

    // Inserts a new value into BST
    void insert(T value);

    // Traversal Methods:
    // Root -> Left -> Right
    void preOrder();

    // Left -> Root -> Right 
    void inOrder();

    // Left -> Right -> Root
    void postOrder();
};


// Constructor Implementation
template <typename T>
BinarySearchTree<T>::BinarySearchTree(T value) {
    key = value;
    left = nullptr;
    right = nullptr;
}

// Destructor 
template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {
    delete left;
    delete right;
}

// Insertion
template <typename T>
void BinarySearchTree<T>::insert(T value) {
    // If the value is smaller, place it into the left subtree
    if (value < key) {
        if (left == nullptr) {
            left = new BinarySearchTree<T>(value); 
        } else {
            left->insert(value);                   
        }
    } 
    // If the value is larger, place it into the right subtree
    else if (value > key) {
        if (right == nullptr) {
            right = new BinarySearchTree<T>(value); 
        } else {
            right->insert(value);                    
        }
    }
   
}

// Pre order
template <typename T>
void BinarySearchTree<T>::preOrder() {
    // Process current node first
    std::cout << key << " ";

    // Traverse left subtree
    if (left != nullptr) {
        left->preOrder();
    }

    // Traverse right subtree
    if (right != nullptr) {
        right->preOrder();
    }
}

// In order
template <typename T>
void BinarySearchTree<T>::inOrder() {
    // Traverse left subtree
    if (left != nullptr) {
        left->inOrder();
    }

    // Process current node
    std::cout << key << " ";

    // Traverse right subtree
    if (right != nullptr) {
        right->inOrder();
    }
}

// Post order 
template <typename T>
void BinarySearchTree<T>::postOrder() {
    // Traverse left subtree
    if (left != nullptr) {
        left->postOrder();
    }

    // Traverse right subtree
    if (right != nullptr) {
        right->postOrder();
    }

    
    std::cout << key << " ";
}

#endif 