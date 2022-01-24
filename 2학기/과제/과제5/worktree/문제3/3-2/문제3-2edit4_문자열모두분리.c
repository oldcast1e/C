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
    int N,K,cnt,wordcnt;
    int sbj_info_stt,sbj_num;
    char str[101];
    char spr[] = " ,\n,'\0";

    char name[101],id[5]={},sbj_name[101];

    scanf("%d",&N);getchar();
    struct student *system = NULL;
    system  = (struct student*)malloc(sizeof(struct student)*N);

    for(int i=0;i<N;i++){
        
        reset(str);gets(str);
        system[i].avg = 0;
        sbj_info_stt=0;sbj_num=0;

        for(int j=0;j<(int)strlen(str);j++){
            sbj_info_stt ++;//printf("(%c)",str[j]);
            if(str[j]== ' ' && ('0' <= str[j-1] && str[j-1] <='9')){break;}
        }//subject구조체 동적할당을 위해서 과목과 점수가 출력되는 위치파악
        for(int j=sbj_info_stt;j<(int)strlen(str);j++)
            if(str[j]==' ' && ( ('a' <= str[j-1] && str[j-1] <='z')  || ('A' <= str[j-1] && str[j-1] <='Z')  )) sbj_num ++;
        // printf("\n> sbj_info_stt = %d\nsbj_num = %d\n\n",sbj_info_stt,sbj_num);

        system[i].psub = (struct subject*)malloc(sizeof(struct subject)*sbj_num);
        //구조체 동적할당


        char *token = strtok(str,spr);
        cnt = 0;wordcnt=0;
    
        while(token != NULL){
            
            // printf("Token: %s\n",token);
            if(cnt == 0){
                int len = strlen(token);
                system[i].name = (char*)malloc(len*sizeof(char)+1);
                strcpy(system[i].name,token);strcmp(system[i].name,"\0");

                cnt ++;
            }
            else if(cnt == 1) {strcpy(system[i].id,token);cnt++;}
            else{
                if(atoi(token) == 0){//영어이면 == 과목이름이면
                    int len = strlen(token);
                    system[i].psub[wordcnt].name = (char*)malloc(len*sizeof(char)+1);
                    strcpy(system[i].psub[wordcnt].name,token);strcmp(system[i].psub[wordcnt].name,"\0");
                }
                else if(atoi(token) != 0){//숫자면(숫자라면 숫자가 반환됨)
                    system[i].psub[wordcnt].score = (double)atoi(token);
                    system[i].avg += system[i].psub[wordcnt].score;
                    wordcnt++;
                }
                
            }
                
        
            token = strtok(NULL,spr);
        }
        system[i].avg = system[i].avg/(double)wordcnt;
        //wordcnt ==> 과목개수
        // 학생이 수강한 모든 과목 점수에 대한 평균을 구조체 멤버 변수 avg에 저장
        for(int k=0;k<wordcnt;k++){
            // printf(">sbjname: %s | score: %.2lf\n",system[i].psub[k].name, system[i].psub[k].score);
        }
        // printf("%.2lf\n",system[i].avg);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            if(system[j].avg < system[j+1].avg){
                struct student tmp;
                tmp = system[j];
                system[j] = system[j+1];
                system[j+1] = tmp;
            }//평균 점수가 같은 학생의 경우에는 학번 순으로 정렬
            if(system[j].avg == system[j+1].avg){
                if(strcmp(system[j].id,system[j+1].id)>0){
                    struct student tmp;
                    tmp = system[j];
                    system[j] = system[j+1];
                    system[j+1] = tmp;
                }
            }
        }
    }
    //평 균 점수가 가장 높은 학생부터 내림차순으로 정렬
    for(int i=0;i<N;i++)printf("%d> %s %s %.2lf\n",i+1,system[i].name  , system[i].id , system[i].avg );

    scanf("%d",&K);
    int index = 0;
    double max;
    cnt =0;

    // printf(">>%d",(int)sizeof(system[K].psub));

    // while(1){

    //     if((system[K].psub[cnt].name) == NULL){printf("cnt = %d\n",cnt); break;}
    //     if(strcmp(system[K].psub[cnt].name,"\0")==0){printf("cnt = %d\n",cnt); break;}

    //     if(cnt == 0) {max = system[K].psub[cnt].score; cnt ++;}
    //     else{
    //         if(system[K].psub[cnt].score > max) max = system[K].psub[cnt].score;
    //         cnt++;
    //     }
    
    for(int i=0;i<10;i++){
        
        // if(&(system[K].psub[cnt].name) == NULL){printf("break1"); break;}
        if(strcmp(system[K].psub[i].name,"\0")==0){ printf("break2"); break;}
        printf("%s\n",system[K].psub[i].name);
    }

    // }
    
    // printf("%s %s %.2lf %s %.1lf",system[K].name  , system[K].id , system[K].avg , system[K].psub[cnt].name, system[K].psub[cnt].score);

    //K를 입력 받아 K 번째 학생의 이름, 학 번, 평균 점수를 출력


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