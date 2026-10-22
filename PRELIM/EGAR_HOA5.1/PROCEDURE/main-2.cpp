#include <iostream>
#include <string>

// create a class called job
class Job{
    private:
        // Id number for the job
        int id;
        // name of the user who submitted the job
        std::string name;
        //number of pages for the printer
        int pages;

    public:
        // constructor 
        Job() {
            id = 0;
            name = "";
            pages = 0;
        }

        // constructor for the job class
        Job(int i, std::string n, int p) {
            id = i;
            name = n;
            pages = p;
        }

        // function to print out the job's details
        void display() {
            std::cout << "Job ID: " << id << ", User: " << name << ", Pages: " << pages << std::endl;
        }
};

class Printer{
    private:
        const int capacity = 10;
        Job jobs[10]; 
        int front;
        int rear;
        int count;


    public:
        // create a queue to hold the jobs
        Printer() {
            front = 0;
            rear = -1;
            count = 0;
        }
        // checks if the queue is full 
        bool isFull() {
            if (count == capacity) {
                return true;
            }
            return false;
        }
        // Check if queue is empty
        bool isEmpty() {
            if (count == 0) {
                return true;
            }
            return false;
        }
        // function to add a job to the queue
        void addJob(Job newJob){
            if (isFull()) {
                std::cout << "Printer queue is full. Cannot add new job." << std::endl;
                return;
            }
            rear = (rear + 1) % capacity; // this moves the rear index circularly
            jobs[rear] = newJob;
            count++;
            std::cout << "Job added to the printer queue." << std::endl;
        }
        // function to process the job from the queue
        void processJob() {
            std::cout << "\nProcessing job:\n" << std::endl;

            while (!isEmpty()) {
                std::cout << "Now printing....." << std::endl;
                jobs[front].display();
                front = (front + 1) % capacity; // this moves the front index circularly
                count--;
                std::cout << std::endl;
            }
        }
        // shows the waiting line for the jobs awaiting to be processed
        void showQueue() {
            if (isEmpty()) {
                std::cout << "\nPrinter queue is empty." << std::endl;
                return;
            }


            std::cout << "\nJobs in the printer queue:" << std::endl;
            int index = front;
            for (int i = 0; i < count; i++) {
                jobs[index].display();
                index = (index + 1) % capacity; // this moves the index circularly
            }
            std::cout << std::endl;
        }
};
int main(){
    //creating of objects for the printer and jobs
    Printer printer;


    int numberOfJobs;
    std::cout << "Enter the number of jobs to add to the printer queue: ";
    std::cin >> numberOfJobs;

    std::cout << std::endl;


    for (int i = 0; i < numberOfJobs; i++) {
        int numPages;
        std::string name;


        std::cout << "Enter User Name: " << (i + 1) << ": ";
        std::cin >> name;
        std::cout << "Enter Number of Pages: " << (i + 1) << ": ";
        std::cin >> numPages;


        Job newJob(i + 1, name, numPages);
        printer.addJob(newJob);
        std::cout << std::endl;
    }


    // Show the jobs in the queue
    printer.showQueue();

    // Process the jobs in the queue
    printer.processJob();

    // Show the jobs in the queue after processing
    printer.showQueue();


    return 0;
}