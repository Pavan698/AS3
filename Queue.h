#ifndef QUEUE_H
#define QUEUE_H

class Queue {
public:
    // Constructor for the Queue class
    Queue();

    // Destructor for the Queue class
    ~Queue();

    // Enqueue a value to the end of the queue
    void enqueue(int value);

    // Dequeue the front element from the queue
    int dequeue();

    // Get the value of the front element without dequeuing it
    int front() const;

    // Check if the queue is empty
    bool isEmpty() const;

    // Get the number of elements in the queue
    int size() const;

private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* frontPtr; // Pointer to the front element of the queue
    Node* rearPtr;  // Pointer to the rear element of the queue
    int count;      // Count of elements in the queue
};

#endif // QUEUE_H
