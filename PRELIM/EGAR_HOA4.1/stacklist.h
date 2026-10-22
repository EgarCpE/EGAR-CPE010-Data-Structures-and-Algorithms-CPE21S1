#ifndef STACK_LIST_H
#define STACK_LIST_H

// class node that contains data and the next
template < typename T >
class Node{
    public:
    T data; //value that we need to store
    Node* next; // pointer to the next node

};

//global pointer
template <typename T>
Node<T> *head = nullptr;

//operations for creating the stack

// push
template <typename T>
void push(T newData){
    //create a new node and assign the newData
    Node<T>* newNode = new Node<T>;
    newNode->data = newData;

    // new node points to current top, then becomes the new top

    newNode -> next = head<T>;
    head<T> = newNode;

}

// pop
template <typename T>
T pop(){
    // checks if the stack is empty
    if (head<T> == nullptr){
        std::cout << "Stack overflow. "<< std::endl;
    }

    // save the current top node
    Node<T>* temp = head<T>;
    // store data
    T tempVAL = temp->data;
    // move the head to the mext node
    head<T> = head<T> -> next;
    // free the removed node
    delete temp;
    // return the removed value
    return tempVAL;
}

// top
template<typename T>
void Top(){
    // error catching
    if(head<T> == nullptr){
        std::cout<<"Stack Underflow "<< std::endl;
        return;
    }
    //display
    std::cout<<"Top of stack: "<< head<T>->data <<std:: endl;
}

// isEmpty
template<typename T>
bool isEmpty(){
    return head <T> == nullptr;
}

// display all
template <typename T>
void displayAll() {
    if(isEmpty<T>()) {
        std::cout << "stack is empty \n";
        return;
    }

    std::cout << " Stack contents " ;
    Node<T>* temp = head<T>;
    while (temp != nullptr){
        std::cout << "\n | "<< temp->data <<" | ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif