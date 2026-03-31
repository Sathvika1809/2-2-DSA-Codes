//TC: O(V+E)
//SC: space for adj and visited


#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10005];
bool visited[10005]

void dfs(int node){
    if(visited[node]) return;
    visited[node] = true;
    for(int neighbor: adj[node]){
        dfs(neighbor);
    }
}
//the ones not visited will be counted as diff
//because we do visit a node once and then by recursive backtracking
//we visit all its neighbors and then come back if there is dead end
//so like this we covered its neighbors
//so now whatever unvisited node comes it isnt a neighbor of this node
//so may be its connected to this so we inc count
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected graph
    }
    int components = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components++;
            dfs(i); // this goesto all neighbors like complete traversal
        }
    }
    cout<<components<<endl;
    return 0;
}
