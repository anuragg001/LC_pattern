#include<bits/stdc++.h>
using namespace std;


//implement linked list using array 
struct Node{
    int data;
    int next;
};

class MyLinkedList {
    vector<Node> nodes;
    int head;
    int size;
public:
    MyLinkedList() {
        nodes.resize(1000); //initial capacity
        head = -1;
        size = 0;
    }

int get(int index) {
    if (index < 0 || index >= size) return -1;
    int curr = head;
    for (int i = 0; i < index; i++) {
        curr = nodes[curr].next;
    }
    return nodes[curr].data;
}

void addAtHead(int val) {
    Node newNode = {val, head};
    nodes[size] = newNode;
    head = size;
    size++;
}

void addAtTail(int val) {
    Node newNode = {val, -1};
    if (head == -1) {
        nodes[size] = newNode;
        head = size;
    } else {
        int curr = head;
        while (nodes[curr].next != -1) {
            curr = nodes[curr].next;
        }
        nodes[size] = newNode;
        nodes[curr].next = size;
    }
    size++;
}

void addAtIndex(int index, int val) {
    if (index < 0 || index > size) return;
    if (index == 0) {
        addAtHead(val);
        return;
    }
    int curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = nodes[curr].next;
    }
    Node newNode = {val, nodes[curr].next};
    nodes[size] = newNode;
    nodes[curr].next = size;
    size++;
}

void deleteAtIndex(int index) {
    if (index < 0 || index >= size) return;
    if (index == 0) {
        head = nodes[head].next;
        return;
    }
    int curr = head;
    for (int i = 0; i < index - 1; i++) {
        curr = nodes[curr].next;
    }
    nodes[curr].next = nodes[nodes[curr].next].next;
}
};