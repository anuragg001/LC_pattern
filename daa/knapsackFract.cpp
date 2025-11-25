#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(struct Item a,struct Item b){
    return (double)a.value/a.weight>(double)b.value/b.weight;
}

double knapsack(int W,vector<Item>&item){
    sort(item.begin(),item.end(),cmp);
    double ttl=0.0;
    for(auto &it:item){
        if(W==0)break;

        if(it.weight<=W){
            W -=it.weight;
            ttl +=it.value;
        }else{
            ttl+=(double)it.value*((double)W/it.weight);
            //why W=0 here?
            //Ans -> to break the loop in next iteration
            W=0;
        }
    }
    return ttl;
}
