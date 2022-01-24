#include  <stdio.h>
int main() 
{
    char u;
    int n;
    scanf("%c%d",&u,&n);
    if(97<=u && u<=122){
        u = u+n>122?(u+n)%122+96:u+n;
        printf("%c",u);
    }
    if(65<=u && u<=90){
        u = u+n>90?(u+n)%90+64:u+n;
        printf("%c",u);
    }
    else
        printf("%c",u);
    


}