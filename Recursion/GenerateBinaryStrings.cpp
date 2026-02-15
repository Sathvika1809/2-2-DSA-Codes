#include <iostream>
#include <vector>
using namespace std;
void binaryString(int n,string curr,vector<string>&result){
    if(curr.length()==n){
        result.push_back(curr);
        return;
    }
    //place 0
    binaryString(n,curr+"0",result);
    //Add 1
    if(curr.empty()||curr.back()!='1'){
        binaryString(n,curr+"1",result);
    }

}
int main(){
    int n;
    cin>>n;
    vector<string>result;
    binaryString(n,"",result);
    for(string s:result){
        cout<<s<<endl;
    }
}