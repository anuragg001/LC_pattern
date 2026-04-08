#include<bits/stdc++.h>
using namespace std;

// walking robot simulation 

/*
North -> {0,1}
South -> {0,-1}
East -> {1,0}
West -> {-1,0}


what if left 90 degree
North -> West  then add {-1,0} which was initlally {0,1};
North -> West  then add {-1,0} which was initlally {0,1};
North -> West  then add {-1,0} which was initlally {0,1};
North -> West  then add {-1,0} which was initlally {0,1};


*/

int robot(vector<int>&commands , vector<vector<int>>& obstacles){
    unordered_set<string>st;
    for(auto & obs:obstacles){
        string key = to_string(obs[0]) + "_" + to_string(obs[1]);
        st.insert(key);
    }

    int x = 0;
    int y = 0;
    int dist = 0;

    pair<int,int>dir = {0,1}; //inially facing north

    int n = commands.size();
    for(int i =0;i<n;i++){
        if(commands[i] == -2){ // left 90 degree
            dir = {-dir.second , dir.first};
        }else if(commands[i] == -1){ // right 90 degree
            dir = {dir.second , -dir.first};
        }else{
            for(int step = 0;step<commands[i];step++){
                int newX = x + dir.first;
                int newY = y + dir.second;

                string nextkey = to_string(newX) + "_" + to_string(newY);
                
                if(st.find(nextkey) != st.end()){
                    break;
                }
                x = newX;
                y = newY;

            }
        }
        dist = max(dist , x*x + y*y);
    }
    return dist;

}