#include "Queue.h"
#include <stdexcept> // Include the <stdexcept> header for std::runtime_error

// Constructor for the Queue class
Queue::Queue() : frontPtr(nullptr), rearPtr(nullptr), count(0) {}

// Destructor for the Queue class
Queue::~Queue() {
    // Dequeue all elements until the queue is empty to prevent memory leaks
    while (!isEmpty()) {
        dequeue();
    }
}

// Enqueue a value to the end of the queue
void Queue::enqueue(int value) {
    Node* newNode = new Node(value); // Create a new node with the given value
    if (isEmpty()) {
        frontPtr = newNode; // If the queue is empty, the new node is both the front and rear
        rearPtr = newNode;
    } else {
        rearPtr->next = newNode; // Otherwise, set the next of the current rear node to the new node
        rearPtr = newNode; // Update the rear pointer to the new node
    }
    count++; // Increment the count of elements in the queue
}

// Dequeue the front element from the queue
int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty"); // Throw a runtime error if the queue is empty
    }
    Node* temp = frontPtr; // Store the front node in a temporary pointer
    int value = temp->data; // Retrieve the value from the front node
    frontPtr = frontPtr->next; // Move the front pointer to the next node
    delete temp; // Delete the old front node to free memory
    count--; // Decrement the count of elements in the queue
    return value; // Return the dequeued value
}

// Get the value of the front element without dequeuing it
int Queue::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty"); // Throw a runtime error if the queue is empty
    }
    return frontPtr->data; // Return the value of the front node
}

// Check if the queue is empty
bool Queue::isEmpty() const {
    return count == 0; // The queue is empty if the count is zero
}

// Get the number of elements in the queue
int Queue::size() const {
    return count; // Return the count of elements in the queue
}
