#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n-1];
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
    }
    int tot = n*(n+1)/2;
    int totArr=0;
    for(int i=0;i<n-1;i++){
        totArr+=arr[i];
    }
    cout<<tot-totArr<<"\n";
    return 0;
}