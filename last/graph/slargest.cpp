#include<bits/stdc++.h>
using namespace std;

int slargest(vector<int>&arr){
priority_queue<int>pq;
int n = arr.size();
for(int i =0;i<n;i++){
    pq.push(arr[i]);
}
pq.pop();
return pq.top();

}
int main(){
    vector<int>arr ={2,3,6,5,1,8,4}; 
    cout<<slargest(arr);
}