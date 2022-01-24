#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*소수의 나열 - 알고리즘2-1 연결리스트 버전*/

struct prime{
    int data;
    struct prime *next;
}NODE[500];
int main(){
    int n,m,cnt=0,node_num=0;
    //prt: 소수의 개수-1 == 소수를 저장하는 배열의 인덱스
    //cnt: 계산 횟수
    NODE[node_num].next = NULL;
    NODE[node_num].data = 2;

    for(n=3;n<=1000;n+=2){
        for(m=1;m<n;m++){
            if(n%m == 0)break;
        }
        if(n == m){
            NODE[node_num].next = &NODE[node_num+1];
            node_num++;
            NODE[node_num].data = n;
        }
    }
    struct prime* curr = NODE->next; //순회용 노드 생성
    for(int i=0;i<node_num;i++){
        printf("%d\n",NODE[i].data);
    }
    printf("나눗셈을 시행한 횟수: %d\n",cnt);
}