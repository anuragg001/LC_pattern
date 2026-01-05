#include<bits/stdc++.h>
using namespace std;

//reverse a queue
void reverseQ(queue<int>&q){
    stack<int>st;
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

}

//reverse first k element of queue
void reverseK(queue<int>q,int k){

    // queue -> {1,2,3,4,5} , k=3
    stack<int>st;
    for(int i=0;i<k;i++){
        st.push(q.front());
        q.pop();
    }
    //stack -> {3,2,1}
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    //queue -> {4,5,1,2,3}
    int t = q.size()-k;
    while(t--){
        q.push(q.front());
        q.pop();
    }
    //queue 
}



int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverseQ(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
