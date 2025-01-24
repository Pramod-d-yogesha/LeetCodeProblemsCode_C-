/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

155. Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 
Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

APPROACH
=======================
Explanation:
Two Stacks:
1. dataStack: Stores all the elements of the stack.
2. minStack: Keeps track of the minimum element at each state of the stack.
   - When an element is pushed onto dataStack, if it's less than or equal to the current minimum, it is also pushed onto minStack.
   - When an element is popped from dataStack, if it matches the top of minStack, it is also popped from minStack.

Operations:
1. push(val): 
   - Push val onto dataStack. 
   - If minStack is empty or val is less than or equal to the current minimum, push val onto minStack.
2. pop(): 
   - Remove the top element from dataStack. 
   - If the top of dataStack is equal to the top of minStack, also pop from minStack.
3. top(): 
   - Return the top element of dataStack.
4. getMin(): 
   - Return the top element of minStack (current minimum).

Time Complexity:
- All operations (push, pop, top, getMin) are O(1) because the operations on stacks (push and pop) are constant time.

Example Execution:
Input:
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output:
[null,null,null,null,-3,null,0,-2]

Execution Steps:
1. push(-2):
   - dataStack: [-2]
   - minStack: [-2]

2. push(0):
   - dataStack: [-2, 0]
   - minStack: [-2]

3. push(-3):
   - dataStack: [-2, 0, -3]
   - minStack: [-2, -3]

4. getMin():
   - Return top of minStack: -3

5. pop():
   - dataStack: [-2, 0]
   - minStack: [-2]

6. top():
   - Return top of dataStack: 0

7. getMin():
   - Return top of minStack: -2

+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

class MinStack {
public:
    stack<int> mainStack;
    stack<int> minStack;
    MinStack() {  
    }
    void push(int val) {
            mainStack.push(val);
        if(minStack.empty() || val<=minStack.top())
            minStack.push(val); 
    }   
    void pop() {

        if(mainStack.top()==minStack.top())
        {
                minStack.pop();
        }
       mainStack.pop();
    }
    int top() {
        return mainStack.top();
    }
    int getMin() {
        return minStack.top();
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
