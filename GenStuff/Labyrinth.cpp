//Finally understood BFS for shortest paths


#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string>grid(n);
bool visited[1000][1000];
pair<int,int>parent[1000][1000];
char moveDir[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char dir[4] = {'D','U','R','L'};
int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    
    queue<pair<int,int>>q;
    pair<int,int>start,end;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'A') start={i,j};
            if(grid[i][j] == 'B')end = {i,j};
        }
    }
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        pair<int,int>val = q.front();
        int x = val.first;
        int y = val.second;
        q.pop();
        for(int i=0;i<4;i++){
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(cx>=0&&cx<n&&cy>=0&&cy<m){
                if(!visited[cx][cy]&&grid[cx][cy]!='#'){
                    visited[cx][cy] = true;
                    parent[cx][cy] = {x,y};
                    moveDir[cx][cy] = dir[i];
                    q.push({cx,cy});

                }
            }
        }
    }
    // if B is not visited
    if(!visited[end.first][end.second]){
        cout<<"NO\n";
        return 0;
    }
    //reconstruct path

    string path = "";
    pair<int,int>cur = end;
    while(cur!=start){
        path+=moveDir[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(),path.end());
    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";


    return 0;
}