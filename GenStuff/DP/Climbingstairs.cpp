#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
//Memoisation
// int findStairs(int n){
//     if(n==1) return 1;
//     if(n==2) return 2;
//     int ways = findStairs(n-1)+findStairs(n-2);
//     return ways;
// }
//Tabulation(without recursion:))
int findStairs(int n){
    int ways[n];
    for(int i=0;i<n;i++){
        ways[i]=0;
    }
    ways[1]=1;
    ways[2]=2;
    for(int i=3;i<=n;i++){
        ways[i]=ways[i-1]+ways[i-2];
    }
    return ways[n];
}
int main(){
    int n;
    scanf("%d",&n);
    cout<<findStairs(n);
    return 0;
}

