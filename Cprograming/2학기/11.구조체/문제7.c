#include  <stdio.h>
struct num{//구조체 정의
    int n,rank;//두개의 정수형 변수 선언
};
int main(){//메인 함수
    int N,cnt,A,B;//
    struct num prs[10];//구조체 선언
    for(int i=0;i<10;i++){//10번 반복하여 
        scanf("%d",&prs[i].n);//구조체의정수값을 입력받음
    }
    for(int i=0;i<10;i++){//10번 반복(1)
        cnt = 0;//cnt 매개변수 초기화
        for(int j=0;j<10;j++){//10번 반복(2)
            if(i!=j){//반복 시 같은 수가 아닌 경우
                if(prs[i].n<prs[j].n) cnt ++;//자신보다 큰 수가 있으면 1증가
            }
        }
        prs[i].rank = cnt +1;//랭크값을 구조체 랭크값에 저장
    }
    for(int i=0;i<10;i++){//10번 반복
        if(prs[i].rank==3) printf("%d ",prs[i].n);//3등을 출력
    }
    for(int i=0;i<10;i++){//10번 반복
        if(prs[i].rank==7) printf("%d ",prs[i].n);//7등을 출력
    }
}
//78 65 23 43 82 95 31 15 8 54