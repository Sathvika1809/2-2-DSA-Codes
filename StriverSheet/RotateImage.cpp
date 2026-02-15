#include <iostream>
#include <vector>
using namespace std;
vector<int> findLeader(vector<int>vec){
    vector<int>ans;
    ans.push_back(vec[vec.size()-1]);
    int min = vec[vec.size()-1];
    for(int i = vec.size()-1;i>=0;i--){
        if(vec[i]>min){
            ans.push_back(vec[i]);
            min = vec[i];
        }
    }
    return ans;
}




int main(){
    vector<int>vec = {10,22,12,3,0,6};
    vector<int>temp = findLeader(vec);
    for(int i:temp){
        cout<<i<<" ";
    }




}