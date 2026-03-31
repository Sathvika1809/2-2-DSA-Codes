#include <bits/stdc++.h>
using namespace std;
//Using Tabulation
// int tribonacci(int n){
//     int T[n+1];
//     for(int i=0;i<=n;i++){
//         T[i]=0;
//     }
//     T[0] = 0;
//     T[1] = 1;
//     T[2] = 1;
//     for(int i=3;i<=n;i++){
//         T[i]=T[i-1]+T[i-2]+T[i-3];
//     }
//     return T[n];
// }
//Using Recursion:(
int tribonacci(int n){
    if(n==0||n==1) return n;
    if(n==2) return 1;
    int ways = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    return ways;
}
int main(){
    int n;
    scanf("%d",&n);
    cout<<tribonacci(n)<<endl;
    return 0;
}