#include  <stdio.h>
int main(){
    
    char str[10];//크기가 10인 배열 선언
    char *p = str,*q=str;//두개의 포인터 선언
    // int strnum = 0;

    for(p=str;p<str+10;p++){//10번 반복하여ㅛ
        scanf("%c",p);//포인터(배열)에 저장
        // *(q+strnum) = *p;
        // strnum ++;
    }
    
    int cnt,maxcnt =-1;//반복횟수저장 cnt와 최대 반복횟수 maxcnt 변수 선언
    char rststr;//최대반복횟수일때의 char값
    for(p=str;p<str+10;p++){//10번 반복 (ㄱ)
        cnt = 0;//cnt초기화
        for(q=str;q<str+10;q++){//10번반복 (ㄴ)
            if(*p==*q) cnt ++;// (ㄱ)과 (ㄴ)이 같은 경우 cnt증가
        }

        if(cnt>maxcnt){//cnt가 maxcnt 보다 큰 경우
            maxcnt = cnt;//maxcnt에 저장하고
            rststr = *p;//해당 요소값을 rststr에 저장
        }

    }
    printf("%c %d",rststr,maxcnt);//결과갑ㄱ 출력

    // for(p=str;p<str+10;p++){
    //     scanf("%c",p);
    //     *(q+strnum) = *p;
    //     strnum ++;
    // }

}

// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

