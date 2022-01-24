#include<stdio.h>
int main(){

    int N,k=0;
    scanf("%d",&N);
    int a=1,b=N,cnt;
    while(k<N){

        if(a<b){
            
            for(int i=a;i<=b;i++){
             if(i==10)
                printf("%d",0);
            else
                printf("%d",i); 
            cnt +=1;
            if(cnt%N==0)
                    printf("\n");
            }
        }

        else{

            for(int i=a;i<=10;i++){
             if(i==10)
                printf("%d",0);
            else
                printf("%d",i); 
            cnt +=1;
            if(cnt%N==0)
                    printf("\n");
            }

            for(int i=1;i<=10;i++){
             if(i==10)
                printf("%d",0);
            else
                printf("%d",i); 
            cnt +=1;
            if(cnt%N==0)
                    printf("\n");
            }


        }
        
        

        a+=1;
        a = (a>10?1:a);
        b+=1;
        b = (b>10?1:b);


        k+=1;
    }

    
}
