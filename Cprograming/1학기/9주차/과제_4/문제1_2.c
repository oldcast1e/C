#include  <stdio.h>
int main(){
    
    int N,gamekey=1;//게임횟수,게임조건 변수 선언
    int score[100];//게임 점수 저장 배열
    scanf("%d",&N);//횟수 입력
    if(N<1 || N>100){//N이 조건에 충족하지 않으면,
        gamekey = 0;//게임조건 값을 0으로 만들고(0이면 게임을 실행하지 않도록함)
        printf("ERROR");//ERROR를 출력
    }
    if(gamekey == 1){//게임 조건이 참이면
        for(int i=0;i<N;i++){//게임 횟수만큼
            scanf("%d",&score[i]);//값을 입력받는다.
            if(score[i]>100 || score[i]<0){
                gamekey = 0;//이때, 점수의 값이 유효하지 않으면
                printf("ERROR");//ERROR를 출력하고 게임 조건값을 0으로 바꾼후
                break;//(ㄱ) 반복문 탈출
            }       
    }
    while (gamekey==1){//(ㄱ)
        //////////
    
        if (N==1) break;//N이 1이되면 반복을 종료한다.
        for (int i = 0; i < N; i += 2) { //2개씩 짝지어서 판별
            if (score[i] >= score[i + 1]) { //점수 비교  (ㄴ)
                printf("%d ", score[i]);//더 큰 값을 출력한다.
                score[i/2] = score[i];//순서 변경
                score[i / 2 + 1] = 0; //다음 값 초기화
            }
            else{ //점수 비교
                printf("%d ", score[i+1]);//더 큰 값을 출력한다.   (ㄷ)
                score[i/2] = score[i+1];//순서 변경
                score[i / 2+1] = 0; //다음 값 초기화
            }           
        }
        printf("\n");
        
        if(N%2==0)//짝수 일때
            N /= 2;//다음 비교해야 할 횟수로 바꾼다.
        else N = N / 2 + 1; //홀수 일때
  

        }

}
}

