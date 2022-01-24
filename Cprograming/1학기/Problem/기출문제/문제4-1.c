#include  <stdio.h>
int main(){


   int N,T,n,key=0;
   int dN=0,dn=0,cnt;
   scanf("%d %d",&N,&T);
   for(int i=1;i<=N;i++){
        if(N%i==0)
        dN++;
    }//N의 약수의 개수

    while(1){
        scanf("%d",&n);
        dn=0;
        cnt = 1;
        if(n<=0){
            break;
        }
        else{
            for(int j=1;j<=n;j++){
                if(n%j==0)
                    dn ++;
            }

            if(dN==dn){
                printf("%d\n",n);
                key ++;
                continue;
            }
            else if(dn%T==0){
                printf("%d\n",n);
                key ++;
                continue;
            }
        }
    }
    if(key==0){
        printf("none");
    }
    
}