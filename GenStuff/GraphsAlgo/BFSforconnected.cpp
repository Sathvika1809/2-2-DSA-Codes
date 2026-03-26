#include <bits/stdc++.h>
using namespace std;


vector<int>adj[10005];
bool visited[10005];

void bfs(int start){
    queue<int>q;
    visited[start] = true;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        
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
        adj[v].push_back(u);
    }
    int components = 0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            components++;
            bfs(i);
        }
    }
    cout<<components<<endl;
    return 0;
}