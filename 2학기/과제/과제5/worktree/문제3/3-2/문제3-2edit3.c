#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct subject{
    char *name; // 과목 이름 
    double score; // 과목 점수
};
struct student{
    char *name; // 학생 이름
    char id[5]; // 학생 학번
    int numSubject; // 과목 개수
    struct subject *psub; // 과목 구조체 포인터 

    double avg; // 모든 과목의 평균 점수
    //학생이 수강한 모든 과목 점수에 대한 평균을 구조체 멤버 변수 avg에 저장
};
void reset(char *str){//배열을 초기화하는 함수
    for(int i=0;i<101;i++) str[i] = '\0';//널함수 저장
}
int main(){//메인함수
    // 총 N명 학생들의 과목별 점수를 관리하는 프로그램
    int N,space,sbj_info_stt;
    int cnt,wordcnt;

    int sbj_num;
    char str[101];

    char name[101],id[5]={},sbj_name[101];

    scanf("%d",&N);getchar();
    struct student *system = NULL;
    system  = (struct student*)malloc(sizeof(struct student)*N);

    for(int i=0;i<N;i++){
        reset(str);gets(str);
        reset(name);
        space = 0;cnt=0;sbj_info_stt=0;
        sbj_num = 0;
        for(int j=0;j<(int)strlen(str);j++){
            sbj_info_stt ++;
            if(str[j]==' ') {printf("\n");space ++;cnt =0;}
            if(str[j]==' ' && ('0' <= str[j-1] && str[j-1] <='9')){printf("\nindex:%d\n",j);break;}
            else{
                if(space == 0&& str[j] !=' '){
                    name[cnt] = str[j];
                    printf("<%c>",name[cnt]);
                    cnt ++;
                }
                else if(space == 1 && str[j] !=' '){
                    // strcat(name,"\0");
                    
                    id[cnt] = str[j];
                    printf("(%c)",id[cnt]);
                    cnt++;
                }
            }
        }
        
        
            
        

    }
    printf("> %s %s | sbj_info_stt = %d\n",name,id,sbj_info_stt);
    printf("sbj_num = %d",sbj_num);

    //n 번째 학 생에 대해서
    //이름, 학번, 과목 1의 이름 및 점수, 과목 2의 이름 및 점수, ..., 과목 Mn의 이름 및 점 수를 입력 받아
    //메모리를 동적으로 할당한 구조체에 저장

    //Mn은 n 번째 학생이 수강한 과목 의 개수
}
/**
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
 */