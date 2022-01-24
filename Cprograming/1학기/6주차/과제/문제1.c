#include  <stdio.h>
int main() 
{
    int n,m,sum=0,cnt,num=0;
    scanf("%d %d",&n,&m);
    while(num==0){
        if(n==m*(-1)){
                sum =0;
                break;
        }

        if(n*m<0){
            if(n>=m){
                for(int i=m*(-1)+1;i<=n;i++){
                    sum+=i;
                }
            }
        else{
            for(int i=(n*-1)+1;i<=m;i++){
                sum+=i;
            }  
        }
    }
    else{
        if(n>m){
            cnt = n;
            n = m;
            m = cnt;
        }
        for(int i=n;i<=m;i++){
            sum += i;
        }
    }

    }
    
    printf("%d",sum);
}

