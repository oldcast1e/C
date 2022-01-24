#include  <stdio.h>
#include<string.h>
int chagearr(char *A,char *B,char *rst,int N,int len,int len1){
    //변경가능 유무 확인 함수 정의

    char arr[1000],*pa = arr; //입력받은 A의 배열을 고칠 수 없으니
    //새로운 배열을 선언하고
    int numcnt = 0,cnt,result,key = 0;//대체배열 매개변수 선언

    for(int i=0;i<len;i++) *(pa+i) = *(A+i);
    //해당배열에 A배열 요소 저장
    // *(pa+len) = '\0';
    // printf("arr = %s\n",arr);
    // printf("B = %s\n",B);

    strcpy(rst," ");
    // printf("rst = %s\n",rst);

    for(int i=0;i<len;i++){//배열의 길이만큼 반복
        // printf("numcnt = %d\n",numcnt);
        if('A'<= *(pa+i) && *(pa+i)<='Z'){//대문자이면
            // *(pa+i) += N;//해당 요소에 N을 더함
            rst[numcnt] = *(pa+i)+N; numcnt++;
        }
        else if('a'<= *(pa+i) && *(pa+i)<='z'){//소문자이먄
            // *(pa+i) -= N;//해당 요소에 N을 뺌
            rst[numcnt] = *(pa+i)-N; numcnt++;
        }

        else if(('0'<= *(pa+i) && *(pa+i)<='9')){//숫자면

            if('0'<= *(pa+i+1)&& *(pa+i+1)<='9'){//십의 자리
               cnt = (*(pa+i) - 48)*10 + *(pa+i+1)-48;//정수화  
               if(cnt<26){
                   *(pa+i+1) = -1;//다음 숫자를 -1로
                    //printf("\ncnt = %d\n",cnt);
                    for(int j= 0;j<N;j++){//N번 반복하여ㅕ
                        //printf("%c",cnt+64);//출력
                        rst[numcnt] = cnt+64; numcnt++;
                    }
               }
               else key =1;
            }
            else{//일의 '자리
                // printf("  --  ");
               for(int j= 0;j<N;j++){//N번 반복
                //    printf("%c",*(pa+i)+16);//출력
                   rst[numcnt] = *(pa+i)+16; numcnt++;
               }
            }
            if(key == 1){
                for(int j= 0;j<N;j++){//N번 반복
                    // printf("진입 %c",*(pa+i));
                    rst[numcnt] = *(pa+i)+16; numcnt++;
                }
                key = 0;
            }
        }
        else if(*(pa+i)!= -1){//조건 충족하지않는 경우
            rst[numcnt] = ' '; numcnt++;//공백 저장
            // printf(" ");
        } 
    }
    // printf("numcnt = %d\n",numcnt);
    rst[numcnt] = '\0';//마지막값을 널문자
    // printf(">rst = %s\n",rst);
    result = strncmp(rst,B,len1)==0?1:0;//결과저장
    // printf("result = %d\n",result);
    return result;
}
int main(){//메인함수

    char A[1000],*pa  = A;//크기 1000의 배열 정의 및 포인터 연결
    char B[1000],*pb  = B;//크기 1000의 배열 정의 및 포인터 연결
    char rst[1000];//대체할 배열 선언
    int N,cnt,len=0,len2=0,numcnt = 0;;//입력받을 정수와 배열의 길이 임의의 정수 저장 변수 정의

    int rstval,key=0;//결과출력 조건값
    
    for(int i=0;i<21;i++){//21번 반복
        scanf("%c",(pa+i));//해당 요소를 입력받고
        if(*(pa+i)=='\n') break;//엔터가 입력되면 종료
        len ++;//길이 증가
    }
    for(int i=0;i<21;i++){//21번 반복
        scanf("%c",(pb+i));//해당 요소를 입력받고
        if(*(pb+i)=='\n') break;//엔터가 입력되면 종료
        len2 ++;//길이 증가
    }

    for(int i=1;i<=10;i++){//1에서 10까지 판단
        rstval = chagearr(A,B,rst,i,len,len2);//함수 실행
        // printf("<%d>\n",rstval);
        if(rstval == 1){//참이면
            printf("1");//1출력 후 종료
            key++;
            break;
        } 
    }
    for(int i=1;i<=10;i++){//1~10까지 판단
        rstval = chagearr(B,A,rst,i,len2,len);
        // printf("<%d>\n",rstval);
        if(rstval == 1){//참이면 출력후 종료
            printf("2");
            key++;
            break;
        } 
    }

    if(key==0)printf("0");
    // printf("%s",A);
    // for(int i=0;;i++){
    //     if(rst[i]=='\0') break;
    //     printf("%c",rst[i]);
    // }
}

//Qej15J
//SchOOL