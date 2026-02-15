#include <iostream>
#include <vector>
using namespace std;
int findCoins(int V,int arr[],int n){
     int count = 0;
     for(int i = n-1;i >= 0;i++){
       count+=V/arr[i];//70 right so 70/50 first then we get 70/50 = 1 so one 50 coin then remainder will be the remaining remainder left so that if V
       V = V%arr[i];
     }
     return count;
}
int main(){
    int V;
    cin>>V;
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << findCoins(V,arr,n);
    return 0;

}
