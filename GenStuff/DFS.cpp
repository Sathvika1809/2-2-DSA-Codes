#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100];
bool visited[100];

void dfs(int node){
    if(visited[node]){
        return;
    }
    visited[node] = true;
    cout<<node<<" ";
    for(int neighbor:adj[node]){
            dfs(neighbor);
    }
    return;
}

int main(){
    int m,n; // n - no.of edges
    // m - number of edges
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1); //start from 1 here
    return 0;
}