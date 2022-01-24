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
    for(int i=0;i<100;i++){
        str[i] = '\0';//널함수 저장
    }
}
int main(){//메인함수
    int N,K,len,space,cnt,line;

    int struct_cnt;
    char str[101];
    char name_arr[100],id_arr[100];
    char sbj_arr[100],scr_arr[100];
    scanf("%d",&N);getchar();

    struct student *std_sys = NULL;
    std_sys = (struct student*)malloc(N*sizeof(struct student));//구조체 동적할당sys = (struct subject*)malloc(N*sizeof(struct subject));//구조체 동적할당

    for(int i = 0;i<N;i++){
        reset(str);//입력받을 문자열 초기화
        reset(name_arr);reset(id_arr);
        space = 0;cnt =0;//매개변수 초기화
        line = 0;

        gets(str);len = strlen(str);//문자열 입력받고 길이구하기
        for(int k=0;k<len;k++){
            line ++;
            if(str[k]==' '){space ++;cnt =0;if(space == 2) break;}
            else if(space == 0){//첫번째 단어
                name_arr[cnt] = str[k];
                cnt ++;
            }
            else if(space == 1){//두번째 단어
                id_arr[cnt] = str[k];
                cnt ++;
            }
      
        }
        std_sys[i].name = (char*)malloc(((int)strlen(name_arr))*sizeof(char));
        strcpy(std_sys[i].name,name_arr);strcat(std_sys[i].name,"\0");
        strcpy(std_sys[i].id,id_arr);strcat(std_sys[i].id,"\0");

        // printf(">%s\n",name_arr);
        // printf(">%s\n",id_arr);
        
                
        // }
        space = 0;cnt = 0;struct_cnt=0;
        for(int j = line;j<len;j++)if(str[j]==' ')space ++;
        std_sys[i].psub = (struct subject*)malloc((space/2+1)*sizeof(struct subject));
        std_sys[i].avg = 0;

        for(int j = line;j<len;j++){

            if(('a'<= str[j] && str[j]<= 'z') || ('A'<= str[j] && str[j]<= 'Z') ){
                sbj_arr[cnt] = str[j];
                cnt++;
            }
            else if('0'<= str[j] && str[j]<= '9'){
                scr_arr[cnt] = str[j];
                cnt++;

            }
            if(str[j]==' ' || j ==(len-1) ){
                cnt = 0;

                if(('a'<= str[j-1] && str[j-1]<= 'z') || ('A'<= str[j-1] && str[j-1]<= 'Z') ){
                    //스페이스바 입력전 값이 영어단어 인경우
                    strcat(sbj_arr,"\0");//과목 저장 변수의 종결 선언
                    int sujlen = strlen(sbj_arr);

                    (std_sys[i].psub[struct_cnt]).name  = (char*)malloc(sujlen*sizeof(char));
                    //해당 인덱스의 구조체의 과목이름을 동적할당
                    strcpy((std_sys[i].psub[struct_cnt]).name,sbj_arr);//동적할당된 배열에 과목이름 저장
                    // printf("<%s[%d]>\n",(std_sys[i].psub[struct_cnt]).name,struct_cnt);
                    reset(sbj_arr);

                    // struct_cnt++;
                }
                else if('0'<= str[j-1] && str[j-1]<= '9'){
                    //
                    strcat(scr_arr,"\0");
                    (std_sys[i].psub[struct_cnt]).score = (double)atoi(scr_arr);
                    // printf("(%lf)[%d]\n",std_sys[i].psub[struct_cnt].score,struct_cnt);
                    std_sys[i].avg += std_sys[i].psub[struct_cnt].score;
                    reset(scr_arr);

                    struct_cnt++;
                }
            }
        }
        std_sys[i].numSubject = struct_cnt;
        std_sys[i].avg/= (double)std_sys[i].numSubject;
        // printf("numSubject[%d] = %d | avg[%d] = %lf\n",i,std_sys[i].numSubject,i,std_sys[i].avg);
    }
    // 평 균 점수가 가장 높은 학생부터 내림차순으로 정렬
    for(int i=0;i<N;i++){
        for (int j = 0; j < N-1; j++){
            if(std_sys[j].avg < std_sys[j+1].avg){
                struct student tmp;
                tmp = std_sys[j];
                std_sys[j] = std_sys[j+1];
                std_sys[j+1] = tmp;
            }
        }
    }
    // printf("---\n");
    // for(int i=0;i<N;i++){
    //     printf("%s %s %.2lf\n",std_sys[i].name,std_sys[i].id,std_sys[i].avg);
    // }
    
    double max;
    int index=0;
    scanf("%d",&K);
    printf("%s %s %.2lf ",std_sys[K].name,std_sys[K].id,std_sys[K].avg);

    for(int i=0;i<100;i++){
        // printf("--");
        if(i==0) max = std_sys[K].psub[i].score ;
        else{
            if(std_sys[K].psub[i].score > max){
                max = std_sys[K].psub[i].score;
                index = i;
            }
        }
    }
    
    printf("%s %.2lf",(std_sys[K].psub[index].name),(std_sys[K].psub[index].score));

    //K를 입력 받아 K 번째 학생의 이름, 학 번, 평균 점수를 출력
    // K 번째 학생의 과목 중 가장 점수가 높은 과목의 이름과 점수를 출력



    // n 번째 학 생에 대해 
    //이름,학번,과목 1의 이름 및 점수, 과목 2의 이름 및 점수, ..., 과목 Mn의 이름 및 점 수를 입력
    //메모리를 동적으로 할당한 구조체에 저장

    //Mn은 n 번째 학생이 수강한 과목 의 개수

    //평 균 점수가 가장 높은 학생부터 내림차순으로 정렬

    //K를 입력 받아 K 번째 학생의 이름, 학 번, 평균 점수를 출력
    // K 번째 학생의 과목 중 가장 점수가 높은 과목의 이름과 점수를 출력하 는 프로그램을 작성
}
//과목 점수가 같은 학생이 있는 경우에는 먼저 입력된 1명만 출력 하시오.

//
/*
5
HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70 
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90 
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
2


HongGilDong 1003 Math 85 C 80 AdvC 90
JeonWooChi 1001 English 60 C 75 Physics 80 Math 70 
HeungBoo 1002 Economics 80 AdvC 90 Math 80 C 90 
NolBoo 1004 Ethics 50 C 62
Euler 1005 Math 100 Physics 90 AdvC 85
*/

/*
Euler 1005 91.67
HongGilDong 1003 85.00
HeungBoo 1002 85.00
JeonWooChi 1001 71.25
NolBoo 1004 56.00
*/