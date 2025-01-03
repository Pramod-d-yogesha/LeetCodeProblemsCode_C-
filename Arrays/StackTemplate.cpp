#include <iostream>
using namespace std;
template<class T>class Stack
{
    T* stackPtr;
    int top;
    int capacity;
   public:
   Stack(int x=5)
   {
       stackPtr=new T[x];
       capacity=x;
       top=-1;
   }
   void push(int val)
   {
       if(isFull())
       {
           cout<<"Stack is full"<<endl;
           return;
       }
       stackPtr[++top]=val;
   }
   void pop()
   {
        if(isEmpty())
       {
           cout<<"Stack is empty"<<endl;
           return;
       }
       cout<<"The deleted element is = "<<stackPtr[top--]<<endl;
   }
   void display()
   {
       cout<<"The stack contains : "<<endl;
       for(int i=top;i>=0;i--)
       {
           cout<<stackPtr[i]<<" ";
       }
       cout<<endl;
   }
   bool isEmpty()
   {
       return (top == -1);
   }
   bool isFull()
   {
       return (top == capacity-1);
   }
   void Capacity()
   {
       cout<<"Stack capacity is "<<capacity<<endl;
   }
};
int main()
{
    Stack<int> sInt;
  
    sInt.push(10);
    sInt.push(20);
    sInt.push(30);
    sInt.push(40);
    sInt.push(50);
    sInt.push(60);
    sInt.push(70);
    sInt.push(80);
    sInt.push(90);
    sInt.push(10);
    sInt.display();
    sInt.pop();
    sInt.display();
  
    Stack<char> sChar;
  
    sChar.push('p');
    sChar.push('r');
    sChar.push('a');
    sChar.push('m');
    sChar.push('o');
    sChar.display();
    sChar.Capacity();
    return 0;
}
