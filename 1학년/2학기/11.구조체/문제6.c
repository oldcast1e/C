#include  <stdio.h>
struct bodyscore{//구조체 정의
    /* data */
    int s,m,h;//성별 몸무게 키 정수형 변수 선언
}bs;//구조체 선언

int manscore(int m,int h){//몸무게와 키를 인자로 갖는 등급 함수: 남자
    int rank;
    if(60>m){//몸무게가 60보다 큰 경우
        if(165>h) rank = 1;//키가 165 보다 작은 경우 1등급
        else if(175>h) rank = 2;//키가 175 보다 작은 경우 2등급
        else rank = 3;//그 외 3등급
    }
    else if(70>m){//몸무게가 70보다 큰 경우
        if(165>h) rank = 3;//키가 165 보다 작은 경우 3등급
        else if(175>h) rank = 1;//키가 175 보다 작은 경우 1등급
        else rank = 2;//그외 2등급
    }
    else {//그외
        if(165>h) rank = 2;//키가 165 보다 큰 경우 2등급
        else if(175>h) rank = 3;//키가 175 보다 큰 경우 3등급
        else rank = 1;//그외 1등급
    }

    return rank;//랭크 반환
}

int womanscore(int m,int h){//몸무게와 키를 인자로 갖는 등급 함수: 여자
    int rank;//랭크값 정의
    if(50>m){//몸무게가 50보다 큰 경우
        if(165>h) rank = 1;//키가 165 보다 큰 경우 1등급
        else if(175>h) rank = 2;//키가 175 보다 큰 경우 2등ㄱ브
        else rank = 3;//그외 3등급
    }
    else if(60>m){//몸무게가 60보다 큰 경우
        if(165>h) rank = 3;//키가 165 보다 작은 경우 3등급
        else if(175>h) rank = 1;//키가 175 보다 작은 경우 1등ㄱ브
        else rank = 2;//그외 2등ㄱ브
    }
    else {//그 외
        if(165>h) rank = 2;//키가 165 보다 작은 경우 2등급
        else if(175>h) rank = 3;////키가 175 보다 작은 경우 3등ㄱ브
        else rank = 1;//그외 1등급
    }
    
    return rank;//랭크 반환
}

int main(){
    int N,cnt;//정수형 변수 N과 매개변수 cnt 선언
    int rank1=0,rank2=0,rank3=0;//3개의 랭크 수 
    scanf("%d",&N);//정수형 변수 입력받음
    for(int i=0;i<N;i++){//N번 반복
        scanf("%d %d %d",&bs.s,&bs.m,&bs.h);//구조체를 통해 입력받고
        if(bs.s == 1)cnt = manscore(bs.m,bs.h);//성별이 남자면 남자함수
        else cnt = womanscore(bs.m,bs.h);//아니면 여자함수 실행

        if(cnt == 1) rank1 ++;// 1등급의 랭크 증가
        else if(cnt == 2) rank2 ++;// 2등급의 랭크 증가
        else if(cnt == 3) rank3 ++;// 3등급의 랭크 증가
    }
    printf("%d %d %d",rank1,rank2,rank3);//결과 출력

}
//2 
//1 66 170 
//2 48 155