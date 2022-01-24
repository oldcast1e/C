#include  <stdio.h>
#include <string.h>
int main(){//메인함수
    char str[10][101]={},tmp[101];//크기 10,100의 이중 배열과 배열 체인지를 위한 함수 정의
    char sentence[1110],*sts  = sentence;//크기 1100의 문자 배열과 포인터 연결
    int x=0,y=0;//열 행 정의
    gets(sentence);//문자열 입력받음
    // printf("%s\n",sentence);
    for(int i=0;;i++){//무한 반복
        // printf("%d\n",i);
        
        if(*(sts+i)!=' '){//공백이 아니면
            str[y][x] = *(sts+i);//해당 열과 행에 저장
            // printf("-");
            x++;
        }
        else if(*(sts+i)==' ' || *(sts+i)=='\0'){//공백이거나 널 문자이면
            x = 0;y ++;//행을 0으로, 열 증가
        } 
        if(*(sts+i)=='\0')break;//엔터가 입력되면 종료
        
    }
    for(int i=0;i<=y;i++){/////->>>>>>>>   i=0;i<=y
        printf("%s\n",str[i]);//순서대로 단어 출력
    }

    for(int i=0;i<=y;i++){/////->>>>>>>>   i=0;i<=y
        for(int j=0;j<=i;j++){//알파벳 순으로 정렬
            if(i!=j){//조건 만족시
                if((strncmp(str[i],str[j],1)<0)){//정렬
                    // printf("<%c %c>\n",str[j][0],str[i][0]);
                    strcpy(tmp,str[i]);
                    strcpy(str[i],str[j]);
                    strcpy(str[j],tmp);//문제 2-1과 방법 동일
                }
            }
        }
    }
    for(int i=0;i<=y;i++){/////->>>>>>>>   i=0;i<=y
        puts(str[i]);//순서대로 단어 출력
    }
    // printf("%s",str[y]);
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