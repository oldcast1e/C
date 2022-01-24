#include  <stdio.h>
int main() 
{
    int N,U;
    scanf("%d",&N);

    while(N!=U){
        scanf("%d",&U);
        if(N>U)
            printf("UP\n");
        else if(N<U)
            printf("DOWN\n");
        else if(N==U){
            printf("RIGHT");
            break;
        }
    }
}
    
    

