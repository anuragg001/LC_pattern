#include<bits/stdc++.h>
using namespace std;

struct Node {
 int data;
 Node* next;
};
Node* head = nullptr;

void insertB(int data){
    Node * newNode = new Node();
    newNode ->data = data;
    newNode ->next = head;
    head = newNode;
}

void insertE(int data){
    Node * newNode = new Node();
    newNode ->data = data;
    newNode ->next = nullptr;

    if(head==nullptr){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next!=nullptr)temp = temp->next;
    temp->next= newNode;
}

void insertP(int data , int pos){
    if(pos == 1){
        insertB(data);
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;

    Node* temp = head;

    for(int i =1;i<pos-1 && temp!=nullptr; i++){
        temp = temp->next;
    }
    newNode->next  = temp->next;
    temp->next = newNode;
}

void deleteB(){
    if(head == nullptr)return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteE(){
    if(head == nullptr)return;
    
    if(head->next ==nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node * temp = head;
    while(temp->next->next!=nullptr)temp= temp->next;
    delete temp->next;
    temp->next = nullptr;
}

void deleteP(int pos){
    if(head == nullptr)return;
    if(pos == 1){
        deleteB();
        return;
    }
    Node * temp = head;
    for(int i =1; i<pos-1 && temp!=nullptr;i++){
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;

}

void display(){
    Node * temp = head;
    if(temp == nullptr)return;

    while(temp!=nullptr){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}



int main(){
int op, data,pos;
cin>>op;

    switch(op){
        case 1:
            cin>>data;
            insertB(data);
            break;
        case 2:
            cin>>data;
            insertE(data);
            break;
        case 3:
            cin>>data>>pos;
            insertP(data,pos);
            break;
        case 4: 
            deleteB();
            break;
        case 5:
            deleteE();
            break;
        case 6:
            cin>>pos;
            deleteP(pos);
            break;

    }

}