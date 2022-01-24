#include  <stdio.h>
int main(){

    int n,m,max,rst=0;

    scanf("%d %d",&n,&m);//연산의 최적화
    int a=(n>0?n:n*(-1)),b=(m>0?m:m*(-1));//n과 m의 절댓값
    int minus = (a>b?a-b:b-a);

    max = a>b?n:m;
    //1번째: 두개의 부호가 같은 경우
    if(n*m>0){
        if(n!=m){
            for(int i=0;i<=minus;i++){
           
            if(n<0){
                rst += max + i;
            }
            else    
                rst += max -i;
            
            }
        }
        printf("%d",rst);
    }
    //2번째: 두개의 부호가 다른 경우
    else if(n*m<0){
        if(a>b){//1번째 숫자가 절대값이 더 큰 경우
            if(n<0){
                for(int i=0;i<minus;i++){
            rst += n + i;
        }
            }
            else{
                for(int i=0;i<minus;i++){
            rst += n - i;
        }
            }
        }
        else{
            for(int i=0;i<minus;i++){
                rst += m - i;
            }
        }
        printf("%d",rst);

        }
    else    
        printf("%d",0);
    

    }
