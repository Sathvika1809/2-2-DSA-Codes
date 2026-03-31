#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string>grid;
bool visited[1000][1000];
pair<int,int>parent[1000][1000];
char moveDir[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
char dir[4] = {'R','L','D','U'};

int main(){
    cin>>n>>m;
    grid.resize(n);

    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    queue<pair<int,int>>q;
    pair<int,int>st,end;

    //find A and B
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'S') start={i,j};
            if(grid[i][j] == 'E')end = {i,j};
        }
    }
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<m){
                if(!visited[nx][ny] && grid[nx][ny]!='#'){
                    visited[nx][ny] = true;
                    parent[nx][ny] = {x,y};
                    moveDir[nx][ny] = dir[i];
                    q.push({nx,ny});
                }
            }
        }
    }

    // if B not visited

    if(!visited[end.first][end.second]){
        cout<<"NO\n";
        return 0;
    }
    //reconstruct path
    string path ="";
    pair<int,int>cur = end;

    while(cur!=start){
        path += moveDir[cur.first][cur.second];
        cur = parent[cur.first][cur.second];
    }
    reverse(path.begin(),path.end());

    cout<<"YES\n";
    cout<<path.size()<<"\n";
    cout<<path<<"\n";
    return 0;
}