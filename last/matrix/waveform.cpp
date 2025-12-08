#include<bits/stdc++.h>
using namespace std;

//generat a waveform in matrix 2d array

void generate(int arr[][100],int row,int col){
    for(int j =0;j<col;j++){
        
        //for even
        if(j%2==0){
            for(int i=0;i<row;i++){
                cout<<arr[i][j]<<" ";
            }
        }else{
            for(int i =row-1;i>=0;i--){
                cout<<arr[i][j]<<" ";
            }
        }
    }
}
int main(){
    int arr[100][100];
    int row,col;
    cin>>row>>col;
    for(int i =0;i<row;i++){
        for(int j =0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    generate(arr,row,col);
    return 0;
}