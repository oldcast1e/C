#include  <stdio.h>

int main(){
    
    int X[10],Y[10],Z[10];//크기 10의 3개의 배열 선언

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&X[i]);//x의 요소를 입력받음 
    }
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&Y[i]);//Y의 요소를 입력받음 
    }
    for(int i=0;i<10;i++){//10번 반복하여
        Z[i] = X[i]+Y[9-i];//k의 요소에 x,y배열의 합을 저장함
        //이때 Y는 9-i부터 시작(뒤부터)
    }

    for(int i=0;i<10;i++){//10번 반복하여
        printf(" %d",Z[i]);//k의 각 요소 출력

    }

    return 0;
}
