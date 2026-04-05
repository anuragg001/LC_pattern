#include<bits/stdc++.h>
using namespace std;

//stack using linked list 

class Stack{

    struct Node{
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }
    };

    Node* top;
    public:
    Stack(){
        top = nullptr;
    }

    void push(int x){
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }

    void pop(){
        if(top == nullptr){
            cout<<"Stack underflow"<<endl;
            return;
        }
        Node* temp = top;
        top= top->next;
        delete temp;
    }

    int peek(){
        if(top == nullptr){
            cout<<"Stak=ck undeflow"<<endl;
            return -1;
        }
        return top->data;
    }


};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
}