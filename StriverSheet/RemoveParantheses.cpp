#include <iostream>
#include <vector>
using namespace std;

string RemoveParantheses (string str){
    vector<int>store;
    string result = "";
    int level = 0;
    for(int i =0;i<str.length();i++){
        if(str[i]=='('){
            level++;
            if(level>1){
                result+= '(';
            }

        }if(str[i]== ')'){
            level--;
            if(level>0){
                result+=')';
            }
        }

    }
    return result;
}
int main(){
    string str = "((()))";
    string s = RemoveParantheses(str);
    cout<<s;

}