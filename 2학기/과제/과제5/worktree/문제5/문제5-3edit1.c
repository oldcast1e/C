#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct customer{ 
    char id[5];
    char *name;
    char *phone; 
    struct customer *next;

};

void reset(char *str){
    for(int i=0;i<100;i++)str[i] = '\0';
}
int main(){

    int N,len,space,cnt = 0;//입력받을정수와 매개변수 선언
    char str[100];//문자열을 임시저장할 배열
    char str_name[100],str_phn[100];//이름과 핸드폰 번호를 임시 저장할 배열
    char separator[] = "' ','\n'";//문자열 분리 토큰

    char K[5],tmp[5];
    int lastphoncnt;
    int key=0;
    
    scanf("%d",&N); 
    getchar();//N을 입력받음
    
    struct customer *system = NULL;
    system = (struct customer *)malloc(N*sizeof(struct customer));//구조체 동적할당

    for(int i=0;i<N;i++){
        gets(str);len = strlen(str);//임시 문자열을 입력받고 길이 구함

        cnt = 0;//매개변수 초기화

        char *token = strtok(str,separator);
        while(token != NULL){//분리가 끝날때까지 반복
            if(cnt == 0){//첫번째 단어인 경우
                strcpy(str_name,token);//이름 저장
                cnt ++;
            }
            else if(cnt == 1) {//두번째 단어인경우
                strcpy(str_phn,token);
            }
            token = strtok(NULL,separator);//토큰 업데이트
        }

        system[i].name = (char*)malloc((int)strlen(str_name)*sizeof(char));
        system[i].phone = (char*)malloc((int)strlen(str_phn)*sizeof(char));
        system[i].next = NULL;
        strcpy(system[i].name,str_name);
        strcpy(system[i].phone,str_phn);    //저장

        cnt = 0;//매개변수 초기화
        for(int j=9;j<13;j++){//핸드폰 뒷자리
            system[i].id[cnt] = system[i].phone[j];//저장
            cnt ++;//매개변수 증가
        }
    }
    scanf("%s",K);//마지막 번호를 입력받음
    char lastnum = K[3];//끝자리 번호(char) 저장
    
    for(int i=0;i<N;i++){
        if(system[i].phone[12] == lastnum){
            //해당 인덱스의 전화번호의 끝자리가 입력된 번호의 끝자리와 동일하면
            for(int j=i+1;j<=N-1;j++){
                //해당 요소의 앞부터 끝까지 확인하여
                //끝자리 번호가 같은 번호가 있는지 확인
                if(system[i].phone[12] == system[j].phone[12]){
                    //있으면 해당 요소의 next 구조체에 저장
                    system[i].next = &system[j];
                    break;
                }
            }
        }
    }
    cnt = 1;
    for(int i=0;i<N;i++){
        lastphoncnt = 0;
        if(system[i].phone[12] == lastnum && key == 0){//key => 첫번째 반복에만 작동
            key ++;
            for(int j=0;j<4;j++) if(system[i].phone[9+j]==K[j])lastphoncnt++;
            if(lastphoncnt == 4){
                printf("%s %s %d\n",system[i].name,system[i].phone,cnt); 
                break;
            }
            else cnt ++;
        }
        
        if(system[i].next != NULL && key != 0) {
            lastphoncnt = 0;
            for(int j=0;j<4;j++) if((system[i].next)->phone[9+j] == K[j]) lastphoncnt++;
            
            // printf("test3[%d]:%d\n",i,lastphoncnt);
            if(lastphoncnt == 4){
                // printf("test4[%d]",i);
                printf("%s %s %d\n",(system[i].next)->name,(system[i].next)->phone,cnt);
                break;
            }
            else cnt ++;
        }
    }

    for(int i=0;i<N;i++)free(system[i].name);
    for(int i=0;i<N;i++)free(system[i].phone);
    free(system);


}
/*
5
KimSooJin 010-1234-5678
ParkGilDong 010-2468-1357
ChungSangChul 010-1230-4567
LeeYoungHee 010-1357-2468
ChoiMyungHee 010-3458-1267
2468

8
7
7
8
7`
*/