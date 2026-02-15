#include <iostream>
#include <climits>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int prices[n];
    for(int i=0;i<n;i++){
        scanf("%d",&prices[i]);
    }
    int maxProfit = 0;
    int profit = 0;
    int minPrice = INT_MAX;
    int i=0;
    while(i<n){
        if(prices[i]<minPrice){
            minPrice = prices[i];
        }
        profit = prices[i]-minPrice;
        maxProfit = max(maxProfit,profit);
        i++;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         profit = prices[j]-prices[i];
    //         maxProfit = max(profit,maxProfit);
    //     }
    // }

    printf("%d\n",maxProfit);


    return 0;
}