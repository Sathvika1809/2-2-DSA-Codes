#include <bits/stdc++.h>
using namespace std;

vector<int>adj[10005];
bool visited[10005];
int dist[10005];

void bfs(int start){
    queue<int>q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int neighbor:adj[node]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                dist[neighbor] = dist[node]+1;
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
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<"dist from 1 to "<<i<<"="<<dist[i]<<endl;
    }
    return 0;
}