#include  <stdio.h>
void input(int *p, int M){//input함수 선언
    for(int i=0;i<M;i++){//M번 반복하여
        scanf("%d",(p+i));//정수를 입력받음
    }
}
int *sel_max(int *in,int M){//sel_max함수 선언 - 포인터 반환

    int num,cnt,rst=0;//정수형 변수 및 매개 변수 선언
    int maxcnt=0;//최대 반복횟수 
    for(int j=0;j<M;j++) if(*in == *(in+j)) maxcnt ++;//최대반복횟수 초기화
    
    for(int i=1;i<M;i++){//m-1번 반복: i=0일때는 빼기
        cnt = 0;//반복횟수 초기화
        for(int j=0;j<M;j++){//M번 반복
            if(*(in+i) == *(in+j)) cnt ++;//같은 수가 나오면 반복횟수 증가
        }
        if(cnt>maxcnt){//최대반복횟수보다 크면
            maxcnt = cnt;//업데이트
            rst = i;//주소 저징 매개변수 업데이트
        }
    }
    return in+rst;//출력할 정수 위치 반환
}
void output(int *p, int N){//여기서 포인터는 맥스 = 최대값의 위치
    for(int i=0;i<N;i++){//N번 반복
        printf(" %d",*(p+i));//출력
    }
    
}
int main(void){//메인함수
    int in[100], out[100], *max, i, N, M;
    //두개의 배열과 최대값 주소 변수 및 매개변수 선언ㅇ
    scanf("%d %d", &N, &M); //두 정수형 변수 입력받음
    for (i=0; i<N; i++){//N번 반복하여
        input(in, M); //입력함수 실행
        max = sel_max(in, M); //최대값 주소 저장
        out[i] = *max;
    }
    output(out, N); return 0;//결과출력
}
/*
3 5 
1 2 2 1 3
2 4 2 4 3
1 2 3 4 5
*/