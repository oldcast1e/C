#include  <stdio.h>
int main(){
    int n,m,k,rvs=0,rst=0;
    int max=-1,min;
    int cnt=0,tn,tncnt;
    while(1){
        scanf("%d",&n);
        rvs = 0;
        rst = 0;

        tncnt = 0;
        tn = 0;

        if(n==0)
            break;

        else{
            m = n;//
            k = n;//
            while(m>0){//n의 역수
                rvs += m%10;
                rvs *=10;
                m/=10;
            }
            rvs /=10;//역수 결과값
            rst += n;//기본값
            while(k>0){
                rst*=10; 
                k/=10;
            }
            rst += rvs;//결과값
        }

        tn = rst;
        while(tn>0){
            if(tn%10==3)
                tncnt ++;
            tn /=10;
        }
        printf("%d %d ",rst,tncnt);


        if(cnt==0){
            min=rst;//첫번째 반복에서 최솟값을 첫번째 결과값으로
            cnt ++;
        }

        if(rst>max)
            max = rst;
        if(rst<min)
            min = rst;

    }
    printf("\n");
    printf("%d %d",min,max);
    
}