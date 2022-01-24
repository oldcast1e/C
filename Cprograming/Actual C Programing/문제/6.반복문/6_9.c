#include  <stdio.h>
int main() 
{
    int n,firstrst=0;
    int cnt;


    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        firstrst +=i;
        if(i==n)
            break;
        firstrst *= 10;
    }
    int secondrst=firstrst;
    
    
    for(int i=1;i<=n;i++){

        if((2*n-1)%i==0){
            firstrst=(secondrst-(secondrst%10))/10;//4자리수로 만듦.
            cnt = secondrst%10;

            for(int i=1;i<n;i++){
                cnt *= 10;
            }
            secondrst = firstrst+cnt;
            // firstrst += (secondrst%10)
            printf("%d\n",secondrst);
            firstrst = secondrst;
            cnt = 0;
            
        
        }
        else if((2*n)%i==0){

            secondrst = (firstrst-(firstrst%10))/10;
            cnt = firstrst%10;
            for(int i=1;i<n;i++){
                cnt *= 10;
            }
            firstrst = secondrst+cnt;
            printf("%d\n",firstrst);
            secondrst = firstrst;
            cnt = 0;

            
        }
        
    }

}