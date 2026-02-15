#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long reachable = 1;
    for(long long coin:a){
        if(coin>reachable){
            break;
        }
        reachable+=coin;
    }
    cout<<reachable<<endl;
    return 0;
}