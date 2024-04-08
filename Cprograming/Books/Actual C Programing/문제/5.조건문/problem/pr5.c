#include<stdio.h>
int main(){

    int n;
    char score;
    scanf("%d",&n);
    if(n%2==0){
        if(n%3==0)
            if(n%5==0)
                score = 'A';
            else
                score = 'B';
        else
            if(n%5==0)
                score = 'C';
            else
                score = 'E';
    }
    else   
        if(n%3==0)

            if(n%5==0)
                score = 'D';
            else
                score = 'E';
        else

            if(n%5==0)
                score = 'E';
            else
                score = 'N';
    printf("%c",score);

}