#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr {
private:
    T* q_array;
    size_t q_capacity;
    size_t q_size;
    size_t q_front;
    size_t q_back;

public:
    // Constructor
    queueArr(size_t capacity = 10) {
        q_capacity = capacity;
        q_array = new T[q_capacity];
        q_size = 0;
        q_front = 0;
        q_back = q_capacity - 1;
    }

    // Destructor
    ~queueArr() {
        delete[] q_array;
    }

    // Copy Constructor
    queueArr(const queueArr<T>& other) {
        q_capacity = other.q_capacity;
        q_size = other.q_size;
        q_front = other.q_front;
        q_back = other.q_back;
        q_array = new T[q_capacity];

        for (size_t i = 0; i < q_capacity; i++) {
            q_array[i] = other.q_array[i];
        }
    }

    // Assignment Operator
    queueArr<T>& operator=(const queueArr<T>& other) {
        if (this != &other) {
            delete[] q_array;

            q_capacity = other.q_capacity;
            q_size = other.q_size;
            q_front = other.q_front;
            q_back = other.q_back;
            q_array = new T[q_capacity];

            for (size_t i = 0; i < q_capacity; i++) {
                q_array[i] = other.q_array[i];
            }
        }
        return *this;
    }

    bool empty() const {
        return q_size == 0;
    }

    bool full() const {
        return q_size == q_capacity;
    }

    void Clear() {
        q_size = 0;
        q_front = 0;
        q_back = q_capacity - 1;
    }

    T Front() {
        if (empty()) {
            std::cout << "Queue is empty.\n" << std::endl;
            return T(); // return default value of T
        }
        return q_array[q_front];
    }

    T Back() {
        if (empty()) {
            std::cout << "Queue is empty.\n" << std::endl;
            return T(); // return default value of T
        }
        return q_array[q_back];
    }

    size_t size() const {
        return q_size;
    }

    void Enqueue(const T& value) {
        if (full()) {
            std::cout << "Queue is full." << std::endl;
            return;
        }

        q_back = (q_back + 1) % q_capacity;
        q_array[q_back] = value;
        q_size++;
    }

    void Dequeue() {
        if (empty()) {
            std::cout << "Queue is empty." << std::endl;
            return;
        }

        q_front = (q_front + 1) % q_capacity;
        q_size--;
    }
};

#endif