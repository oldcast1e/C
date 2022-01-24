#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{//구조체 정의
    char *studentName;//이름
    char id[5];//아이디
    char *subjectName;//과목
    double subjectScore; // 과목 점수
};
void reset(char *str){//배열을 초기화하는 함수
    for(int i=0;i<100;i++){
        str[i] = '\0';//널함수 저장
    }
}
int main(){//메인함수
    int N,K,len,space,cnt;//입력받을 2개의 정수형 변수와 매개변수
    scanf("%d",&N);getchar();//반복횟수 입력

    int sequence[100],sqcnum = 0;//스페이스 입력확인 배열 및 매개변수

    char namearr[100],idarr[100],sujarr[50],scrarr[100];
    //구조체의 멤버를 임시저장할 배열
    char str[101];//입력받을 문자열
    struct student *st = NULL;
    st = (struct student*)malloc(N*sizeof(struct student));//구조체 동적할당

    for(int i = 0;i<N;i++){//N번 반복
        reset(str);//입력받을 문자열 초기화

        gets(str);len = strlen(str);//문자열 입력받고 길이구하기
        space = 0;cnt =0;//매개변수 초기화
        reset(namearr);reset(idarr);reset(sujarr);reset(scrarr);
        //멤버 저장 배열 초기화
        for(int k=0;k<len;k++){//배열 길이만큼 반복
            if(str[k]==' '){//스페이스바 입력시
                space ++;//스페이스바 입력횟수 증가
                cnt =0;
            }
            
            if(space == 0 && str[k]!=' '){//첫번째 단어
                namearr[cnt] = str[k];
                cnt ++;
            }
            else if(space == 1 && str[k]!=' '){//두번째 단어
                idarr[cnt] = str[k];
                cnt ++;
            }
            else if(space == 2 && str[k]!=' '){//세번째 단어
                sujarr[cnt] = str[k];
                cnt ++;
            }
            else if(space == 3 && str[k]!=' '){//네번째 단어
                scrarr[cnt] = str[k];
                cnt ++;
            }    
        }
        // printf(">");puts(namearr);
        // printf(">");puts(idarr);
        // printf(">");puts(sujarr);
        // printf(">");puts(scrarr);
        st[i].studentName = (char*)malloc((int)strlen(namearr)*sizeof(char));
        //학생이름 구조체 배열동적할당
        st[i].subjectName = (char*)malloc((int)strlen(sujarr)*sizeof(char));
        //과목이름 구조체 배열동적할당
        strcpy(st[i].studentName,namearr);//저장
        strcpy(st[i].id,idarr);//저장
        strcpy(st[i].subjectName,sujarr);//저장
        st[i].subjectScore = (double)atoi(scrarr);//점수 저장
        sequence[sqcnum] = sqcnum;
        sqcnum ++;
    }
    scanf("%d",&K);//두번째 정수형 변수 입력
    for(int i=0;i<N;i++){//N번 반복
        for(int j=i;j<N;j++){//N번 반복
            if(i!=j){
                if(st[i].subjectScore < st[j].subjectScore ){//점수순으로 정렬
                    struct student tmp;//구조체 스왑
                    tmp = st[i];
                    st[i] = st[j];//구조체 스왑
                    st[j] = tmp;

                    int sqctmp;//순서 스왑
                    sqctmp = sequence[i];
                    sequence[i]=sequence[j];//순서 스왑
                    sequence[j] = sqctmp;
                }
            }
        }
    }
    for(int i=0;i<N;i++){//N번 반복
        for(int j=i;j<N;j++){//N번 반복
            if(i!=j){
                if(st[i].subjectScore == st[j].subjectScore){//같은 점수일때
                    //입력된 순서로 스왑
                    if(sequence[i]>sequence[j]){//입력된 순서 확인
                        struct student tmp;//구조체 스왑
                        tmp = st[i];
                        st[i] = st[j];//구조체 스왑
                        st[j] = tmp;
                        
                        int sqctmp;
                        sqctmp = sequence[i];// 순서 스왑
                        sequence[i]=sequence[j];
                        sequence[j] = sqctmp;// 순서 스왑
                    }
                }
            }
        }
    }


    //과목 점수가 같은 학생이 있는 경우에는 먼저 입력된 1명만 출력 하시오.
    // for(int i=0;i<N;i++)printf("<%d> ",sequence[i]);printf("\n");
    // for(int i=0;i<N;i++)printf("%s | ",st[i].studentName);
    printf("%s %s %s %.2lf",st[K-1].studentName,st[K-1].id,st[K-1].subjectName,st[K-1].subjectScore);
    //결과 출력
    for(int i=0;i<N;i++){//메모리 해제
        free(st[i].studentName);
        free(st[i].subjectName);
    }
    free(st);//메모리 해제
    

}
/*
5
HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 50
Euler 1005 Math 100 

HongGilDong 1003 Math 78
JeonWooChi 1001 English 60
HeungBoo 1002 Economics 80
NolBoo 1004 Ethics 78
Euler 1005 Math 100 
2
*/

//과목 점수가 같은 학생이 있는 경우에는 먼저 입력된 1명만 출력 하시오.