#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10000
int topIdx = -1;
char strStack[MAX][MAX];
int intStack[MAX];
void push(char* str,int val){
    topIdx++;
    strcpy(strStack[topIdx],str);
    intStack[topIdx] = val;
    return;
}
void pop(char* str,int* num){
    strcpy(str,strStack[topIdx]);
    *num = intStack[topIdx];
    topIdx--;
}

int main(){
    int n;
    scanf("%d",&n);
    char s[MAX];
    scanf("%s",s);
    char curr[MAX] = "";
    int num = 0;
    for(int i=0;s[i]!='\0';i++){
        char c = s[i];
        if(isdigit(c)){
        num = num*10+(c-'0');
        }
        else if(s[i]=='['){
            push(curr,num);
            strcpy(curr,"");
            num = 0;
        }else if(s[i]==']'){
            char prev[MAX];
            int k;
            pop(prev,&k);
            char temp[MAX]="";
            for(int j=0;j<k;j++){
                strcat(temp,curr);
            }
            strcpy(curr,prev);
            strcat(curr,temp);
        }else{
            int len = strlen(curr);
            curr[len] = c;
            curr[len+1]='\0';
        }
    }
    printf("%s\n",curr);

    return 0;
}