#include<bits/stdc++.h>
using namespace std;

int trapped(vector<int>&hyt){
    int n = hyt.size();
    int lMax = 0, rMax = 0;
    int ttlWater = 0;
    int maxHyt = hyt[0];
    int idx = 0;
    //lets fnd out the real maxhyt 
    for(int i =1;i<n;i++){
        if(hyt[i]>maxHyt){
            maxHyt = hyt[i];
            idx = i;  // store the index to divide the buildings into two halves
        }
    }

    for(int i=0;i<idx;i++){
        if(lMax>hyt[i]){
            ttlWater += lMax-hyt[i];
        }else{
            lMax=hyt[i];
        }
    }

    for(int i =n-1;i>idx;i--){
        if(rMax>hyt[i]){
            ttlWater +=rMax-hyt[i];
        }else{
            rMax = hyt[i];
        }
    }
    return ttlWater;
}


//thorugh prefix nd suffix max 
int trapped2(vector<int>&hyt){
    int n = hyt.size();

    int preMax[n],sufMax[n];
    preMax[0]=hyt[0];
    for(int i=1;i<n-1;i++){
        preMax[i] = max(preMax[i-1],hyt[i]);
    }
    sufMax[n-1]=hyt[n-1];
    for(int i =n-2;i>=0;i--){
        sufMax[i] = max(sufMax[i+1],hyt[i]);
    }
    
    int ttlWater = 0;
    for(int i =0;i<n;i++){
        int lMax = preMax[i],rMax = sufMax[i];
        if(hyt[i]<lMax && hyt[i]<rMax){
            ttlWater += min(lMax,rMax)-hyt[i];
        }
    }
    return ttlWater;
}



//through two pointer 
int trapped3(vector<int>&hyt){
    int n = hyt.size();
    int l =0  , r = n-1;
    int lMax = hyt[0] , rMax = hyt[n-1];
    int ttlWater =0;
    while(l<r){
        if(lMax<rMax){
            l++;
            lMax = max(lMax,hyt[l]);
            ttlWater += lMax-hyt[l];
        }else{
            r--;
            rMax = max(rMax,hyt[r]);
            ttlWater += rMax -hyt[r];
        }
    }
    return ttlWater;
}


int main(){
vector<int>height = {0,1,0,2,1,0,1,3,2,1,2,1};
cout<<trapped3(height)<<endl;
}