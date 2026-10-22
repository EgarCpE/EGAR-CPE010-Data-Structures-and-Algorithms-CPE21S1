#include <iostream>
#include "nodes.h"
//problem2-Modi-sequencial

int countArray(int arr[], int size, int target) 
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            count++;
        }
    }
    return count;
}

int countLinkedList(Node<int>* head, int target) 
{
    int count = 0;
    Node<int>* current = head;

    while (current != nullptr) {
        if (current -> data == target) {
            count++;
        }
        current = current -> next;
    }
    return count;
}

int main() 
{
    int values[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int k = 18;


    Node<int>* head = new_node(values[0]);
    Node<int>* current = head;
    for (int i = 1; i < 10; i++) {
        current -> next = new_node(values[i]);
        current = current -> next;
    }

   
    int arrayResult = countArray(values, 10, k);
    int listResult = countLinkedList(head, k);

    std::cout << std::endl;

    std::cout << "Array count for key '" << k << "': " << arrayResult << std::endl;

    std::cout << std::endl;

    std::cout << "Linked List count for key '" << k << "': " << listResult << std::endl;

    std::cout << std::endl;

    return 0;
}