#include<bits/stdc++.h>
using namespace std;

//find the lenght of the loop in linked list

//brute force using hashing

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

int len(Node* head){
    unordered_map<Node* ,int>mpp;
    Node* temp  = head;
    int timer =1;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return timer -mpp[temp];
        }
        mpp[temp]=timer;
        timer++;
        temp=temp->next;

    }
    return 0;
}