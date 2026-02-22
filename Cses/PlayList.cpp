#include <bits/stdc++.h>
using namespace std;

int main(){
   int n;
   cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    multiset<int>st;
    int ans=0;
    int l=0,r=0;
    while(r<n){
    st.insert(v[r]);
    while(l<=r && st.count(v[r])>1){
        auto it = st.find(v[l]);
        st.erase(it);
        l++;
    }
    ans = max(ans,r-l+1);
    r++;
}
cout<<ans<<endl;


    return 0;
}