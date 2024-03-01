#include<stdio.h>
int main(void){
    
    int cnt = 0;
    char ipt[100];
    // scanf("%s",ipt);
    while(1){
        scanf("%c",&ipt[cnt]);
        if(ipt[cnt]=='\n') break;
        cnt ++;
    }
    // printf("%s",ipt);
    
    return 0;
}
