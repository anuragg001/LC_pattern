#include<bits/stdc++.h>
using namespace std;

//detect a loop in linked list

//bruteforce using hashing
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

bool detect(Node* head){
    unordered_map<Node* ,int>mpp;
    Node* temp = head;
    while(temp!=nullptr){
        if(mpp.find(temp)==mpp.end()){
            return true;
        }
        mpp[temp]++;
        temp=temp->next;
    }
    return false;
}

//optimal approach using two pointers
bool detect2(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast!=nullptr && fast->next!=nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast)return true;
    }
    return false;
}