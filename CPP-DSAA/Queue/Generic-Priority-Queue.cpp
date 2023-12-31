#include <iostream>

template <typename T>
struct Node {
    T data;
    int priority;
    Node* next;
};

template <typename T>
class PriorityQueue {
private:
    Node<T>* front;

public:
    PriorityQueue() : front(nullptr) {}

    void enqueue(T x, int priority) {
        Node<T>* newNode = new Node<T>;
        newNode->data = x;
        newNode->priority = priority;
        newNode->next = nullptr;

        if (front == nullptr || priority < front->priority) {
            newNode->next = front;
            front = newNode;
        } else {
            Node<T>* temp = front;
            while (temp->next != nullptr && temp->next->priority <= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    T dequeue() {
        if (front == nullptr) {
            std::cerr << "Priority Queue is empty" << std::endl;
            return T(); // Return default value for type T
        }

        Node<T>* temp = front;
        T x = temp->data;
        front = front->next;
        delete temp;
        return x;
    }

    void display() {
        Node<T>* temp = front;
        while (temp != nullptr) {
            std::cout << "(" << temp->data << ", " << temp->priority << ") ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ~PriorityQueue() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    PriorityQueue<int> pq;
    pq.enqueue(10, 2);
    pq.enqueue(20, 1);
    pq.enqueue(30, 3);
    pq.display();
    std::cout << pq.dequeue() <<std::endl;
    pq.display();

    return 0;
}
