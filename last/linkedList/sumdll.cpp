#include<bits/stdc++.h>
using namespace std;


//px ->find all pairs in doubly linked list whose sum is equal to given value x

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

//brute force
vector<pair<int,int>> sumPairs(Node* head ,int x){
    vector<pair<int,int>>res;
    Node* temp1 = head;
    while(temp1!=nullptr){
        Node* temp2 = temp1->next;
        while(temp2!=nullptr && (temp1->data + temp2->data)<=x){
            if(temp1->data+temp2->data == x){
                res.push_back({temp1->data , temp2->data});
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return res;
}


//using {
