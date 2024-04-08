#include  <stdio.h>
int main() 
{
    int n,i,j,k;//n = 4
    scanf("%d",&n);
    
    int r = 1;
    int cnt=1;

    int R = n-1;
    int CNT = n-1; 

    for(i=1;i<=2*n-1;i++){//열 1,2,3,4,5,6,7
        
        if(i<n){//i = 1,2,3
            for(j=n-i;j>0;j--){ //3~1=>3번 반복
                printf(" ");
            }//처음~n-1번째 줄 칸 띄우기(3칸 -> 2칸-> 1칸)

            if(i==1)//첫번째 열
                printf("%d\n",1);
            else{    //2,3번째 열
                for(k=i;k>1;k--){
                    printf("%d",k);
                }
                printf("%d",1);
                for(k=2;k<i+1;k++){
                    printf("%d",k);
                }
                printf("\n");
            }
            
        }
        else if(i==n){
            
            for(k=n;k>1;k--){
                    printf("%d",k);
                }

            printf("%d",1);

            for(k=2;k<=n;k++){
                printf("%d",k);
            }
            printf("\n");

        }

        else if(i>n){//n+1~끝번째 줄 칸 띄우기
            while(cnt>0){
                printf(" ");
                cnt --;
            }
            r++;
            cnt = r;

            if(i==2*n-1)//
                printf("%d\n",1);

            else{    //5,6,7번째 열(i)
                for(k=R;k>=2;k--){
                    printf("%d",k);
                }
                printf("%d",1);
                for(k=2;k<=CNT;k++){
                    printf("%d",k);
                }

                R--;
                CNT--;
                printf("\n");

            }
        }


    }


}



