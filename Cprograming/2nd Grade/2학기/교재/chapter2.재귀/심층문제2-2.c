#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isPalindrome(char *str, int n){
    for(int i=0;i<n/2;i++){if(str[i] != str[n-1-i]) return 0;}
    return 1;
}

int risPalindrome(char *str, int len, int r){
    //현재 확인하는 값이 가운데 값을 가질때 종료
    if(r == len/2) return 1;
    
    if(str[r] != str[len -1 - r]) return 0;
    else return risPalindrome(str,len,r+1);
}

int main(){
    char str[100];
    scanf("%s",str);
    // if(isPalindrome(str,strlen(str))) printf("True");
    // else printf("False");

    if(risPalindrome(str,strlen(str),0)) printf("True");
    else printf("False");
}