#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Queue
{
private:
    int front;
    int rear;
    int size;
    T *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new T[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new T[this->size];
    }

    void enqueue(T x)
    {
        if (rear == size - 1)
        {
            cout << "Queue Full" << endl;
            return;
        }
        rear++;
        Q[rear] = x;
    }

    T dequeue()
    {
        if (front == rear)
        {
            cout << "Queue is empty" << endl;
            return T(); // Return default-constructed value for T (0 for numeric types, nullptr for pointers, etc.)
        }
        else
        {
            T x = Q[front + 1];
            front++;
            return x;
        }
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
        {
            cout << Q[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue<int> intQueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);
    intQueue.display();
    cout << intQueue.dequeue() << endl;
    intQueue.display();

    // Example with a string queue
    Queue<string> strQueue(5);
    strQueue.enqueue("Hello");
    strQueue.enqueue("World");
    strQueue.display();
    cout << strQueue.dequeue() << endl;
    strQueue.display();

    return 0;
}
