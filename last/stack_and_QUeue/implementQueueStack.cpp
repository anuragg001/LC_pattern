#include<bits/stdc++.h>
using namespace std;

//implement queue using stack

/*
    approach1 : using 2 stack
    push : O(1)
    pop : O(n)
    front : O(n)
    empty : O(1)
    Intution: Use two stacks to simulate the queue operations.
    first stack  is use to enqueue operation , second stack is use to dequeue operation.

*/

class MyQueue {
    stack<int>s1;
    stack<int>s2;
public:
    bool empty(){
        return s1.empty() && s2.empty();
    }

    void push(int x){
        s1.push(x);
    }

    int pop(){
        if(empty())return 0;

        if(!s2.empty()){
           int element = s2.top();
           s2.pop();
           return element;
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            int element = s2.top();
            s2.pop();
            return element;
        }
        
    }

    int peek(){
        if(empty())return 0;

        if(!s2.empty()){
            return s2.top();
        }else{
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }


};