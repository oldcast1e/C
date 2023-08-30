#include  <stdio.h>
int main(){

    int n,k,rvs,cnt,rst;
    int renum,total;

    int max=-1,min=999999;
    while(1){
        
        rvs=0,cnt=0,rst=0;
        renum=0,total=0;

        scanf("%d",&n);
        if(n==0)
            break;
        k = n;
        while(k>0){//역수 구하는 코드
            rvs += k%10;
            cnt++;
            k/=10;
            if(k<=0)
                break;
            rvs *=10;
        }
        for(int i=0;i<cnt;i++){
            n*=10;
        }//역수의 자리수만큼 n에 10을 곱함
        rst = n+rvs;//결과값
        if(rst>max)
            max = rst;
        if(rst<min)
            min = rst;
        printf("%d ",rst);
        while(rst>0){
            renum = rst%10;
            if(renum == 3){
                total +=1;
            }
            rst /=10;
        }
        printf("%d ",total);


    }
    printf("\n%d %d",min,max);
    
}