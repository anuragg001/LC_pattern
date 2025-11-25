#include<bits/stdc++.h>
using namespace std;

//activity selection problem using greedy approach
struct Activity{
    int start;
    int end;
};
//in ascending order of end time
bool cmp(struct Activity a, struct Activity b){
    return a.end<b.end;
}

int acitvity(vector<Activity>&act,int n){
    sort(act.begin(),act.end(),cmp);
    int cnt = 1;
    int lastEnd=act[0].end;
    for(int i=1;i<n;i++){
        if(act[i].start>=lastEnd){
            cnt++;
            lastEnd =act[i].end;
        }
    }
    return cnt;
}
int main(){
    vector<Activity>act={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    int n=act.size();
    cout<<acitvity(act,n);
    return 0;
}