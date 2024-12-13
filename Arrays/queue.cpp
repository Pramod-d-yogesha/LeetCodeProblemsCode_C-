#include <iostream>
using namespace std;
class Queue
{
    int front;
    int rear;
    int* queue;
    int capacity;
    public:
    Queue(int size)
    {
        queue=new int[size];
        front=0;
        rear=0;
        capacity=size;
    }
    void push(int val)
    {
        if(rear==capacity)
        {
            cout<<"queue is full"<<endl;
            
        }
        else
        {
        queue[rear++]=val;
        }
    }
    void pop()
    {
        if(front>=rear)
        {
            cout<<"Queue is empty"<<endl;
        }
        else
        {
            cout<<"the deleted element is - "<<queue[front++]<<endl;
        }
        if(front==capacity) {front=0;rear=0;}
    }
    void display()
    {
        cout<<"The queue elements are "<<endl;
        for(int i=front;i<rear;i++)
        {
            cout<<"Queue[ "<<i<<" ] = "<<queue[i]<<endl;
        }
    }
    
};
int main()
{
    Queue q(5);
    q.push(10);
    q.display();
    q.push(20);
    q.display();
    q.push(30);
    q.display();
    q.push(40);
    q.display();
    q.push(50);
    q.display();
    q.push(60);
    q.display();
    q.push(70);
    q.display();
    q.push(80);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.push(10);
    q.display();
    q.push(20);
    q.display();
    q.push(30);
    q.display();
    q.push(40);
    q.display();
    q.push(50);
    q.display();
    q.push(60);
    q.display();
    q.push(70);
    q.display();
    q.push(80);
    
    
    
    
    return 0;
}
