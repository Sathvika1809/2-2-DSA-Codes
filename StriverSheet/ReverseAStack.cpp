#include <iostream>
#include <stack>
using namespace std;
void insertAtBottom(stack<int>&s,int val){
    if(s.empty()){
        s.push(val);
        return;
    }
    int temp = s.top();
    s.pop();
    insertAtBottom(s,val);
    s.push(temp);

}
void reverseStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,temp);

}
int main(){
    stack<int>s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
     reverseStack(s);
    cout<<"After Reversing the stack"<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;

}