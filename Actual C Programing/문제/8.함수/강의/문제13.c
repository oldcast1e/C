#include  <stdio.h>

int count_3(int x){//count_3함수 정의
    int cnt = 0,k;//3이 나오는 횟수 저장 변수 cnt와 i값 저장 변수 k
    for(int i=1;i<=x;i++){//x번 반복하여
        if(i<10){//i가 1자리인경우
            if(i%10==3)//i=3이면
                cnt++;//cnt 증가
        }     
        else{//아닌 경우
            k = i;//k에 i 저장
            while(k>0){//k가 0보다 클때 동안 반복
                if(k%10==3)//k%10이 3이면
                    cnt++;//cnt증가
                k/=10;//10으로 나눔(13,33같은 숫자에서 3 도출)
            }
        }
    }
    return cnt;//3이 나온 횟수를 반환
}
int main(){
    
    int N,rst;
    scanf("%d",&N);
    rst = count_3(N);
    printf("%d",rst);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
