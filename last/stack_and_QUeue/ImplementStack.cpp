#include<bits/stdc++.h>
using namespace std;

//using array implement stack 
class Stack{
    int *arr;
    int top;
    int size;

    public:
    Stack(int s){
        size = s;
        arr = new int[size];
        top =-1;
    }
    void push(int x){
        if(top == size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Undeflor"<<endl;
            return;
        }
        top--;
    }
    int peek(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};


//implement stack using linked list
class StackLL{
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }

    };

    Node* top = nullptr;
    int size;
    public:
    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;

    }
    void pop(){
        if(top == nullptr){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;

    }
    int peek(){
        if(top == nullptr){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }

};



int main(){
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl; //30
    st.pop();
    cout<<st.peek()<<endl; //20
    st.pop();
    st.pop();
    st.pop(); //Stack Undeflor
    return 0;
}
