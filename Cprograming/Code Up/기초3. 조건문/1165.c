#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c;
    float d,e,f;
    
    // scanf("%d",&a);
    scanf("%d %d",&a,&b);
    int time = a, score = b;
    while (time < 90){
        score += 1;
        time += 5;
    }
    
    printf("%d",score);
 
} 