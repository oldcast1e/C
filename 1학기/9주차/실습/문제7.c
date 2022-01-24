#include  <stdio.h>
int main(){
    
    int cnt,key,spn=0;
    //카운트 변수 cnt, 출력 조건 변수 key, 줄 띄움 변수 spn
    int D[10];//크기가 10인 배열 선언
    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&D[i]);//배열에 각각의 값 입력받음
    }

    for(int i=0;i<10;i++){//10번 반복하여
        cnt = 0;//카운트 변수와 입력 조건 변수 초기화
        key = 0;

        for(int j=0;j<10;j++){//10번 반복하여
            if(D[i] == D[j])//같은 값의 반복 횟수 찾음
                cnt ++;
        }

        if(i!=0){//i가 0이 아니면(0이면 이때까지 나왔던 값과 비교할 수 없음)
            for(int k=0;k<i;k++){//현재의 숫자까지
                if(D[i]==D[k])//비교하여 같은 수가 있는 경우
                    key ++;//key의 값을 올림
            }
        }

        if(key==0){//key의 값이 0인 경우 == 그 전 입력에서 같은 값이 없는 경우
            if(spn!=0)//첫번째 열만 안 띄우고
                printf("\n");//문자 출력 전 줄 바꿈
            spn ++;
            printf("%d %d",D[i],cnt);//해당 숫자와 반복횟수 출력
        }
    }

}


