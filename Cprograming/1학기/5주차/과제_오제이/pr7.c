#include<stdio.h>
int main(){
    
    int N,a,b;
    scanf("%d",&N);
    scanf("%d",&a);
    if(N>a){
        printf("UP\n");
        scanf("%d",&b);
        if(N>b)
            printf("UP");
        else if(N<b)
            printf("DOWN");
        else
            printf("RIGHT");  
    }
    else if(N<a){
        printf("DOWN\n");
        scanf("%d",&b);
        if(N>b)
            printf("UP");
        else if(N<b)
            printf("DOWN");
        else
            printf("RIGHT");
    }
    else 
        printf("RIGHT");

    }
    

