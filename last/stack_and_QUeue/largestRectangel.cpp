#include<bits/stdc++.h>
using namespace std;

//largest rectangale in histogram
//though stack ans nse and pse

vector<int> nse(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i = 0;i<n;i++){
        while(!st.empty() && arr[st.top()]>arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

vector<int> pse(vector<int>&arr){
    int n = arr.size();
    vector<int>ans(n,-1);
    stack<int>st;
    for(int i =n-1;i>=0;i--){
        while(!st.empty() && arr[st.top()]>=arr[i]){
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

int largest(vector<int>&arr){
    int n = arr.size();
    vector<int>nextSmaller = nse(arr);
    vector<int>prevSmaller = pse(arr);
    int maxArea = 0;
    for(int i =0;i<n;i++){
        int next = nextSmaller[i] == -1 ?n:nextSmaller[i];
        int prev = prevSmaller[i] == -1 ?-1:prevSmaller[i];
        int width = next-prev-1;
        int area = arr[i]*width;
        maxArea = max(maxArea,area);
    }
    return maxArea;
}


// next question -> maximal rectangle in binary matrix

// lets solve with same approach of nse and pse

//calculate largest rectangle for each row by considering that row as histogram
// then return max area among them
// time complexity -> O(n*m)

int maximal(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();
    vector<int>histogram(m,0);
    int maxArea = 0;
    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(arr[i][j]=='0'){
                histogram[j]=0;
            }else{
                histogram[j]+=1;
            }
        }
        maxArea = max(maxArea ,largest(histogram));
    }
    return maxArea;

}