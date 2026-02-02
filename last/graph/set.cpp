#include<bits/stdc++.h>
using namespace std;


//set matrix zero 
// bruteforce apporach by taking extra space as whole array 

void set(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>>temp = mat;

    for(int i -0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j]==0){

                //row 
                for(int k =0;k<n;k++){
                    temp[i][k]= 0;
                }

                //col
                for(int k =0;k<m;k++){
                    temp[k][j] =0;
                }
            }
        }
    }
    mat = temp;
}


//better approach using extra space for only row and col

void set2(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<bool>row(n,false);
    vector<bool>col(m,false);


    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j]==0){
                row[i]= true;
                col[j]= true;
            }
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(row[i] || col[j])
                mat[i][j]=0;
        }
    }

}


//optiimal approach withut extra space

void set3(vector<vector<int>>&mat){
    int m = mat.size(); // row
    int n = mat[0].size(); // col


    //for edge cases
    bool firstRow = false;
    bool firstCol = false;

    //chcek first row 
    for(int col=0;col<n;col++){
        if(mat[0][col]==0){
            firstRow = true;
            break;
        }
    }


    //chcek first col 
    for(int row=0;row<m;row++){
        if(mat[row][0]==0){
            firstCol = true;
            break;
        }
    }


    //set the markeres
    for(int i =1;i<m;i++){
        for(int j =1;j<n;j++){
            if(mat[i][j]==0){
                mat[i][0]=0;
                mat[0][j]=0;
            }
        }
    }


    //second traversal to set zeroes
    for(int i=1;i<m;i++){
        for(int j =1;j<n;j++){
            if(mat[i][0]==0 || mat[0][j]==0){  // first element of row or col is zero if then
                mat[i][j]=0;
            }
        }
    }


    //edges cases for first row and col impaceted

    if(firstRow){
        for(int col =0;col<n;col++){
            mat[0][col]=0;
        }
    }
    if(firstCol){
        for(int row =0;row<m;row++){
            mat[row][0]=0;
        }
    }
}
