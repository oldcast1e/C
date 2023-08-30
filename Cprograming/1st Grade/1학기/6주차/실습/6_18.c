#include  <stdio.h>
int main() 
{
    double n,sum=0,cnt=0;
    double avg = 0;

    while(1){//무한반복
        scanf("%lf",&n);//입력받음
        if(n<=0){//0보다 작거나 같으면 코드 종료
            break;
        }
        if(n<=100){//100보다 작으면
            sum += n;//합에 n을 더함
            cnt ++;//카운트를 올림
        }
        else{//100보다 작지 않은경우
            continue;//계산에 포함하지 않음
        }
            
            
    }
    avg = sum/cnt;//평균
    printf("%d %.2f %d",(int)sum,avg,(int)cnt);//합,평균,개수 출력
}

