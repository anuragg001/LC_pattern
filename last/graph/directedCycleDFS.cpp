#include<bits/stdc++.h>
using namespace std;

/*
    cycle detection in a directed graph using DFS
    using though two flags:visited[] and dfsVisited[]

    the difference between undirected ans directed cycle detection is that in undirected graph we need to keep track of parent node to avoid false positive cycel detection whereas ,
     based  on current recursion stack  
*/