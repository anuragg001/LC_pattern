#include<bits/stdc++.h>
using namespace std;

//ps -> merege k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

//brute force 
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node * arrToll(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

Node* merge(vector<Node*>& lists){
    vector<int>arr;
    for(auto head: lists){
        Node* temp = head;
        while(temp!=nullptr){
            arr.push_back(temp->data);
            temp = temp->next;
        }

    }
    sort(arr.begin(), arr.end());
    return arrToll(arr);
    
}