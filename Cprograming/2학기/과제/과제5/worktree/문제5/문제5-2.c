#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct customer{ 
    char id[5];
    char *name;
    char *phone; 
    struct customer *next;
    //고객번호의 마지막 숫자가 같은 고객들을 포인터로 연결한다
    //next는 고객번호의 마지막 숫자가 같은 다음 입력 고객의 주소를 가리키게 한다.
};

void reset(char *str){
    for(int i=0;i<100;i++)str[i] = '\0';
}
int main(){//메인함수

    int N,len,space,cnt = 0;//입력받을정수와 매개변수 선언
    char str[100];//문자열을 임시저장할 배열
    char str_name[100],str_phn[100];//이름과 핸드폰 번호를 임시 저장할 배열
    char separator[] = "' ','\n'";//문자열 분리 토큰

    char K;
    int key=0;
    
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
        system[i].next = NULL;
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
    //고객 정보를 저장한 후, 고객번호의 마지막 숫자가 입력되면, 
    
    //고객번호의 마지막 숫자가 같은 고 객들의 이름과 전화번호를 출력
    // 해당 고객이 고객번호의 마지막 숫자가 같은 고객들 중 몇 번째 고객인지를 함께 출력하는 프로그램을 작성
    
    scanf("%c",&K);//핸드폰 뒷자리를 입력받고
    // for(int i=0;i<N;i++) printf("%c\n",system[i].phone[12]);

    for(int i=0;i<N;i++){
        // key = 1;
        // printf(">%d\n",i);
        if(system[i].phone[12] == K){
            // printf(">>%s\n",system[i].name);

            for(int j=i+1;j<=N-1;j++){
                // if(i!=j){
                if(system[i].phone[12] == system[j].phone[12]){
                    // printf("i = %d | j = %d\n",i,j);
                    // printf("<%s> -> (%s)\n",system[i].name,system[j].name);
                    system[i].next = &system[j];
                    break;
                }
                // key = 0;
                
                // }
            }
        }
    }
    cnt = 1;
    for(int i=0;i<N;i++){
        if(system[i].phone[12] == K && key == 0){
            key ++;
            printf("%s %s %d\n",system[i].name,system[i].phone,cnt);
            cnt ++;

        }
        if(system[i].next != NULL && key != 0) {
            printf("%s %s %d\n",(system[i].next)->name,(system[i].next)->phone,cnt);
            cnt ++;
        }
        // if(system[i].phone[12] == K){
        //     printf("%s %s %d\n",system[i].name,system[i].phone,i+1);
        //     if(system[i].next != NULL) printf("%s %s %d\n",(system[i].next)->name,(system[i].next)->phone,i+1);
        //     break;
        // }
    }

    for(int i=0;i<N;i++)free(system[i].name);
    for(int i=0;i<N;i++)free(system[i].phone);
    free(system);


}
/*
KimSooJin 010-1234-5678
ParkGilDong 010-2468-1357
ChungSangChul 010-1230-4567
LeeYoungHee 010-1357-2468
ChoiMyungHee 010-3458-1267

8
7
7
8
7`
*/