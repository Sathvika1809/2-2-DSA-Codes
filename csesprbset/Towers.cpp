#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>towers;
    for(int i=0;i<n;i++){
        int x=arr[i];
        auto it = upper_bound(towers.begin(),towers.end(),x);
        if(it==towers.end()){
        towers.push_back(x);
        }else{
            *it = x;
        }
    }
    cout<<towers.size()<<endl;
    
    return 0;
}