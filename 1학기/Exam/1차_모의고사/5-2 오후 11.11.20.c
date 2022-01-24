#include  <stdio.h>
int main(){
    
    int N,n,sum,key=0;
    int cnt=0;//연속 횟수
    int maxcnt = -1,befnum,lastnum;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&n);
        sum = 0;
        if(n>100){
            cnt =0;
            maxcnt=0,lastnum=0;
        }
            
        else{
            for(int j=1;j<=n;j++){
                if(n%j==0)
                    sum++;
            }
            if(sum==2){
                cnt +=1;
                befnum = n;
            }
            else{
                if(cnt>maxcnt){
                    maxcnt = cnt;
                    lastnum = befnum;
                }
                cnt=0;
                key++;
            }
        }
    }
    if(key==15){
        printf("%d",0);
    }
    else{
        printf("%d\n%d",maxcnt,lastnum);
    }
    
}


