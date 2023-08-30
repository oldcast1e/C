#include  <stdio.h>

int main(){
    
    char X[10];
    int key;//크기가 10인 배열과 출력조건key변수 선언

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%c",&X[i]);//x의 요소를 입력받음 
    }
    getchar();

    for(int i=0;i<10;i++){//10번 반복하여
        key = 1;//key값 초기화
        for(int j=0;j<10;j++){//10번 반복하여
            if(i!=j){//같은 숫자(자기 자신)끼리는 비교하지 않음
                if(X[i]==X[j])//같은 숫자가 한번이라도 나오면
                    key = 0;//출력조건을 0으로 
            }
        }
        if(key==1)//출력조건을 만족하는 경우
            printf(" %c",X[i]);//해당 문자를 출력
        
    }
    

    return 0;
}
