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

    char K[5];//마지막 번호
    int lastphoncnt;//마지막 번호의 일치 유무 확인 매개변수
    int key=0;//조건값
    
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
    // 마지막 숫자가 같은 고객들 중 몇 번째 고객인지 출력하는 프로그램
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
    cnt = 1;//cnt초기화
    for(int i=0;i<N;i++){//N번 반복
        lastphoncnt = 0;//일치확인 매개변수 초기화
        if(system[i].phone[12] == lastnum && key == 0){//key => 첫번째 반복에만 작동
            key ++;//조건값 증가
            for(int j=0;j<4;j++) if(system[i].phone[9+j]==K[j])lastphoncnt++;//일치확인 매개변수증가
            // printf("test1[%d]:%d\n",i,lastphoncnt);
            if(lastphoncnt == 4){//마지막 번호가 일치하면
                // printf("test2[%d]",i);
                printf("%s %s %d\n",system[i].name,system[i].phone,cnt); //결과출력 후
                break;//반복문 종료
            }
            else cnt ++;
        }
        
        if(system[i].next != NULL && key != 0) {//두번째 반복문
            lastphoncnt = 0;//일치확인 매개변수 초기화
            for(int j=0;j<4;j++) if((system[i].next)->phone[9+j] == K[j]) lastphoncnt++;//일치확인 매개변수증가
            if(lastphoncnt == 4){//마지막 번호가 일치하면
                // printf("test4[%d]",i);
                printf("%s %s %d\n",(system[i].next)->name,(system[i].next)->phone,cnt);//결과출력 후
                break;//종료
            }
            else cnt ++;//cnt == 번호의 마지막 자리의 끝자리가 같은 횟수
        }
    }

    for(int i=0;i<N;i++)free(system[i].name);//동적할당 해제
    for(int i=0;i<N;i++)free(system[i].phone);//동적할당 해제
    free(system);//동적할당 해제


}