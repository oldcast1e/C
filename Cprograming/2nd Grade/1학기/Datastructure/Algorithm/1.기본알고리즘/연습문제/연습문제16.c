#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//정수 n,m을 입력하고 nxm의 정사각형을 만들어라

void triangleLB(int n){//왼쪽 아래가 직각
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }printf("\n");
    }

}

void triangleLU(int n){//왼쪽 위가 직각
    for(int i=n;i>=1;i--){
        for(int j=i;j>=1;j--){
            printf("*");
        }printf("\n");
    }
}

void triangleRB(int n){//오른쪽 아래가 직각
    for(int i=1;i<=n;i++){
        for(int k=0;k<n-i;k++) printf(" ");
        for(int j=1;j<=i;j++)printf("*");
        printf("\n");
    }
}

void triangleRU(int n){//오른쪽 위가 직각
    for(int i=n;i>=1;i--){
        for(int k=0;k<n-i;k++) printf(" ");
        for(int j=1;j<=i;j++)printf("*");
        printf("\n");
    }
}

int main(){
    int n,dir;
    printf("정수 n을 입력하세요: "); scanf("%d",&n);
    printf("직각의 방향을 입력하세요\n우측 상단:1\n우측 하단:2\n좌측 상단:3\n좌측 하단:4\n입력: ");scanf("%d",&dir);
    switch (dir){
    case 1:
        triangleRU(n);
        break;
    case 2:
        triangleRB(n);
        break;
    case 3:
        triangleLU(n);
        break;
    case 4:
        triangleLB(n);
        break;
    
    }

}//**********
