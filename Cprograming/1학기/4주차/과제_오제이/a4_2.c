#include  <stdio.h>
int main() 
{
    char u;
    int n;
    scanf("%c%d",&u,&n);
    if('a'<=u && u<='z'){
        if(u+n>122){
            u = ((u+n)%122)+96;
            printf("%c",u);
        }
        else
            printf("%c",u+n);
    }
    else if('A'<=u && u<='Z'){
        if(u+n>90){
            u = ((u+n)%90)+64;
            printf("%c",u);
        }
        else
            printf("%c",u+n);

    }
    else if(!('a'<=u && u<='z') && !('A'<=u && u<='Z'))
        printf("%c",u);
    


}