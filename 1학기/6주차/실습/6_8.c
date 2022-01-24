#include<stdio.h>
int main(){
    
    int n,m,cnt=0,cnt2=1;//정수형 변수 4개 선언
    scanf("%d",&n);//n입력 받음
    m = n;//변수 m에 n을 저장_안씀
    

    while(cnt2<=n){//cnt2가 n보다 작거나 같은 경우

        for(int j=1;j<=10;j++){//행
            
            if(cnt2>n)//cnt2가 n보다 크면 종료
                break;

            if(j==10)//j==10이면 10말고 0출력
                printf("%d",0);
            else//나머지는 j출력
                printf("%d",j);
            cnt +=1;
            if(cnt%n==0){//정해진 행 만큼 출력하고 열을 바꾸는 코드
                cnt2 +=1;
                if(cnt2<=n)//cnt2가 nㅂ다 작거나 같으면
                    printf("\n");//열 바꿈
            }
            // printf("\ncnt2 : %d\n",cnt2);
        }
        

    }

    
}

