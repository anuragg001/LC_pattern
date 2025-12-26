#include<bits/stdc++.h>
using namespace std;

/*
spiral form of matrix 
traversal order - > top row ->rightmost col -> bottom row -> leftmost col

*/
void spiral(int arr[][100],int row,int col){
    int top =0,right = col-1;
    int bottom = row-1,left =0;
    while(top<=bottom && left<=right){
        //top row
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        //rightmost col
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        //bottom row
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<arr[bottom][i]<<" ";
            }
            bottom--;
        }
        //leftmost col
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<arr[i][left]<<" ";
            }
            left++;
        }
    }
    
}