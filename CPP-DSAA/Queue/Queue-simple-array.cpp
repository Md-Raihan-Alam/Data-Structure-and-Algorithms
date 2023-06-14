#include <iostream>

using namespace std;

const int MAX_SIZE = 100; // Maximum size of the queue

class Queue {
private:
    int arr[MAX_SIZE]; // Array to store queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element

public:
    Queue() {
        front = -1; // Initialize front index
        rear = -1; // Initialize rear index
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue element." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0; // If queue is empty, set front and rear to 0
        } else {
            rear++; // Increment rear index
        }

        arr[rear] = item; // Add the element to the rear of the queue
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue element." << endl;
            return;
        }

        if (front == rear) {
            front = rear = -1; // If queue has only one element, reset front and rear to -1
        } else {
            front++; // Increment front index
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
            return -1;
        }

        return arr[front];
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    queue.display(); // Output: Queue elements: 10 20 30

    queue.dequeue();

    queue.display(); // Output: Queue elements: 20 30

    cout << "Front element: " << queue.getFront() << endl; // Output: Front element: 20

    return 0;
}
