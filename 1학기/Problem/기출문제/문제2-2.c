#include  <stdio.h>
int main(){

    char u,min1='z',min2='z';

    while(1){
        scanf("%c",&u);
        if('A'<=u && u<='Z')
            break;
        else{
            if(u<min1){
                min2 = min1;
                min1 = u;
            }
            if(u>min1 && min2>u)
                min2 = u;

        }
    }
    printf("%c%c",min1,min2);

    return 0;
}