#include<bits/stdc++.h>
using namespace std;
//linked list creation ,insetion ,deletion and display 
class Node{
    public:
    int data;
    Node * next;
    Node(int val){
        data = val;
        next= nullptr;
    }
};

Node* arrtoll(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node * mover = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next= temp;
        mover =mover->next;
    }
    return head;
}


// deletion at head
Node* deleteAtHead(Node* head){
    if(head==nullptr)return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

//delete at tail 
Node* deleteAtTail(Node* head){
    if(head ==nullptr || head->next ==nullptr)return nullptr;
    Node* temp = head;
    while(temp->next->next !=nullptr){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;
}

//deelte at pos
Node* deleteAtPos(Node* head,int pos){
    if(head==nullptr)return head;
    if (pos==1){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp = head;
    Node* prev = nullptr;
    int cnt = 0;
    while(temp !=nullptr){
        cnt++;
        if(cnt == pos){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

//delete the elem by val
Node* deleteByVal(Node* head,int val){
    if(head==nullptr)return head;
    if (head->data == val){
        Node* temp = head;
        head=head->next;
        free(temp);
        return head;
    }
    Node*temp = head;
    Node* prev = nullptr;
    while(temp !=nullptr){
        if(temp->data == val){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int search(Node* head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data ==val)return 1;
        temp = temp->next;
    }
    return 0;
}

//insert at head
Node* insertatHead(Node* head,int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return head;
}

//insert at tail 
Node* insertAtTail(Node* head,int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head  = newNode;
        return head;
    }
    Node * temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = nullptr;
    return head;
}


//insert at pos
Node* insertAtPos(Node* head,int pos ,int val){
    Node* newNode  = new Node(val);
    if(head == nullptr){
        if(pos==1){
            head = newNode;
            return head;
        }
    }
    if(pos==1){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;
    int cnt =0;
    while(temp !=nullptr){
        cnt++;
        if(cnt ==pos-1){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;

    }
    return head;
}

//insert by val
Node* insertBYval(Node* head,int el,int val){
    Node* newNode  = new Node(val);
    if(head ==nullptr){
        return nullptr;
    }
    if(head->data == val){
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node* temp = head;  
    while(temp->next !=nullptr){
        if(temp->next->data == val){
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;

    }
    return head;
}
void print(Node*head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}





int main(){
    vector<int>arr={1,2,3,4,5};
    Node* head = arrtoll(arr);

    // print(head);
    // head = deleteAtHead(head);
    // print(head);
    // head = deleteAtTail(head);
    // print(head);    
    // head = deleteAtPos(head,2);
    // print(head);
    // head = deleteByVal(head,4);
    // print(head);

    head = insertatHead(head,0);
    print(head);
    head = insertAtTail(head,6);
    print(head);
    head = insertAtPos(head,4,10);
    print(head);
    head = insertBYval(head,3,9);
    print(head);
      
}
