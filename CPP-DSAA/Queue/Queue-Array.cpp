#include<bits/stdc++.h>
using namespace std;
class Queue
{
    private:
        int front;
        int rear;
        int size;
        int *Q;
        public:
        Queue()
        {
            front=rear=-1;
            size=10;
            Q=new int[size];
        }
        Queue(int size)
        {
            front=rear=-1;
            this->size=size;
            Q=new int[this->size];
        }
        void enqueue(int x)
        {
            if(rear==size-1)
            {
                cout<<"Queue Full"<<endl;
                return ;
            }
            rear++;
            Q[rear]=x;
        }
        int dequeue()
        {
            if(front==rear)
            {
                cout<<"Queue is empty"<<endl;

            }else{
                int x=-1;
                x=Q[front+1];
                front++;
                return x;
            }
        }
        void display()
        {
            for(int i=front+1;i<=rear;i++)
            {
                cout<<Q[i]<<" ";
            }
            cout<<endl;
        }
};
int main()
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    cout<<q.dequeue()<<endl;
    q.display();
    return 0;
}