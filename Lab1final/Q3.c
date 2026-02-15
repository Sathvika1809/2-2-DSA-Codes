#include <stdio.h>
#include <stdlib.h>
int isVowel(char ch){
    if(ch>='A'&&ch<='Z'){
        ch = (ch-'A'+'a');
    }
    return ((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'));
}
void reverse(char* s){
    int len = 0;
    int i=0;
    while(s[i]!='\0'){
        len++;
        i++;
    }
    for(int i=0;i<len/2;i++){
        char ch = s[i];
        s[i]=s[len-i-1];
        s[len-i-1]=ch;
    }
    printf("%s\n",s);

}
int main(){
    char inp[1000];
    scanf("%[^\n]%*c",inp);
    int words = 1;
    int vowels = 0;
    int i=0;
    while(inp[i]!='\0'){
        char ch = inp[i];
        if(ch==' '){
            words++;
        }
        else if(isVowel(ch)){
            vowels++;
        }
        i++;
    }
    reverse(inp);
    printf("Words: %d\n",words);
    printf("Vowels: %d",vowels);

    return 0;
}