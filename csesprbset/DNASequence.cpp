#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    int maxLen = 1;
    int currLen = 1;
    for(int i = 0;i <s.length();i++){
        if(s[i]==s[i+1]){
            currLen++;
        }else{
            currLen = 1;
        }
        maxLen = max(maxLen,currLen);
    }
    printf("%d ",maxLen);
}