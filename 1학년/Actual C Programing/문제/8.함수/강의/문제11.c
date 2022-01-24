#include  <stdio.h>

int ans[3],spn=0,inp[3];//정답을 저장할 배열ans과 입력값을 저장할 배열 inp, 그리고 줄띄움 변수 spn선언
int count_strike(int x,int y,int z){//count_strike함수 정의(스트라이크 횟수 파악)

    int stcnt = 0;//스트라이크 개수를 0으로 초기화
    for(int i=0;i<3;i++){//3번 반복하여
        if(ans[i]==inp[i])//같은 위치 같은 숫자인지 확인
            stcnt++;//같은 위치 같은 숫자인경우 스트라이크 개수를 증가
    }
    return stcnt;//스트라이크 횟수 반환
}
int count_ball(int x,int y,int z){//count_ball함수 정의(볼 개수 파악)
    int bacnt = 0;//볼 횟수를 0으로 초기화
    for(int i=0;i<3;i++){//3번 반복하여
        for(int j=0;j<3;j++){//3번 반복하여(같은 위치이면 안되므로)
            if(i!=j)//같은 위치가 아닌 경우
                if(ans[i]==inp[j])//값이 같은게 있으면
                    bacnt ++;//볼의 횟수를 증가
        }
    }
    return bacnt;//볼 횟수 반환
    
}
int main(){//main함수
    
    int x,y,z;//입력값을 저장할 3개의 변수 선언
    for(int i=0;i<3;i++){//3번 반복하여
        scanf("%d",&ans[i]);//정답을 입력받음
    }
    while(1){//무한 루ㅍ,
        for(int i=0;i<3;i++){//3번 반복하여
            scanf("%d",&inp[i]);//추측값을 입력받아 배열에 저장
        }
        x = inp[0],y=inp[1],z=inp[2];//추측값의 0,1,2값을 각각 x,y,z에 저장
        int str = count_strike(x,y,z);//count_strike에 x,y,z를 실행
        int bal = count_ball(x,y,z);//count_ball에 x,y,z를 실행
        printf("%dS%dB\n",str,bal);//스트라이크 값과 볼 값을 출력
        if(str==3)//스트라이크 개수가 3인 경우 반복문(코드) 종료
            break;
}

}