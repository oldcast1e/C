#include <stdio.h>

int main(){

    int u,m,l;//입력값 선언,돈 변수 선언,남은 돈 변수 선언
    int a,b,k;//나머지 연산에 사용할 변수
    scanf("%d",&u);//입력값을 입력받음

    switch(u){

        case 1://입력값이 1인 경우
            printf("Americano\n");
            scanf("%d",&m);//돈 입력받음
            l = m - 500;//남은 돈 = 입력된 돈 -500
            a = l/500;//남은 돈을 500으로 나눔
            k = l%500;//남은 돈을 500으로 나머지 연산
            b = k/100;//k값을 100으로 나눔
            printf("%d %d",a,b);
            break;

        case 2://입력값이 2인 경우
            printf("Cafe Latte\n");
            scanf("%d",&m);//돈 입력받음
            l = m - 400;//남은 돈 = 입력된 돈 -400
            a = l/500;//남은 돈을 500으로 나눔
            k = l%500;//남은 돈을 500으로 나머지 연산
            b = k/100;//k값을 100으로 나눔
            printf("%d %d",a,b);
            break;

        case 3://입력값이 3인 경우
            printf("Lemon Tea\n");//돈 입력받음
            scanf("%d",&m);
            l = m - 300;//남은 돈 = 입력된 돈 -300
            a = l/500;//남은 돈을 500으로 나눔
            k = l%500;//남은 돈을 500으로 나머지 연산
            b = k/100;//k값을 100으로 나눔
            printf("%d %d",a,b);//500원의 개수 ,100원의 개수 출력
            break;


    }
    
}