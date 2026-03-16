#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int topIdx = -1;
int isEmpty(float* stk){
     return topIdx==-1;
}
void push(float* stk,float x){
    stk[++topIdx] = x;
}
void pop(float* stk){
    if(!isEmpty(stk)) topIdx--;
}
float top(float* stk){
    if(!isEmpty(stk)){
    return stk[topIdx];
    }
    return -1;
}

int main(){
    char str[10000];
    scanf("%s",str);
    float stk[MAX];
    int i=0;
    int ie = 0;
    while(str[i]!='\0'){
        char c = str[i];
        if(c =='+'||c=='-'||c=='*'||c=='/'){
            if(topIdx == -1||topIdx == 0){
                printf("Invalid Expression\n");
                ie = 1;
                break;
            }
            float two = top(stk);
            pop(stk);
            float one = top(stk);
            pop(stk);
            float val = 0;
            if(c == '+'){
                val = one+ two;
            }else if(c == '-'){
                val = one-two;
            }else if(c == '*'){
                val = one* two;
            }else{
                if(two == 0){
                    printf("Invalid Expression\n");
                    ie = 1;
                    break;
                }else{
                    val = one/two;
                }
            }
            push(stk,val);
        }else{
            float val = str[i]-'0';
            push(stk,val);
        }
        i++;
    }
    if(!ie && topIdx == 0){
        printf("%.2f",top(stk));

    }else if(!ie){
        printf("Invalid Expression\n");
    }
    return 0;
}