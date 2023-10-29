
#include<stdio.h>
 
 
int main(){
    
    int num,k;
    scanf("%d %d", &num, &k);
    
    for(int i = 1; i<= num; i++){ 
        for(int j = 1; j<=num; j++){        
            if( (i == 1) || (j == 1) || (i == num) || (j == num)  ){
                printf("*");
            }
            else if ( k == 1){
                printf("*");
            }
            else if( (i + j)%k  == 1 ){
                printf("*");
            }
            else{
                printf(" ");
            }
            //printf("%d",m);
        }
        printf("\n");
        
        
    }
    
    return 0;
}
/*
**********
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
* *  *  **
**  *  * *
*  *  *  *
**********

*/