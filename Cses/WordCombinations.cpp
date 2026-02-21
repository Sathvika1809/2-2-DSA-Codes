#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
const int mod = 1e9+7;
//For backtracking too many combinations-TLE(Recursion)
//Use dp[i]=no.of ways to form prefix S[0,....i-1]
//Base case dp[0]=1;//TLE because of substr
int main(){
    string s;
    cin>>s;
    int n = s.size();
    int k;
    cin>>k;
    vector<string>dict;
    for(int i=0;i<k;i++){
        string temp;
        cin>>temp;
        dict.push_back(temp);
    }
    vector<long long>dp(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
    for(string str:dict){
        int len = str.size();
        if(i>=len){
            if(s.substr(i-len,len)==str){
                dp[i]=(dp[i]+dp[i-len])%mod;
            }
        } 
    }
}
cout<<dp[n]<<"\n";


    return 0;
}