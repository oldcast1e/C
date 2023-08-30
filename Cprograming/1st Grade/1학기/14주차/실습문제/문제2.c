#include  <stdio.h>
int main(){
    
    char ch[20];//문자열 선언
    char *pch = ch;//문자열의 주소 선언
    int cnt;//#이 처음나오는 순서
    for(int i=0;i<20;i++){//20번 반복(최대)
        scanf("%c",(pch+i));//포인터를 통해 요소를 입력받음
        if(*(pch+i)=='#') cnt = i-1;//해당 요소가 #인 경우 해당 위치를 cnt에 저장
        if(*(pch+i) == '\n'){//엔터가 나오면 반복을 종료함
            break;
        } 
    }

    for(int i=cnt;i>=0;i--){//cnt부터 0까지 역순으로(반대로 출력위함)
        
        if(*(pch+i)=='#') break;//#이 나오면 종료
        printf("%c",*(pch+i));//역순으로 문자를 출력한다.
        
    }
    

    
}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

