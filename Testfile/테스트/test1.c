#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {

    char tag[11][1000]={
        {"푸시"},
        {"팝"},
        {"피크"},
        {"출력"},
        {"초기화"},
        {"용량확인"},
        {"데이터상태"},
        {"저장상태"},
        {"과저장상태"},
        {"검색"},
        {"종료"}

    };
    for(int i=0;i<55;i++) printf("--");printf("-\n");
    for(int i=0;i<=10;i++){
        printf("|%5d    ",i);
    }printf("|\n");
    for(int i=0;i<55;i++) printf("--");printf("-\n");

    for(int i=0;i<=10;i++){
        printf("|%-11s",tag[i]);
    }printf("|\n");
    for(int i=0;i<55;i++) printf("--");printf("-\n");

    
    // for(int j=0;j<10;j++){
    //     for(int i=0;i<10;i++)printf("-");
    //     printf("\n%2d |",j+1); printf("data");
    //     printf("\n");
    // } 
    // printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)초기화 (6)용량확인 (7)스택의 현재 데이터 상태 (8)스택 저장상태 (9)스택 과저장 유무 (10)검색 (0)종료: ");scanf("%d",&menu);
}	
