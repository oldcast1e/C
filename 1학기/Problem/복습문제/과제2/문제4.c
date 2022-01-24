#include  <stdio.h>
int main(){

    char u,rst;
    int n;
    scanf("%c %d",&u,&n);
    if('a'<=u&&u<='z'){
        if(n+u>'z')
            rst = (u+n)%'z'+'a'-1;
        else
            rst = n+u;
        printf("%c",rst);
    }
    else if('A'<=u&&u<='Z'){

        if(n+u>'Z')
            rst = (u+n)%'Z'+'A'-1;
        else
            rst = n+u;
        printf("%c",rst);
    }
    else
        printf("%c",u);
    
}