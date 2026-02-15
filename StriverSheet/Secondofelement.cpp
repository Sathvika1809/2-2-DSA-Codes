#include <iostream>
using namespace std;
int secondlargest(int arr[],int n){
    int max = arr[0];
    int second = 0;
    for(int i=0;i<n;i++){
        if(arr[i]>max){
            second = max;
            max = arr[i];
          
        }else if(arr[i]>second){
            second = arr[i];
        }
        
    }
    return second;
    
}
int secondsmallest(int arr[],int n){
    int min = arr[0];
    int secondsmall = 0;
    for(int i =0;i<n;i++){
        if(arr[i]<min){
            secondsmall = min;
            min = arr[i];
            
        }else if(arr[i]<secondsmall){
            secondsmall = arr[i];
        }
    }
    return secondsmall;
}




int main(){
    int arr[] = {3,8,4,2,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int a = secondsmallest(arr,size);
    int b = secondlargest(arr,size);
    cout<<a<<" "<<b<<" "<<endl;

}