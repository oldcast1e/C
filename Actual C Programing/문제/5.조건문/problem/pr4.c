#include<stdio.h>
int main(){

    char u;
    scanf("%c",&u);
    if('A'<= u && u<='Z'){
        u +=32;
        printf("%c",u);
    }

    else if('a'<= u && u<= 'z'){
        u -=32;
        printf("%c",u);
    }
    else    
        printf("none");

}