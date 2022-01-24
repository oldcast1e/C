#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char str[10][100]={},tmp[100];//열10 행100의 배열 정의, 배열 체인지를 위한 배열 정의
    char sentence[1100],*sts  = sentence;//문장입력시 저장할 배열과 포인터 정의
    int x=0,y=0;//열 , 행
    gets(sentence);//문자열을 입력받음
    // printf("%s\n",sentence);
    for(int i=0;;i++){//무한반복
        // printf("%d\n",i);
        if(*(sts+i)!=' '){//공백이 아니면
            str[y][x] = *(sts+i);//해당요소에 저장
            // printf("-");
            x++;//행 증가
        }
        else if(*(sts+i)==' ' || *(sts+i)=='\0'){//공백이거나 널 문자이면
            x = 0;y ++;//행 0 초기화 열 증가
        } 
        if(*(sts+i)=='\0')break;//널 문자이면 종료
    }

    for(int i=0;i<=y;i++){/////->>>>>>>>   i=0;i<=y
        puts(str[i]);//기본값 출력 /단어 분리
    }
    /////////////////////

    for(int i=0;i<=y;i++){/////->>>>>>>>   i=0;i<=y
        for(int j=0;j<=y;j++){//열만큼 반복
            if(i!=j){//조건 
                if(strcmp(str[i],str[j])<0){//str[i]가 str[j]보다 먼저면
                    strcpy(tmp,str[i]);
                    strcpy(str[i],str[j]);
                    strcpy(str[j],tmp);//문자열 교환
                }
            }
        }
    }
    printf("%s",str[0]);//결과값 출력
    // printf("y = %d %s",y,str[y]);

}
//공백을 포함하는 알파벳 소문자로 이뤄진 하나의 문자을 입력받고, 
//1)이를 단어로 분리하고
//2)알파벳 순으로 재정렬하여 출력하라

//strtok사용 금지
//위 함수 제외 문자함수 사용가능

//gets함수 사용

//알파벳순 출력시 단어의 첫 알파벳을 기준으로하며, 같으면 먼저 나온 순으로 출력

//단어의 개수는 최대 10개, 단어의 최대 길이는 100