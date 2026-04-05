#include<bits/stdc++.h>
using namespace std;





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


bool isEmpty(){
    return top == -1;
}

void push(int x){
    if(top == size-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    top++;
    arr[top] = x;

}

void pop(){
    if(top == -1){
        cout<<"Stack underflow"<<endl;
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


int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    
}