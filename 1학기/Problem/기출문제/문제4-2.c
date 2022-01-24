#include  <stdio.h>
int main(){

    int M,n,cnt,cnt2,numbercnt;
    scanf("%d",&M);
    int N,T,Tn,a,b,need;//need=T의 배수 조건 확인
    int Ndn=0,ndn=0;//Tn:T의 배수
    int ren;//n을 대신할 변수

    int key = 0;
    for(int i=1;i<=M;i++){
        cnt = 0;
        cnt2=1;
        numbercnt=0;
        need = 0;
    
        while(1){//2입력시 첫번째 줄과 두번째 줄
            scanf("%d",&n);
            if(n<=0)
                break;

            if(cnt==0){
                N = n;
                numbercnt ++;
                
            }
            if(cnt==1){
                T = n;
                Tn = T;
                numbercnt++; 
            }
            cnt++;//N과T구별
            ////////////

            a = N;
            for(int i=1;i<=a;i++){
                if(N%i==0)
                    Ndn++;//N의 약수
            }

            if(numbercnt>=2){//T를 찾은 후 코드 실행
                ndn = 0;//n의 약수 개수
                ren = n;///n대신할 변수
                for(int i=1;i<=ren;i++){
                    if(n%i==0)
                        ndn ++;
                }//n의 약수의 개수

                //-----------------
                // while(n>Tn){
                    
                //     Tn = T;
                //     if(n==Tn){
                //         need = 1;
                //         break;
                //     }
                //     Tn*=cnt2;
                //     cnt2 ++;
                // }

                //조건1. N과 약수의 개수가 같은 경우
                if(ndn == Ndn){
                    printf("%d ",n);
                    key=1;
                }
                //조건2. T의 배수인 정수중 가장 먼저 나오는 정수 == n
                else if(need>0){
                    printf("%d ",n);
                    key=1;
                }
          
                
            }
        }
        printf("\n");
        
    }
    if(key==0)
        printf("none");
    printf("%d %d\n",N,T);
    printf("%d %d %d",Ndn,ndn,numbercnt);
}