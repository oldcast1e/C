#include  <stdio.h>

void gcdlcm(int n,int m,int *p1,int *p2){//gcdlcm함수 선언

    int small = (n<m?n:m);//n과 m중 작은 값을small에 저장
    int large = (n<m?m:n);//n과 m중 큰 값을large에 저장
    int a,b;//두개의 변수 선언
    //최소공배수
    for(int i=small;i>=1;i--){//small부터 1까지 반복
        if(small%i==0 && large%i==0){//입력받은 두개의 변수의 공통된 약수이면
            a = i;//a에 저장
            // printf("a");
            break;//반복 종료
        }
    }
    int cnt = large;//최대값을 cnt에 저장
    while(1){//무한 반복
        if(cnt%large==0 && cnt%small==0){//두개의 변수와 공배수 관계이먄
            b = cnt;//b에 저장하고
            break;//반복 ㅈㅇ료
        }
        // printf("b");
        cnt ++;
    }
    *p1 = a,*p2=b;//포인터에 각각의 값을 저장
   

}

int main(){//메인 함수 선언
    
    int n,m;//두개의 변수 선언
    int *p1 = &n,*p2 = &m;//포인터 선언
    scanf("%d %d",&n,&m);//2개의 값을 입력받음
    gcdlcm(n,m,p1,p2);//함수 실행
    printf("%d %d",*p1,*p2);//결과값 출력
   
      

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

