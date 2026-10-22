#include <iostream>
#include <string>

class Job {
private:
    int id;
    std::string user;
    int pages;

public:
    Job() {
        id = 0;
        user = "";
        pages = 0;
    }

    Job(int jobID, std::string u, int p) {
        id = jobID;
        user = u;
        pages = p;
    }

    void display() const {
        std::cout << "Job ID: " << id << ", User: " << user << ", Pages: " << pages << std::endl;
    }
};

class Printer {
private:
    static const int capacity = 10;
    Job queue[capacity];
    int front;
    int rear;
    int count;

public:
    Printer() {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isFull() const {
        return count == capacity;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void addJob(Job newJob) {
        if (isFull()) {
            std::cout << "Printer queue is full. Cannot add new job." << std::endl;
            return;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = newJob;
        count++;
        std::cout << "Job added to the printer queue.\n" << std::endl;
    }

    void processJobs() {
        std::cout << "\nProcessing Jobs:\n" << std::endl;
        while (!isEmpty()) {
            std::cout << "Now printing....." << std::endl;
            queue[front].display();
            front = (front + 1) % capacity; // this moves the front index circularly
            count--;
            std::cout << std::endl;
        }
    }

    void showQueue() const {
        if (isEmpty()) {
            std::cout << "Printer queue is empty." << std::endl;
            return;
        }

        std::cout << "\nJobs in the printer queue:" << std::endl;
        int index = front;
        for (int i = 0; i < count; i++) {
            queue[index].display();
            index = (index + 1) % capacity; // this moves the index circularly
        }
        std::cout << std::endl;
    }
};

int main() {
    Printer printer;
    int numberOfJobs;

    std::cout << "Enter the number of jobs to add to the printer queue: ";
    std::cin >> numberOfJobs;
    std::cout << std::endl;

    for (int i = 0; i < numberOfJobs; i++) {
        int numPages;
        std::string name;

        std::cout << "Enter User Name: " << (i + 1) << " ";
        std::cin >> name;
        std::cout << "Enter Number of Pages: " << (i + 1) << " ";
        std::cin >> numPages;

        Job newJob(i + 1, name, numPages);
        printer.addJob(newJob);
    }

    // Show the jobs in the queue
    printer.showQueue();

    // Process the jobs in the queue
    printer.processJobs();

    // Show the jobs in the queue after processing
    printer.showQueue();

    return 0;
}