#include <stdio.h>

int main(){

    int u,m,l;
    int a,b,k;
    scanf("%d",&u);
    if(u==1){
        printf("Americano\n");
        scanf("%d",&m);
        l = m - 500;
        a = l/500;
        k = l%500;
        b = k/100;
        printf("%d %d",a,b);
    }

    else if(u==2){
        printf("Cafe Latte\n");
        scanf("%d",&m);
        l = m - 400;
        a = l/500;
        k = l%500;
        b = k/100;
        printf("%d %d",a,b);
    }

    else if(u==3){
        printf("Lemon Tea\n");
        scanf("%d",&m);
        l = m - 300;
        a = l/500;
        k = l%500;
        b = k/100;
        printf("%d %d",a,b);
    }
}