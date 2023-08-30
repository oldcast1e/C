#include  <stdio.h>

int key;//전역변수 key 선언(반복 조건:key가 1일때 반복횟수 증가 및 현재 숫자 반환 + 출력 조건)
int rstcnt = 0;//반복 횟수 ( 소수가 N만큼 출력)
int is_prime(int x){//is_prime함수 정의

    int num=0;//약수의 개수
    int key=0;//key값 초기화

    for(int i=1;i<=x;i++){//x만큼 반복하여
        if(x%i==0)//약수가 있으면
            num++;//약수의 개수 증가
    }
    if(num==2) key = 1;//약수의 개수가 2개이면 = 소수이면 key값을 1으로 (참으로)
    else key = 0;//아닌 경우 key값을 0으로 (거짓으로)
    
    return key;//key값 반환
}
int next_prime(int x){//next_prime함수 정의
    
    key = is_prime(x);//is_prime함수에서 반환된 값 저장
    if(key==1){//key가 1인 경우(참인 경우)
        rstcnt ++;//반복횟수를 증가
        return x;//x반환
    }
    return 0;//아닌 경우 0반환
        
}
int main(){
    
    int N,M,k;//입력받을 정수 N,M과 next_prime에서 반환값 k
    scanf("%d %d",&N,&M);//두개의정수를 입력받음

    while(1){//무한루프
        if(rstcnt==M)//출력횟수가 M과 같은 경우
            break;//종료(종료조건)
       
        k = next_prime(N+1);//next_prime의 반환값 저장
        if(k!=0)//k==1이면(참이면)
            printf(" %d",k);//해당 숫자를 출력
        N++;//분석할 숫자를 증가
    }

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
