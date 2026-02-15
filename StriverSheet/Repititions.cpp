#include <iostream>
using namespace std;

int findRepitition(string& s){
    int n =  s.size();
    int HashLen = 256;
    int hash[HashLen];
    for(int i =0;i<HashLen;++i){
        hash[i] = -1;
    }
    int left = 0,right = 0,maxLen = 0;
    while(right < n){
        if(hash[s[r]]!=-1){
            left = max(hash[s[r]]+1 , l);
        }
            int len = r-l+1;
            maxLen = max(maxLen,len);
            hash[s[r]] = r;
            r++;
    }
        return maxLen;
        
    }

int main(){
    string s;
    cin>>s;
    int max = findRepitition(s);
    cout<<max<<" ";
}