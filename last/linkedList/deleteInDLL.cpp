#include<bits/stdc++.h>
using namespace std;

//ps -> delete all occurrences of a given key in a doubly linked list

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

Node* deleteall(Node* head ,int x){
    Node * temp = head;
        while(temp!=nullptr){
            if(temp->data == x){
                if(temp==head){
                    head = head->next;
                }
                Node* nextNode = temp->next;
                Node * prevNode =  temp->prev;
                if(nextNode)nextNode->prev = prevNode;
                if(prevNode) prevNode->next = nextNode;
                
                free(temp);
                temp = nextNode;
            }else{
                temp = temp->next;
            }
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
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;

    cout<<"Original list: ";
    display(head);

    int key = 2;
    head = deleteall(head, key);

    cout<<"List after deleting all occurrences of "<<key<<": ";
    display(head);

    return 0;
}