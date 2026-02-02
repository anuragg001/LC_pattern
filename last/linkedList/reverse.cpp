#include<bits/stdc++.h>
using namespace std;

//reverse a linked list

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* reverse(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}