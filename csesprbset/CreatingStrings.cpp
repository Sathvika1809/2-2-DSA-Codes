#include <bits/stdc++.h>
using namespace std;
set<string>ans;
void generate(string s,int idx){
    if(idx == s.size()){
        ans.insert(s);
        return;
    }
    for(int i=idx;i<s.size();i++){
        swap(s[idx],s[i]);
        generate(s,idx+1);
        swap(s[idx],s[i]);//Backtrack
    }
}

int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    generate(s,0);
    cout<<ans.size()<<endl;
    for(string s:ans){
        cout<<s<<endl;
    }

    return 0;
}