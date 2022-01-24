#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct customer{ //구조체 정의
    char id[5];
    char *name;
    char *phone; 
};

void reset(char *str){//문자열 초기화 함수
    for(int i=0;i<100;i++)str[i] = '\0';
}
int main(){//메인함수

    int N,len,space,cnt = 0;//입력받을정수와 매개변수 선언
    char str[100];//문자열을 임시저장할 배열
    char str_name[100],str_phn[100];//이름과 핸드폰 번호를 임시 저장할 배열
    char separator[] = "' ','\n'";//문자열 분리 토큰

    char input[5];//핸드폰 뒷자리
    
    scanf("%d",&N); getchar();//N을 입력받음
    
    struct customer *system = NULL;
    system = (struct customer *)malloc(N*sizeof(struct customer));//구조체 동적할당
    //고객 수 N을 입력받고, 크기 N의 구조체 배열을 동적으로 할당 받아, 고객 정보를 저장한다.
    for(int i=0;i<N;i++){
        // reset(str_name);reset(str_phn);
        gets(str);len = strlen(str);//임시 문자열을 입력받고 길이 구함

        cnt = 0;//매개변수 초기화

        char *token = strtok(str,separator);
        while(token != NULL){//분리가 끝날때까지 반복
            if(cnt == 0){//첫번째 단어인 경우
                strcpy(str_name,token);//이름 저장
                cnt ++;//매개변수 증가 - 핸드폰 번호에 저장 위함
                // printf("str_name: %s\n",token);
            }
            else if(cnt == 1) {//두번째 단어인경우
                strcpy(str_phn,token);
                // printf("str_phn: %s\n",token);
            }
            token = strtok(NULL,separator);//토큰 업데이트
        }

        system[i].name = (char*)malloc((int)strlen(str_name)*sizeof(char));
        //이름 동적할당
        system[i].phone = (char*)malloc((int)strlen(str_phn)*sizeof(char));
        //핸드폰 번호 동적하당
        strcpy(system[i].name,str_name);
        strcpy(system[i].phone,str_phn);    //저장

        cnt = 0;//매개변수 초기화
        for(int j=9;j<13;j++){//핸드폰 뒷자리
            system[i].id[cnt] = system[i].phone[j];//저장
            cnt ++;//매개변수 증가
        }
        // strcpy(system[i].phone,str_phn); strcat(system[i].phone,"\0");
    }
    scanf("%s",input);//핸드폰 뒷자리를 입력받고

    for(int i=0;i<N;i++){
        if(strcmp(input,system[i].id)==0){//뒷자리가 같으면
            printf("%s %s %d",system[i].name,system[i].phone,i+1);
            //고객의 정보 출력
        }
    }
    for(int i=0;i<N;i++)free(system[i].name);
    for(int i=0;i<N;i++)free(system[i].phone);
    free(system);


}