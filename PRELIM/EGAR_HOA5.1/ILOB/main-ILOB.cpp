#include <iostream>
#include "QueueLL.h"

int main() {
    Node<char>* Front = nullptr;
    Node<char>* Back = nullptr;

    enqueue(&Front, &Back, '3');
    std::cout << Front->data << " " << Back->data << std::endl;

    enqueue(&Front, &Back, 'A');
    std::cout << Front->data << " " << Back->data << std::endl;

    dequeue(&Front, &Back);
    std::cout << Front->data << " " << Back->data << std::endl;

    std::cout << "Queue list: ";
    display(Front);

    std::cout << "Front value: " << FrontValue(Front) << std::endl;

    return 0;
}