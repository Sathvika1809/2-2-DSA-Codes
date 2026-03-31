#include <bits/stdc++.h>
using namespace std;
 int n,m;
vector<string>grid(n);
pair<int,int>parent[1000][1000];
bool visited[1000][1000];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int reached_end = false;
int move_count = 0;
int nodes_left_in_layer = 1;
int nodes_in_next_layer = 0;
int main(){
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        cin>>grid[i];
    }
    
    queue<int>rq;
    queue<int>cq;
    pair<int,int>st,end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='S'){
                st = {i,j};
            }
            if(grid[i][j]=='E'){
                end = {i,j};
            }
        }
    }
    rq.push(st.first);
    cq.push(st.second);
    visited[st.first][st.second] = true;
    while(rq.size()>0){
        int r = rq.front();
        int c = cq.front();
        rq.pop();
        cq.pop();
        if(grid[r][c]=='E'){
            reached_end = true;
            break;
        }
        for(int i=0;i<4;i++){
            int x = r+dx[i];
            int y = c+dy[i];
            if(x>=0&&x<n&&y>=0&&y<m){
                if(!visited[x][y]&&grid[x][y]!='#'){
                    visited[x][y] = true;
                    parent[x][y] = {r,c};
                    rq.push(x);
                    cq.push(y);
                    nodes_in_next_layer++;
                }
            }
        }
        nodes_left_in_layer--;

        if(nodes_left_in_layer==0){
            nodes_left_in_layer = nodes_in_next_layer;
            nodes_in_next_layer = 0;
            move_count++;
        }
    }
    cout<<move_count<<endl;



    return 0;
}