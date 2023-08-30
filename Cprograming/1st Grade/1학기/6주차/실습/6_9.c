#include<stdio.h>
int main(){

    int N,k=1;
    scanf("%d",&N);
    int a=1;
    int b=N;//10
    int cnt,num=0;
    
    while(N>k){
        
        for(int i=k;i<=b;i++){

            if(k<=N){
                if(i==10)
                    printf("%d",0);
            
                else
                    printf("%d",i);
                cnt +=1;
                if(cnt%N==0)
                    printf("\n");
            }
        }
        k+=1;
        b +=1; 
        for(int i=k;i<=b;i++){

            if(k<=N){
                if(i==10)
                    printf("%d",0);
            
                else
                    printf("%d",i);
                cnt +=1;
                if(cnt%N==0)
                    printf("\n");
            }
        }     
        k+=1;


    }

    
}
