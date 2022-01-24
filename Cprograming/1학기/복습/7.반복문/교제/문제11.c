#include  <stdio.h>
int main(){
    
    int n,cnt=1;
    scanf("%d",&n);

    for(int i=1;i<=2*n-1;i++){

        if(i==1 || i ==2*n-1){//첫번째 줄 아니면 마지막 줄
            for(int s=0;s<n-1;s++){
                printf(" ");
            }
            printf("%d",1);
            printf("\n");
        }
        
        else if(i==n){//가운데 줄

            for(int j=n;j>=1;j--)
                printf("%d",j);
            for(int j=2;j<=n;j++)
                printf("%d",j);

            printf("\n");
        }

        else{
            if(i<n){
                for(int s=0;s<n-i;s++){
                    printf(" ");
                }
                for(int j=i;j>=1;j--)
                    printf("%d",j);
                for(int j=2;j<=i;j++)
                    printf("%d",j);
                
                printf("\n");
            }
            else{
                for(int s=0;s<cnt;s++){
                    printf(" ");
                }

                for(int j=n-cnt;j>=1;j--)
                    printf("%d",j);
                for(int j=2;j<=n-cnt;j++)
                    printf("%d",j);
                cnt++;
                printf("\n");
            }
        }



        
    }
}
