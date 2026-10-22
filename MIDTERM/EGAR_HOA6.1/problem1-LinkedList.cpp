#include <iostream>
#include "nodes.h"
//problem1-LinkedList

int main() 
{
    int values[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int target = 18;
    int steps = 0;

    Node<int>* head = new_node(values[0]);
    Node<int>* curr = head;

    for (int i = 1; i < 10; i++) {
        curr->next = new_node(values[i]);
        curr = curr->next;
    }


    curr = head;

   
    while (curr != nullptr) {
        steps++;
        if (curr->data == target) {

            std::cout << std::endl;

            std::cout << "Numbers of Key Found: " << curr->data << std::endl;
            break;
        }
        curr = curr->next;
    }

    std::cout << std::endl;

    std::cout << "How many numbers are similar to the key: " << steps << std::endl;

    std::cout << std::endl;

    return 0;
}