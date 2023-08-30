#include  <stdio.h>
int N,M;
int is_prime_number(int num){//is_prime_number함수 선언

    int n,cnt;// 입력받을 변수와 소수 개수 변수 선언
    int key  = 0;// 종료조건
    int anscnt = 0;//0출력 조건 값 초기화
    for(int i=0;i<num;i++){//num번 반복 실행

        if(key==M) break;//전역변수 M과 key의 값이 같으면 종료
        scanf("%d",&n);//정수를 입력받음
        cnt = 0;//소수의 개수 초기화
        for(int j=1;j<=n;j++){//입력받은 숫자만큼 반복
            if(n%j==0){//약수가 있다면
                cnt++;//중가
                
            }
        }
        if(cnt==2){//약수가 2개인 경우 = 소수인 경우
            printf(" %d",n);//해당 정수를 출력
            anscnt = 1;//0조건값을 1로 만듦= 1이면 출력 안함
            key ++;//반복 조건 플러스
        }
        if(i==num-1){//i가 마지막 수일때
            if(anscnt == 0) printf("%d",0);//0출력 조건이 0이면 0을 출력
        }
    }
    return 0;

}
int main(){
    
    
    scanf("%d %d",&N,&M);//N,M을 입력받음
    is_prime_number(N);//함수 실행
    
    
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가


//769812773 //9ㄱㅐ
//7 6 9 8 1 2 7 7 3
//7 4 5 3 7 1 8 9

//2100000000