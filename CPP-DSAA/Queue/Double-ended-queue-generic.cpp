#include<iostream>
#include<vector>

template <typename T>
class Deque {
private:
    int size;
    int front;
    int rear;
    T *Q;

public:
    Deque(int size) {
        this->size = size;
        front = rear = -1;
        Q = new T[size];
    }

    ~Deque() {
        delete[] Q;
    }

    void insertFront(T x) {
        if ((front - 1 + size) % size == rear) {
            std::cout << "Deque is full\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            front = (front - 1 + size) % size;
        }
        Q[front] = x;
    }

    void insertRear(T x) {
        if ((rear + 1) % size == front) {
            std::cout << "Deque is full\n";
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }
        Q[rear] = x;
    }

    T deleteFront() {
        T x;
        if (front == -1) {
            std::cout << "Deque is empty\n";
            return T();  // Return default-constructed value for T (0 for numeric types, nullptr for pointers, etc.)
        }
        x = Q[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
        return x;
    }

    T deleteRear() {
        T x;
        if (front == -1) {
            std::cout << "Deque is empty\n";
            return T();
        }
        x = Q[rear];
        if (front == rear) {
            front = rear = -1;
        } else {
            rear = (rear - 1 + size) % size;
        }
        return x;
    }

    void display() {
        if (front == -1) {
            std::cout << "Deque is empty\n";
            return;
        }
        int i = front;
        do {
            std::cout << Q[i] << " ";
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        std::cout << std::endl;
    }
};

int main() {
    Deque<int> dq(5);

    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertRear(30);
    dq.display();

    dq.insertFront(5);
    dq.display();

    std::cout << dq.deleteFront() << std::endl;
    dq.display();

    std::cout << dq.deleteRear() << std::endl;
    dq.display();

    return 0;
}
