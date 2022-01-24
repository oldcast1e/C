#include  <stdio.h>
int main(){
    char ch[20]={0};//크기 20인 배열 선언
    char *pch = ch;//배열의 포인터 서언
    int cnt=0,key=0,rst,brv=0;//반복사용시 기준값과 결과값, 반복횟수 카운드 변수 선언
    while(1){//무한 반복
        scanf("%c",pch+cnt);//배열에 저장
        if(*(pch+cnt) =='\n') break;//엔터입력시 종료
        cnt++;//엔터가 눌리지않으면 cnt를 증가하고 반복 계속
    }
    // printf("cnt = %d\n",cnt);
    for(int i=cnt;i>=0;i--){//반복횟수 만큼 반복(역)
        if(*(pch+i)== '#'){//배열의 요소가 #인 경우
            key = 1;//기준값을 1로
            for(int j=i-1;j>=0;j--){
                if(*(pch+j)=='#') key = 0;//해당위치보다 앞에 #이 존재하면 다시 0으로
                // printf("j=%d\n",j);
            }
        }
        if(key==1){//기준값이 1인 경우
            // printf("i=%d\n",i);
            rst = i;
            brv = 1;//출력할 변수들을 재설정 후 종료
            break;
        } 
    }
    for(int i=rst-1;i>=0;i--)printf("%c",*(pch+i));//결과값 출력
}
//duck#dduckk#popo

