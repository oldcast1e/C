#include  <stdio.h>
int main(){
    
    int total=0;//cat이 나오는 횟수
    char u;//입력받을 char형 변수
    char D[7]={0,};//배열 선언
    for(int i=0;i<7;i++){
        scanf("%c",&u);//7번 반복하여 u를 입력받아
        D[i]=u;//배열에 저장
    }

    for(int j=0;j<7;j++){//7번 반복하여
        if(D[j]=='c'){//j 번째 배열 항목이 c이면
            if(D[j+1]=='a'){//다음 배열 항목이 a인지 확인 후
                if(D[j+2]=='t'){//그 다음 항목이 t이면
                    total ++;//total을 하나 올림
                }
            }
        }
    }
    printf("%d",total);//cat이 나온 횟수 출력
}


