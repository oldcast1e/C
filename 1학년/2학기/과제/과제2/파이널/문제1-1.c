#include  <stdio.h>
#include<string.h>
int main(){//메인함수

    char A[21],*pa  = A;//크기 20의 배열 정의 및 포인터 연결
    char rst[21],*prst = rst,changeval;
    int N,cnt=0,num,len=0,key=1;//입력받을 정수와 배열의 길이 임의의 정수 저장 변수 정의
    for(int i=0;i<21;i++){//20번 반복
        scanf("%c",(pa+i));//해당 요소를 입력받고
        if(*(pa+i)=='\n') break;//엔터가 입력되면 종료
        len ++;//길이 증가
    }
    
    scanf("%d",&N);//정수를 입력받음
    // printf("len = %d\n",len);
    for(int i=0;i<len;i++){//배열의 길이만큼 반복  
        if('A'<= *(pa+i) && *(pa+i)<='Z'){//대문자이면
           
            // printf(">%c\n",*(pa+i));
            *(prst+cnt) = *(pa+i) += N;
            cnt++;
        }
        else if('a'<= *(pa+i) && *(pa+i)<='z'){//소문자이먄
           
            *(prst+cnt) =  *(pa+i) -= N;//해당 요소에 N을 뺌
            cnt++;
        }
        else if(('0'<= *(pa+i) && *(pa+i)<='9')){//숫자면
            
            if('0'<= *(pa+i+1)&& *(pa+i+1)<='9'){//십의 자리
                num = 1;
                num *= (*(pa+i)-48)*10;
                num += (*(pa+i+1)-48);
                key=0;
                // printf("num = %d | rst = %c\n",num,num + 64);
                for(int j = 0;j<N;j++){
                    *(prst+cnt) = num + 64;
                    cnt++;
                }
                // printf("[%s]\n",rst);
                // printf("(%c)\n",*(pa+i+N-1));
                // printf("basic i = %d\n",i);
                // printf("changed i = %d\n",i+N-1);
                i = i + N -1;
                // continue;
            }
            else if(key!=0){//
                // printf("----");
                //다음숫자가 숫자
               
               changeval = *(pa+i);
               for(int j = 0;j<N;j++){
                    *(prst+cnt) =changeval + 16;
                    cnt++;
                }
                key = 1;
            }
            
        }
        else{
            
            *(prst+cnt) = ' ';
            cnt++;
        }
    }
    for(int i=0;i<=cnt;i++) *(pa+i)= *(prst+i);
    printf("%s",A);
}
//CLikp5tGLE?Qej15J

//FOfhmEEEqJOH TbgOOO
//DMhjoEsHMF RdiOK 
//DMhjoEsHMF RdiOK