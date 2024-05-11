#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
    char str[1000];
    // gets(str); 
    scanf("%[^\n]s", str);
    int cnt = 0;
    for(int i=0;i<strlen(str);i++){
        char c = str[i];
        // printf("%c",c);
        if(c == '(' || c == '{' || c == '['|| c == ')' 
            || c == '}' || c == ']') cnt ++;
    }
     printf("%d",cnt);
    
}
//3*{4+(2-792)/1} + [3*{4-2* (100 -7)}]