//TC: O(V+E)
//V for each node is visited once so O(V)
//and in each neighbor thing we r visiting every edge


#include <bits/stdc++.h>
using namespace std;

vector<int>adj[10005];
bool visited[10005];

void bfs(int node){
    queue<int>q;
    if(visited[node])return;
    visited[node] = true;
    q.push(node);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
        cout<<node<<" ";
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
            visited[neighbor] = true;
            q.push(neighbor);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u); //undirected graph
    }
    bfs(1);
    return 0;
}