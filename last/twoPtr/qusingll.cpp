#include<bits/stdc++.h>
using namespace std;


//implenet q using linked list 

class Q{
    struct Node{
        int data;
        Node* next;

        Node(int x){
            data = x;
            next = nullptr;
        }
    };
    Node *front;
    Node * rear;
    public:
    Q(){
        front = nullptr;
        rear = nullptr;
    }

    

    void enqueue(int x){
        Node * newNode = new Node(x);
        if(rear== nullptr){
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front == nullptr){
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr){
            rear = nullptr;
        }
        delete temp;
    }
    int peek(){
        if(front == nullptr){
            return -1;
        }
        return front->data;
    }
    
};

int main(){
    Q q;
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3);
        cout<<q.peek()<<endl;
        q.dequeue();
        cout<<q.peek()<<endl;
}