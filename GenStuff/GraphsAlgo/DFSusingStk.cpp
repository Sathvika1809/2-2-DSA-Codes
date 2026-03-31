#include <bits/stdc++.h>
using namespace std;
vector<int>adj[10005];
bool visited[10005];
void dfs(int node){
    stack<int>st;
    st.push(node);
    visited[node] = true;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        cout<<node<<" ";
       for(int neighbor:adj[node]){
        if(!visited[neighbor]){
            visited[neighbor] = true;
            st.push(neighbor);
        }
    }
    }
    return;
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
    dfs(1);

    return 0;
}