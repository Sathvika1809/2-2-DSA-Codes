#include<stdio.h>
#include <stdlib.h>
char* toString(int n){
    int k = 0;
    char* res = (char*)calloc(1000,sizeof(char));
    while(n>0){
        res[k++] = (n%10)+'0';
        n/=10;
    }
    for(int i = 0;i<k/2;i++){
        char ch = res[i];
        res[i] = res[k-i-1];
        res[k-i-1] = ch;
    }
    return res;
}
int main(){
    char s[1000];
    scanf("%s",s);
    char outp[1000];
    int i = 0,k = 0;
    while(s[i]!='\0'){
        int j = i+1;
        while(s[j]!='\0'&&s[j]==s[i]){
            j++;
        }
            outp[k++] = s[i];
            char *st = toString(j-i);
            int x = 0;
            while(st[x]!='\0'){
                outp[k++] = st[x++];
            }
            free(st);
            i=j;
        }
    outp[k] = '\0';
    if(k<=i){
        printf("%s",outp);
    }else{
        printf("%s",s);
    }

}