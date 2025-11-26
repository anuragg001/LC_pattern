#include<bits/stdc++.h>
using namespace std;
//N- queen problem using backtracking
//we will solve by creating multiple functions
//1. isSafe -> to check if placing queen at given position is safe or not
//2. solveNQUtil -> to solve the N queen problem using backtracking
//3. main function
class Solution {
public:
    bool isPossible(vector<string>&board,int row,int col,int n){
        int duprow=row;
        int dupcol = col;

        //check upper diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q')return false;
            row--,col--;
        }
        row=duprow;
        col=dupcol;
        //check lower diagonal
        while(col>=0){
            if(board[row][col]=='Q')return false;
            col--;
        }
        row=duprow;
        col=dupcol;
        //check lower diagonal
        while(col>=0 && row<n){
            if(board[row][col]=='Q')return false;
            row++,col--;
        }
        return true;
    }
    void solve(vector<string>&board,int col ,int n ,vector<vector<string>>&ans){
        if(col==n){
            ans.push_back({board});
            return;
        }

        for(int row=0;row<n;row++){
            if(isPossible(board,row,col,n)){
                board[row][col]='Q';
                solve(board,col+1,n,ans);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i =0;i<n;i++){
            board[i]=s;
        }
        solve(board,0,n,ans);
        return ans;
    }
};