#include<bits/stdc++.h>
using namespace std;

//find the starting point of loop in linked list

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

//brute foce using hashing 
Node* startLoop(Node* head){
    unordered_map<Node*,int>mpp;
    Node* temp = head;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return temp;
        }
        mpp[temp]++;
        temp =temp->next;
    }
    return nullptr;
}


//using slow and fast pointer
Node* st2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next!=nullptr){
        slow =slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow!=fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}