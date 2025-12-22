#include<bits/stdc++.h>
using namespace std;


//ps ->reverse a linked list in groups of size k

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* revll(Node* head){
    Node *temp = head;
    Node* prev = nullptr;
    while(temp!=nullptr){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp ;
        temp =front;
    }
    return prev;
}

Node* getKthNode(Node* head,int k){
    Node* temp = head;
    int cnt =1; // why count is 1 because we are already at head node
    while(temp!=nullptr && cnt<k){
        temp =temp->next;
        cnt++;
    }
    return temp;
}

Node* reverseKGrp(Node* head ,int k){
    Node* temp = head;
    Node* prevLast = nullptr;

    while(temp!=nullptr){
        Node* kthNode = getKthNode(temp,k);
        if(kthNode == nullptr){
            if(prevLast)prevLast->next = temp; // connect the last part which is less than k
            break;
        }

        Node* nextNode = kthNode->next;
        kthNode->next = nullptr; // break the link to reverse only k nodes
        revll(temp); // reverse k nodes

        if(temp==head){
            head = kthNode; // new head after reversing first k nodes

        }else{
            prevLast->next = kthNode; // connect previous part with reversed k nodes
        }
        prevLast = temp ; // temp is now the last node after reversing
        temp = nextNode; // move to the next part of the list
    }
    return head;
}
void display(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


//another method using recursion only 

Node* revKgrp(Node* head,int k){
    if(!head)return nullptr;

    Node * temp = head;
    int cnt= 0;
    while(temp!=nullptr && cnt<k){
        temp= temp->next;
        cnt++;
    }
    if(cnt<k){
        return head;
    }

    Node* prev = nullptr;
    Node* curr  = head;
    Node* front = nullptr;
    cnt =0; // why count is 0 because we are at head node and we have to reverse k nodes
    while(curr!= nullptr && cnt<k){  // reverse k nodes
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
        cnt++; // whey increment count bcos we have reversed one node
    }

    //if there are more nodes to process that mean front is not null
    if(front){
        //just call the function recursively for the next part
        //why to pass head becos head is now the last node after reversing
        head->next = revKgrp(front,k);
    }
    return prev; // prev is the new head after reversing k nodes
}





int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);

    int k = 3;
    cout<<"Original list: ";
    display(head);

    head = reverseKGrp(head,k);

    cout<<"Reversed list in groups of "<<k<<": ";
    display(head);
}

