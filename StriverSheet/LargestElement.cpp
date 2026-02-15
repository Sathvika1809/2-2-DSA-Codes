#include <iostream>
using namespace std;

int largestelement(int arr[],int n){
    int max = arr[0];
    for(int i = 1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int arr[] ={3,2,7,4,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    int a = largestelement(arr,size);
    cout<<a<<endl;
}