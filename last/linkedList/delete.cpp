#include<bits/stdc++.h>
using namespace std;
//delete the middle of the given linked list

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

//brute force using n/2 traversal
Node* deleteMid(Node* head){
    if(head==nullptr || head->next==nullptr)return nullptr;
    int n =0;
    Node* temp = head;
    while(temp!=nullptr){
        n++;
        temp =temp->next;
    }
    int mid = n/2;
    temp=head;
    while(mid!=0){
        mid--;
        if(mid==0){
            temp->next = temp->next->next;
            delete temp->next;
            break;

        }
        temp=temp->next;

    }
    return head;

}
//optimal approach using slow and fast pointer 
Node* deleteMid2(Node* head){

}