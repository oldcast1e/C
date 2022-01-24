#include  <stdio.h>
int main() 
{
    int n,i,j,k;//4개의 정수 선언
    scanf("%d",&n);//3~18사이의 정수 입력받음
    int a,b,c,cnt;//반복을 담당할 3개의 정수형 변수 선언
    for(a=1;a<=6;a++){//첫번째 주사위
        for(b=1;b<=6;b++){//두번째 주사위
            for(c=1;c<=6;c++){//3번째 주사위
            cnt =0;
                if(a+b+c==n){//3개의 주사위의 합이 n과 같은 경우
                    //뒤에 반복에도 합이 n이되는게 있으면 열을 띄움
                    for(k=a;k<=6;k++){
                        if(k==a){
                            for(i=b+1;i<=6;i++){
                                for(j=1;j<=6;j++){
                                    if(a+i+j==n)
                                        cnt ++;
                                } 
                            }
                        }
                        else{
                            for(i=1;i<=6;i++){
                                for(j=1;j<=6;j++){
                                    if(a+i+j==n)
                                        cnt ++;
                            } 
                            }
                        }
                        }
                    }
                            
                    }
                if(cnt>0)
                    printf("%d %d %d\n",a,b,c);
                else
                    printf("%d %d %d",a,b,c);
                    
                } 
                }
                
            }  
        

