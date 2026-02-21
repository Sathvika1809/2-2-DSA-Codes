#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long n=s.length();
    long long maxLen=1;
    long long currLen = 1;
    long long i=0;
    while(i<n){
        long long j=i+1;
        if(s[j]==s[i]){
            currLen++;
        }else{
            currLen=1;
        }
        maxLen = max(maxLen,currLen);
        i++;
    }
    cout<<maxLen<<"\n";
    return 0;
}