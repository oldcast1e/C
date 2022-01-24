#include  <stdio.h>
#include  <string.h>
struct st{
    char name[10]; //학생이름
    char book[5][20]; //인증시험 본 책 이름 (예) History Politics 
    int score[5]; //위 책에 대한 인증시험 점수 (예) 60 40 
    int cnt,pcnt; //인증시험 본 책의 권수, 통과한 책의 권수
};

typedef struct st system;

int main(){//메인함수
    system student[100];//구조체 선언

    int N,key;//입력받을 정수와 조건값 정의
    char tmpstr[100],tmp=' ',sc;//엔터키를 입력받을 변수 선ㅇ너
    scanf("%d",&N);//정수를 입력받고
    getchar();//엔터값을 지움

    for(int i=0;i<N;i++){//N번 반복
        student[i].cnt = 0;//
        student[i].pcnt = 0;//인증시험본 책의 권수와 통과권수 초기화
        key = 1;//조건값 초기화

        scanf("%s",student[i].name);//학생의 이름을 받고
        getchar();//엔터값 지우기
        for(int j=0;j<5;j++){//5번 반복 = 책의 5권수
            scanf("%s%c",student[i].book[j],&tmp);//책의 이름과 tmp값을 입력받음
            //==0만 입력되면 tmp에는 엔터가 저장되므로
            if(tmp =='\n') {//0만 입력시

                if(strcmp(student[i].book[j],"0")==0){//입력받은 문자열이 0이면
                    // printf("break!");
                    key = 0;//조건값을 0으로 하거
                    break;//반복문 종료
                }
            }
            else{//tmp가 엔터가 아니면 = 다른값이 입력될 예정 = 점수
                student[i].cnt ++;//입력권수 증가
                // printf("increasing cnt\n");
                scanf("%d",&student[i].score[j]);//점수를 입력받음

                if(student[i].score[j] >= 50) student[i].pcnt++;//50점이 넘으면 통과권수 증가
                if(j==4) key = 3;//5권모두 입력받으면 조건값을 3으로
            }
        }
        if(key == 3) {//조건값이 3이면 = 5권모두 입력받으면 -> 종료를 위해 0을 입력받아야함
            // printf("Full\n");
            scanf("%c",&tmp);getchar();//0을 입력받고 엔터 지움
        }
        if(key == 0 || key == 3){//0이거나 3이면 = 입력이 끝나면
            printf("%s %d%%\n",student[i].name,student[i].pcnt*20);//결과 출력
        }

    }

    
}
