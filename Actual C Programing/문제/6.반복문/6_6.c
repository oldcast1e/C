#include  <stdio.h>
int main() 
{
    int n,sum1=0,sum2=0;
    char now;
    int max1=0,max2=0;
    int bef1=0,bef2=0;
    scanf("%d",&n);
    while(n>0){

        scanf("%c",&now);

        if(97<=now && now<=122){
            sum1 +=1;
            scanf("%c",&now);
            while(97<=now && now<=122){
                scanf("%c",&now);
                sum1 +=1;
            }
            if(max1<=sum1){
                bef1 = sum1;
                max1 = sum1;
            }
            
        }
        else{
            while(97>now || now>122){
                sum2 +=1;
                scanf("%c",&now);
            }
            if(max2<=sum2){
                bef2 = sum2;
                max2 = sum2;
            }
        }
        
        n--;
        
    }
    printf("%d\n",max1);
    printf("%d",max2);
}
    
    

