#include  <stdio.h>
int main(){

   int N,M,cnt,dn;//dn 약수(2부터 시작)
   //maxcntnum:약수의 개수가 가장 큰 수
   //maxcnt:약수의 개수가 가장 큰 수의 약수의 개수
   //maxcntsum: 소인수 지수의 합
   scanf("%d %d",&N,&M);
   int maxcntnum=-1,maxcnt=-1,maxcntsum=-1;
   int n,m,r,divisum,cntsum; 
   while(N<=M){
       cnt = 0;
       divisum =1;//약수의 개수
       cntsum=0;

       dn = 2;
       n = N;

       r = N;
       while(n>0){
           if(n%dn==0){
               cnt++;
               n/=dn;
           }
           else{
               
               dn +=1;
               cntsum += cnt;
               divisum *= (cnt+1);
               cnt=0;
               if(n<=1)
                    break;
           }
       }
       if(divisum>maxcnt){
           maxcnt = divisum;
           maxcntnum=r;
           maxcntsum=cntsum;
       }

       N+=1;
   }
   printf("%d %d %d",maxcntnum,maxcnt,maxcntsum);

}