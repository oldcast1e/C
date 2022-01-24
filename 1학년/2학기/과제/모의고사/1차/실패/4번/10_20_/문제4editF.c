#include  <stdio.h>
#include  <string.h>
struct st{
    char name[10]; //학생이름
    char book[5][20]; //인증시험 본 책 이름 (예) History Politics 
    int score[5]; //위 책에 대한 인증시험 점수 (예) 60 40 
    int cnt,pcnt; //인증시험 본 책의 권수, 통과한 책의 권수
};

int main(){

    int N = 0,key,len;
    char input[100],*pi  = input;

    int bookcnt,scorecnt;
    struct st exam[100];
    scanf("%d",&N);
    getchar();

    for(int i=0;i<N;i++){
        exam[i].cnt = 0;
        exam[i].pcnt = 0;
        key = 1;

        scanf("%s",exam[i].name);
        getchar();
        for(int j=0;j<5;j++){
            
            gets(input);
            // getchar();
            printf("input : %s\n",input);
            if(input[0]=='0')break;
            key = 1;
            bookcnt = 0;
            scorecnt = 0;
            
            len = strlen(input);
            for(int j=0;j<len;j++){
                if(*(pi+j)==' '){
                    key = 0; 
                    j++;
                }

                if(key ==1 ){//책이름
                    exam[i].book[i][bookcnt] = *(pi+j);
                    bookcnt++;
                }
                else if(key == 0){//점수
                    exam[i].score[scorecnt] = *(pi+j)-48;
                    scorecnt++;
                }
            }
        }
        printf(">%s/",exam[0].book[0]);
        printf(">%s",exam[0].score);
        

        // if()
    }
}

//세종대 학생들의 시험 현황을 알고자한다.

//N명 학생의 이름과 인증시험 점수를 입력받고,
//각 학생들의 시험현황이 몇 퍼센트인지 출력하라.

/*
- 학생의 이름은 공백 없이 최대 길이가 9인 영어 문자열이다.
- 입력받는 학생의 정보는 최대 100명이다.
- 책 한 권의 인증시험의 통과 점수는 50점 이상이다.
*/

/*
인증시험을 봐야하는 책은 총 5권이며, 책명은 다음과 같다.
History Politics DonQuixote LaPeste Chaos
*/

//최대 5권의 책명과 점수 입력
//종료시 0입력하고 퍼센트 출력

/*
3
Ann
History 60
Politics 40
Chaos 100
LaPeste 10
DonQuixote 10
0  
Branden
LaPeste 70
0
Christina
0


*/
