#include<bits/stdc++.h>
using namespace std;

// Implement a queue using array

class Queue{
   int *arr;
   int front;
   int rear;
   int size;
   public:
   Queue(int s){
        size = s;
        arr = new int[size];
        front =0;
        rear = -1;
   }

   bool isEmpty(){
    return front == rear+1 || front ==0 && rear == size-1;
   }

   void enqueue(int x){
    if(rear == size-1){
        cout<<"Queue overflow"<<endl;
        return;
    }
    rear++;
    arr[rear]= x;

   }

   void dequeue(){
    if(isEmpty()){
        cout<<"Queue underflow"<<endl;
        return;
    }
    front++;

   }
   int peek(){
    if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    return arr[front];
   }


};

// int main(){
//     Queue q(5);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     cout<<q.peek()<<endl;
//     q.dequeue();
//     cout<<q.peek()<<endl;

// }

//circular queue implementation using array

class Qu2{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    Qu2(int s){
       size = s;
       arr = new int[size];
       front = -1;
         rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return (rear+1)%size == front;
    }
    void enqueue(int x){
       if(isFull()){
        cout<<"Queue overflow"<<endl;
        return;
       }
       if(isEmpty()){
        front = 0;
       }else{
        rear = (rear+1)%size;
       }
       arr[rear]= x;
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front == rear){
            front =0;
            rear = -1;
        }else{
            front = (front+1)%size;
        }

    }
    int peek(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
};
// int main(){
//     Qu2 q(5);
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     cout<<q.peek()<<endl;
//     // q.dequeue();
//     // cout<<q.peek()<<endl;
// }

class q2{
int *arr;
int front ;
int rear;
int size;
int currSize;
public:
q2(int s){
    size = s;
    arr = new int[size];
    front = -1;
    rear = -1;
    currSize = 0;
}

int enq(int x){
    if(currSize== size)return -1;
    if(currSize ==0){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%size;
    }
    arr[rear] = x;
    currSize++;
}
    int deq(){
        if(currSize ==0)return -1;
        if(currSize ==1){
            front = rear = -1;
        }
        else{
            front = (front+1)%size;
        }
        currSize--;
    }
    int peek(){
        if(currSize ==0)return -1;
        return arr[front];
    }

    void display(){
        if(currSize ==0)return;
        for(int i =0;i<currSize;i++){
            cout<<arr[(front+i)%size]<<" ";
        }
        cout<<endl;
    }

};

int main(){
    q2 q(5);
    q.enq(1);
    q.enq(2);
    q.enq(3);
    q.enq(4);
    q.enq(5);
    q.display();
    q.deq();
    q.deq();
    q.display();
    q.enq(6);
    q.enq(7);
    q.enq(8);
    q.display();
}