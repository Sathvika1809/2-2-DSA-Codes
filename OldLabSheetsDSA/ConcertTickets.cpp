#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int h[n];
    for(int i=0;i<n;i++){
        scanf("%d",&h[i]);
    }
    int price[m];
    for(int i=0;i<m;i++){
        scanf("%d",&price[i]);
    }
    maxPriceExceed(n,m,h,price);
    return 0;
}

// int upperbound(int* arr,int n,int x){
//     int low = 0;
//     int high = n-1;
//     int ans = -1;
//     while(low<=high){
//         int mid = low+(high-low)/2;
//         if(arr[mid]<=x){
//             ans = mid;
//             low = mid+1;
//         }else{
//             high = mid-1;
//         }
//     }
//     return ans;
// }
// void removeticket(int* arr,int* n,int idx){
//     for(int i = idx;i<(*n)-1;i++){
//         arr[i]=arr[i+1];
//     }
//     (*n)--;
// }
void maxPriceExceed(int n,int m,int* h,int* price){
    multiset<int>s;
    sort(h,
      
}