#include <iostream>
#include "bst.h"

int main() {
    BinarySearchTree<int> tree(20);

    tree.insert(30);
    tree.insert(70);
    tree.insert(50);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(15);

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