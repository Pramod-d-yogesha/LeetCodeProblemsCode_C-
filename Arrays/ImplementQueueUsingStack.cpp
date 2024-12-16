//implement queue functions = push(),pop(),peek() and empty() functions using stack 
class MyQueue {
public:
stack<int> mainStack;
stack<int> tempStack;
    MyQueue() {
        
    }
    void push(int x) {
        mainStack.push(x);   
    }
    int pop() {
        int var;
        while(!mainStack.empty())
        {       
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        var=tempStack.top();
        tempStack.pop();
        while(!tempStack.empty())
        {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        return var;    
    }
    int peek() {
        while(!mainStack.empty())
        {
            tempStack.push(mainStack.top());
            mainStack.pop();
        }
        int val=tempStack.top();
        while(!tempStack.empty())
        {
            mainStack.push(tempStack.top());
            tempStack.pop();
        }
        return val;
    }
    bool empty() {
        return mainStack.empty();   
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
