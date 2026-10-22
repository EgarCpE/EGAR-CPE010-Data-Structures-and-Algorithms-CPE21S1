#include <iostream>
#include "BST_SUPPLE.h"

int main() {
    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    std::cout << "PreOrder: " << "\n";
    tree.preOrder();
    std::cout << "\n";

    std::cout << "InOrder: " << "\n";
    tree.inOrder();
    std::cout << "\n";

    std::cout << "PostOrder: " << "\n";
    tree.postOrder();
    std::cout << "\n";

    return 0;
}