#include  <stdio.h>
int main(){

    char arr[10]={0};//크기 10의 배열 선언
    char *pch = arr,result;//배열의 포인터 선언과 결과값 선언
    int cnt = 0,rst[10]={0},key,max;//정수형 변수와 조건값 key와 최대값저장 변수 선언
    int *pnum = rst;//결과값의 포인터변수 선언
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%c",(pch+i));//포인터를 이용하여 배열에 저장
    }
    for(int i=0;i<10;i++){//10번 반복하여
        cnt = 0;//cnt값 초기화(cnt는 빈도수)
        for(int j=0;j<10;j++){//10번 반복하여
            if(*(pch+i)==*(pch+j)) cnt++;//해당 배열요소가 같으면 빈도수 증가
        }
        *(pnum+i)= cnt;//빈도수 배열에 저장
    }
    for(int i=9;i>0;i--){//9번 반복(역순)
        if(i==9){
            max = *(pnum+9);//첫번째 반복시 max의 초기화
            result = *(pch+i);
        } 
        else{
            if(*(pnum+i)>= max){//빈도수가 최대인 경우
                max = *(pnum+i);
                result = *(pch+i);//해당 요소(char형 문자)를 결과값으로  저장
            } 
        }
    }
    printf("%c %d",result,max);//결과값 출력
}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가
//1 2 1 2 2 1 1 2 2
