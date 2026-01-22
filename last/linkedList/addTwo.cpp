#include<bits/stdc++.h>
using namespace std;

/*
Add two linked list
*/


class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};


Node* addtwo(Node* l1 ,Node* l2){
Node* dummyNode = new Node(-1);
Node* curr = dummyNode;
Node* t1 = l1;
Node * t2 = l2;

int carry = 0;
while(t1!=nullptr || t2 != nullptr){
    int sum = carry;
    if(t1){
        sum += t1->data;
        t1 = t1->next;
    }
    if(t2){
        sum += t2->data;
        t2 = t2->next;
    }
    Node* newNode = new Node(sum%10);
    carry = sum/10;
    curr->next = newNode;
    curr = curr->next;
}
if(carry){
    Node* newNode = new Node(carry);
    curr->next = newNode;
}
return dummyNode->next;
}