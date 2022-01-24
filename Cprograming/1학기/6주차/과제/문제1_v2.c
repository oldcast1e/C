#include<stdio.h>
int main(){
    
    int n,m,cnt,a,b;
    int sum=0,var=0;
    scanf("%d %d",&n,&m);
    if(n>m){
        if(n>0)
            m = (m>0?m:m*(-1)+1);
        for(int i=m;i<=n;i++){
            sum+=i;
            printf("%d\n",sum);
            }
    }
    else if(n<m){
        if(n>0){
            for(int i=n;i<=m;i++){
                sum+=i;
                printf("%d\n",sum);
            }
        }
        else if(n<0){
            if(m>0){
                for(int i=n*(-1)+1;i<=m;i++){
                    sum+=i;
                    printf("%d\n",sum);
                }
            }
            else{
                for(int i=n;i<=m;i++){
                    sum+=i;
                    printf("%d\n",sum);
                }
            }
        }
        else{
            for(int i=n;i<=m;i++){
                    sum+=i;
                    printf("%d\n",sum);
                }
        }
    }
    else
        sum =0;
    
    printf("%d",sum);
    
}