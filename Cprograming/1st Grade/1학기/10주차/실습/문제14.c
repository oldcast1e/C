#include  <stdio.h>

int main(){
    
    int cnt;//자신보다 작은 숫자의 개수
    char X[10],Y[10];//크기가 10인 실수형 변수선언

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%c",&X[i]);//x의 요소를 입력받음 
    }
    getchar();
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%c",&Y[i]);//y의 요소를 입력받음 
    }
    for(int i=0;i<10;i++){//10번 반복하여
        printf(" %c %c",X[i],Y[i]);//x,y 순서대로 문자를 출력
    }

    return 0;
}
