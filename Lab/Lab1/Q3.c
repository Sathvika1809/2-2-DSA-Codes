#include <stdio.h>

int wordCount(char* s);
int vowelCount(char* s);
void reverse(char* s);
int isVowel(char ch);
int wordCount(char* s){
    int i = 0;
    int wordCnt = 1;
    while(s[i]!='\0'){
        char ch = s[i];
        if (ch==' ') {
            wordCnt++;
        }
        i++;
    }
    return wordCnt;
}
int isVowel(char ch){
    if(ch>='A'&&ch<='Z'){
        ch = (ch-'A'+'a');
    }
    return (ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u');
}
int vowelCount(char* s){
    int i=0;
    int vowelCnt=0;
   while(s[i]!='\0'){
     if(isVowel(s[i])){
        vowelCnt++;
     }
     i++;
   }
   return vowelCnt;
}
void reverse(char* s){
    int len = 0;
    int i = 0;
    while(s[i]==' '){
        i++;
    }
    while(s[i]!='\0'){
        len++;
        i++;
    }
    int left = 0;
    int right = len-1;
    while(left<right){
       char c = s[left];
       s[left] = s[right];
       s[right] = c;
       left++;
       right--;
    }
    printf("Reversed: %s ",s);
}
int main(){
    char str[1000];
    scanf("%[^\n]%*c",str);
    printf("Words: %d\n",wordCount(str));
    printf("Vowels: %d\n",vowelCount(str));
    reverse(str);
    return 0;
}