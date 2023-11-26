#include<iostream>
#include<vector>

template <typename T>
class Queue {
private:
    int size;
    int front;
    int rear;
    T *Q;

public:
    Queue(int size) {
        this->size = size;
        front = rear = 0;
        Q = new T[size];
    }

    ~Queue() {
        delete[] Q;
    }

    void enqueue(T x) {
        if ((rear + 1) % size == front) {
            std::cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % size;
        Q[rear] = x;
    }

    T dequeue() {
        if (front == rear) {
            std::cout << "Queue is empty\n";
            return T();  // Return default-constructed value for T (0 for numeric types, nullptr for pointers, etc.)
        }
        front = (front + 1) % size;
        return Q[front];
    }

    void display() {
        if (front == rear) {
            std::cout << "Queue is empty\n";
            return;
        }
        int i = (front + 1) % size;
        do {
            std::cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        std::cout << std::endl;
    }
};

int main() {
    Queue<int> intQueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.display();

    std::cout << intQueue.dequeue() << std::endl;

    intQueue.enqueue(70);
    intQueue.display();

    // Example with a string queue
    Queue<std::string> strQueue(5);
    strQueue.enqueue("Hello");
    strQueue.enqueue("World");
    strQueue.display();

    std::cout << strQueue.dequeue() << std::endl;

    strQueue.display();

    return 0;
}
