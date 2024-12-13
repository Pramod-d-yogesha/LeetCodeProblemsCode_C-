#include<iostream>
using namespace std;
class Stack
{
    int top;
    int* s;
    int capacity;
    public:
    Stack(int size)
    {
        s=new int[size];
        capacity=size;
        top=-1;
    }
    void push(int val)
    {
        if(top==capacity-1)
        
        {
            cout<<"Stack is full"<<endl;
        }
        else
        {
            s[++top]=val;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        else
        {
            cout<<"the deleted element is - "<<s[top--]<<endl;
        }
    }
    void display()
    {
        if(top==-1) {cout<<"stack is empty"<<endl;}
        else
        {
        cout<<"the elements are "<<endl;
        for(int i=top;i>=0;i--)
        {
            cout<<"stack [ "<<i<<"] = "<<s[i]<<endl;
        }
        }
    }
};
int main()
{
    Stack s(5);
    s.push(10);
    s.display();
    s.push(20);
    s.display();
    s.push(30);
    s.display();
    s.push(40);
    s.display();
    s.push(50);
    s.display();
    s.push(60);
    s.display();
    s.push(70);
    s.display();
    s.push(80);
    s.display();
    s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
        s.pop();
        s.display();
         s.push(10);
    s.display();
    s.push(20);
    s.display();
    s.push(30);
    s.display();
    s.push(40);
    s.display();
    s.push(50);
    s.display();
    s.push(60);
    s.display();
    
    return 0;
}
