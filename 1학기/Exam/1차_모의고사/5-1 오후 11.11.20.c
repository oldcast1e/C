#include  <stdio.h>
int main(){
    int N,M;
    int num;
    int cnt,key=0;
    int cntnum = 0;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        cnt =0;
        scanf("%d",&num);
        for(int j=1;j<=num;j++){
            if(num%j==0)
                cnt++;
        }
        if(cnt==2){//소수이면
            if(cntnum<M){
                printf(" %d",num);
            }
            cntnum++;
        }
        else{
            key++;
        }
        
        
            
    }
    if(key==N){
        printf("%d",0);
    }
}


