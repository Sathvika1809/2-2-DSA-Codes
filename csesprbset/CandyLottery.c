#include <stdio.h>
#include <math.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
/*
P(X<=x)=x/k;
child->independent->P->(x/k)^n;
P(M=x)=P(M<=x)-P(M<=x-1)=(x/k)^n-(x-1/k)^n
E(x)=(sigma)P(M=x).x
*/
double ans = 0.0;
for(int x=1;x<=k;x++){
double p1 = pow((double)x/k,n);
double p2 = pow((double)(x-1)/k,n);
double prob = p1-p2;
ans+=x*prob;
}
printf("%.6f",ans);



    return 0;
}