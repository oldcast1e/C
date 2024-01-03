#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int num[100];
    int dnum[11][11];
    //fgets(arr, 101, stdin);
    // scanf("%d",&a);
    // scanf("%s",arr);
    // for(int i=0;i<(int)strlen(arr);i++)
    //for(int i=0;i<cnt;i++)
    /*
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++)printf("%d ",dnum[i][j]);
        printf("\n"); cnt++;
    }
    */
    

    
} 
/*
0은 빈공간을 뜻한다.

1 이상의 수는 물풍선으로, 물풍선은 자신의 숫자만큼 상하좌우로 터진다.
-1은 장애물로, 물풍선이 터질때 물줄기가 여기 닿으면 멈춘다.

그 후 플레이어의 수 n이 입력되고, n개의 플레이어의 행,열이 주어진다.

이 때, 플레이어는 장애물에 위치하지 않는다.

물풍선이 모두 터질 때의 정보를 출력하는 프로그램을 작성하라.

그 방법은 다음과 같다.

1. 보드판을 출력한다.(0은 빈공간, -1은 장애물, -2는 물풍선, 플레이어는 입력된 순서+1로 표현한다.)
2. 플레이어의 생존 유무를 출력한다.

*/