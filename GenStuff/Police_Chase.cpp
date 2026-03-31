//Not a BFS algo u should know dinic algo


#include <bits/stdc++.h>
using namespace std;
vector<int>adj[1000];
bool visited[1000];
int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int>q;
    vector<pair<int,int>>ans;
    q.push(1);
    visited[1] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int t:adj[x]){
            if(!visited[t]){
                visited[t] = true;
                q.push(t);
                if(t==n){
                    ans.push_back({x,t});
                }
            }
        }
    }
    int sz = ans.size();
    cout<<sz<<"\n";
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<"\n";
        
    }

    return 0;
}