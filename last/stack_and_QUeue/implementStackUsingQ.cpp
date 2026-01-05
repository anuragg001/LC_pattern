#include<bits/stdc++.h>
using namespace std;

/*
 Implement stack using queue
  using two queues
  for push use those q which is not empty

  for pop use the other queue to push all element except last one from non empty queue
  then pop the last element and swap the name of two queues

  for peek use the same approach as pop but instead of popping last element just return it and push it to other queue

  for empty just check both queues are empty or not
*/

class MyStack {
    queue<int>q1;
    queue<int>q2;
    public:

    bool empty(){
        return q1.empty() && q2.empty();
    }

    void push(int x){
        if(!q1.empty()){
            q1.push(x);
        }else{
            q2.push(x);
        }
    }

    int pop(){
        if(empty())return 0;

        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int elem = q1.front();
            q1.pop();
            return elem;
        }else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int elem = q2.front();
            q2.pop();
            return elem;

        }

    }

    int peek(){
        if(empty())return 0;

        if(!q1.empty()){
            while(q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int elem  = q1.front();
            q2.push(elem);
            q1.pop();
            return elem;
        }else{
            while(q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int elem = q2.front();
            q1.push(elem);
            q2.pop();
            return elem;
        }
    }
    
};