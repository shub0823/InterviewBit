/*
https://www.interviewbit.com/problems/min-stack/
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
        push(x) – Push element x onto stack.
        pop() – Removes the element on top of the stack.
        top() – Get the top element.
        getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.
Questions to ask the interviewer :
Q: What should getMin() do on empty stack? 
A: In this case, return -1.
Q: What should pop do on empty stack? 
A: In this case, nothing. 
Q: What should top() do on empty stack?
A: In this case, return -1
    NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor. 
*/

//a stack of pair<int, int> first int is for returning the topmost element and other int is to compare and plave the min elem on second.
stack<pair<int, int> > st;


MinStack::MinStack() {
    while (!st.empty())
        st.pop();
}

void MinStack::push(int x) {
    int mn = (st.empty()) ? x : min(st.top().second, x);//second place in pair is for minimum element among all.
    st.push(make_pair(x, mn));
}

void MinStack::pop() {
    if (!st.empty())
        st.pop(); 
}

int MinStack::top() {
    if (!st.empty())
        return st.top().first;
    return -1;
}

int MinStack::getMin() {
    if (!st.empty())
        return st.top().second;
    return -1;
}

