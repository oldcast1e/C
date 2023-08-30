#include  <stdio.h>
int main(){

    int n,dn,k;//
    int cnt,cntsum;
    int maxcntnum=-1,mincntum=-1,maxcnt;
    int mincnt = 100000,mincntnum=-1;

    int rst1=0,rst2=100000;//소인수 최대 개수
    //1. 각 정수를 소인수 분해한 결과

    //2(1). 가장 많은 소인수를 포함하고 있는 정수(maxcntnum)
    //2(2).가장 적은 소인수를 포함하고 있는 정수(mincntum)

    //단. 포함된 소인수의 개숙가 같은 경우,
    //가장 많은 소인수를 포함한 정수 -> 가장 작은 수
    //가장 적은 소인수를 포함한 정수 -> 가장 큰 수
    while(1){
        scanf("%d",&n);
        if(n<1)
            break;
        else{
            while(1){

                dn = 2;
                cnt = 0;
                cntsum=0;
                maxcnt =1;
                k = n;

                if(n%dn==0){
                    cnt +=1;
                    n/=dn;
                }
                else{
                    // printf("%d ",dn);
                    // printf("%d ",cnt);
                    dn +=1;
                    cntsum += cnt;
                    maxcnt *= (cntsum+1);//소인수 개수
                    
                    cnt =0;
                    if(n>=1)
                        break;
                }
            }
            if(maxcnt>rst1){
                rst1 = maxcnt;
                maxcntnum = k;//소인수 개수가 가장 많은 수
            }
            if(maxcnt<rst2){
                rst2 = maxcnt;
                mincntnum = k;

            }

        }
    
    }
    printf("%d %d",maxcntnum,mincntnum);
}


