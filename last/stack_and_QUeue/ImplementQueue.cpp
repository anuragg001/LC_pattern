#include<bits/stdc++.h>
using namespace std;

//implement queue using array

class Queue{
    int *arr;
    int front;
    int rear;
    int size;

    public:
    //front is responsible for dequeue
    //rear is responsible for enqueue
    Queue(int s){
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x){
       if(rear == size -1){
        cout<<"Queue Overflow"<<endl;
        return;
       }
       if(front == -1){
        front = 0;
       }
       rear = (rear+1)%size;
       arr[rear] = x;
    }

    void dequeue(){
        if(front == -1 || front>rear){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        front++;
        if(front>rear){
            front = rear  = -1;
        }
    }

    int top(){
        if(front == -1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    
    }

};


//implement queue using linked list
class QueueLL{
    struct Node{
        int data;
        Node* next;
        Node(int x){
            data = x;
            next = nullptr;
        }

    };
    Node* front = nullptr;
    Node* rear = nullptr;
    int size;

    public:
    void enqueue(int x){
        Node* newNode=   new Node(x);
        if(rear == nullptr){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear  = newNode;

    }
    void dequeue(){
        if(front == nullptr){
            cout<<"Queue Underflow"<<endl;
            return;
        }
        Node* temp  = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;   
        return;
    }
    int top(){
        if(front == nullptr){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    

};





int main(){
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout<<q.top()<<endl; //10
    q.dequeue();
    cout<<q.top()<<endl; //20
    q.dequeue();
    q.dequeue();
    q.dequeue(); //Queue Underflow
    return 0;
}