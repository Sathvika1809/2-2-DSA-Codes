#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>dist(n+1,INT_MAX),parent(n+1);
    vector<vector<int>>adj(n+1);
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    dist[1] = 0;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int t:adj[x]){
            if(dist[t] == INT_MAX){
                dist[t] = dist[x]+1;
                parent[t] = x;
                q.push(t);
            }
        }
    }
    if(dist[n] == INT_MAX) cout<<"IMPOSSIBLE\n";
    else{
        cout<<dist[n]+1<<"\n";
        vector<int>v{n};
        while(v.back()!=1)//keep gng until last element is 1
        v.push_back(parent[v.back()]); //v.back() is the last element of vector
        reverse(begin(v),end(v));
        for(int t:v) cout<<t<<" ";
    }
    return 0;
}