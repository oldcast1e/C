#include  <stdio.h>
int main(){

    char str[6];
    scanf("%s",str);
    printf("%s\n",str);
    str[5] = '?';
    printf("%s",str);

}