#include <iostream>
#include <stack>
using namespace std;
void sortstack(stack<int>s){
    if(!s.empty()){
        temp = s.top();
        s.pop();
        sortstack(s);
        insert(s,temp);
    }
}
void insert(stack<int>s,int temp){
    if(s.empty()||s.top()<=temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    insert(s,temp);
    s.push(val);
    
}



int main(){
    stack<int>nums = {4,1,3,2};
    sortstack(nums);
    cout<<"Sorted Stack (descending order)";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;

}