#include<bits/stdc++.h>
using namespace std;

//find intersection point of two linked list

class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data = val;
        next= nullptr;
    }
};

//brute force through hashing
//tc -> O(n+m) , sc -> O(n)
Node* intersectionPoint(Node* head1,Node* head2){
    unordered_map<Node*,int>mpp;
    Node* temp1 = head1;
    while(temp1!=nullptr){
        mpp[temp1]++;
        temp1=temp1->next;
    }
    Node* temp2 = head2;
    while(temp2!=nullptr){
        if(mpp.find(temp2)!=mpp.end()){
            return temp2;
        }
        temp2=temp2->next;
    }
    return nullptr;
}

//optimal approach 
//with counting lengths of both
//tc -> O(n+m) , sc -> O(1)
Node* insterction2(Node* head1,Node* head2){
    Node* temp1 = head1;
    int n1 =0;
    while(temp1!=nullptr){
        n1++;
        temp1=temp1->next;
    }
    Node* temp2 = head2;
    int n2 = 0;
    while(temp2!=nullptr){
        n2++;
        temp2 = temp2->next;
    }
    int d =abs(n1-n2);
    Node* first = (n1>n2)?head1:head2;
    Node* second = (n1>n2)?head2:head1;
    while(d--){
        first= first->next;
    }
    while(first!=nullptr && second!=nullptr){
        if(first == second){
            return first;
        }
        first= first->next;
        second= second->next;
    }
    return nullptr;
}
