#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct city { //관광지 정보
   char name[21]; //관광지명
   int money; //입장료
   char out; //야외/실내
   char startday[9]; //시작일
   char cityname[21]; //도시명
};

int main() { //메인함수
    int N; //변수 N 정의
    int citynum[10000]; //관광지 개수 변수 정의
    int i, j, k, p = 0, q = 0; //임의변수 정의
    int max_money = 0, maxstart = 99999999, index_i, index_j; //매개변수 정의
    char city[10000][21]; //도시명 변수 정의
   
   

    scanf("%d", &N);getchar();  //도시개수 입력
    struct city **ptr = NULL; //구조체 포인터 정의
    ptr = (struct city**)malloc(N * sizeof(struct city*)); //메모리 동적할당
    
    for (i = 0; i < N; i++) scanf("%s", city[i]); //도시명 입력
    
    for (i = 0; i < N; i++) {
        scanf("%d", &citynum[i]); //도시의 관광지 개수 
        ptr[i] = (struct city*)malloc((citynum[i]) * sizeof(struct city)); //메모리 동적할당 - 1차 배열
    }

    if (ptr == NULL) { 
        printf("Not Enough Memory"); //오류 확인
        return -1; //종료
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < citynum[i]; j++) {
            if (ptr[i] == NULL) {
                printf("Not Enough Memory"); //오류 확인
                return -1; //종료
            }
            getchar();
            scanf("%s %d %c %s", ptr[i][j].cityname, &ptr[i][j].money, &ptr[i][j].out, ptr[i][j].startday); 
            //관광지 이름, 입장료, 야외 실내 구분, 시작일 입력
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < citynum[i]; j++) {
            if (ptr[i][j].money > max_money) { //money멤버가 max_money보다 큰 경우
                max_money = ptr[i][j].money; //money멤버 값으로 저장
                maxstart = atoi(ptr[i][j].startday); //startday 값으로 저장
                index_i = i; //index_i에 i값 저장
                index_j = j; //index_j에 j값 저장
            }
            else if (ptr[i][j].money == max_money) { //만약 멤버money가 max_money와 같을 경우
                if (atoi(ptr[i][j].startday) < maxstart) { //값 비교
                maxstart = atoi(ptr[i][j].startday); //startday 값으로 저장
                index_i = i; //index_i는 i값 저장
                index_j = j; //index_j는 j값 저장
                }
            }
        }
    }

    printf("%s %s %d %s %c", city[index_i], ptr[index_i][index_j].cityname, ptr[index_i][index_j].money, ptr[index_i][index_j].startday, ptr[index_i][index_j].out); 
    //결과출력

    for (i = 0; i < N; i++) { //메모리 해제
        free(ptr[i]);
    }
    free(ptr);


    return 0;
}