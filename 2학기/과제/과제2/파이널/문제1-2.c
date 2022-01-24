#include  <stdio.h>
#include<string.h>
int changenum(char *carr,char *cmparr,char *rst ,int N,int len){
    int cnt = 0,num,key,result;
    char changeval;

    char str[21],*arr = str;
    for(int i=0;i<21;i++){
        *(arr+i) = *(carr+i);
    }
    for(int i=0;i<len;i++){//배열의 길이만큼 반복  
        if('A'<= *(arr+i) && *(arr+i)<='Z'){//대문자이면
            rst[cnt] = *(arr+i) + N;
            cnt++;
        }
        else if('a'<= *(arr+i) && *(arr+i)<='z'){//소문자이먄
            rst[cnt] =  *(arr+i) - N;//해당 요소에 N을 뺌
            cnt++;
        }
        else if(('0'<=*(arr+i) && *(arr+i)<='9')){//숫자면
            
            if('0'<= *(arr+i+1) && *(arr+i+1)<='9'){//십의 자리
                num = 1;num *= (*(arr+i)-48)*10;num += (*(arr+i+1))-48;
                *(arr+i+1) = -1;
                for(int j = 0;j<N;j++){
                    rst[cnt] = num + 64;cnt++;
                }
                // continue;
            }
            else{//
               for(int j = 0;j<N;j++){
                    rst[cnt] = *(arr+i) + 16;cnt++;
                }
            }
            
        }
        else if(*(arr+i) != -1){
            rst[cnt] = ' ';cnt++;
        }
    }

    result = strncmp(rst,cmparr,len)==0?1:0;

    return result;


    //반환값을 rst로 줘서 1씩 올려가면서 비교하면 되겠네!!! => 안됨
}
int main(){//메인함수

    char A[10000],*pa  = A;//크기 20의 배열 정의 및 포인터 연결
    char B[10000],*pb  = B;//크기 20의 배열 정의 및 포인터 연결

    char rst[10000],*prst = rst,changeval=' ';
    int val = 0,cntval=0;
    int N=0,cnt=0,num,len1=0,len2 = 0,key=1;//입력받을 정수와 배열의 길이 임의의 정수 저장 변수 정의
    for(int i=0;i<21;i++){//20번 반복
        scanf("%c",(pa+i));//해당 요소를 입력받고
        if(A[i]=='\n') break;//엔터가 입력되면 종료
        len1 ++;//길이 증가
    }
    for(int i=0;i<21;i++){//20번 반복
        scanf("%c",(pb+i));//해당 요소를 입력받고
        if(B[i]=='\n') break;//엔터가 입력되면 종료
        len2 ++;//길이 증가
    }

    for(int I = 1;I<=10;I++){
        strcpy(rst," ");
        val = changenum(A,B,rst,I,len1);
        if(val ==1){
            printf("%d\n",val);
            cntval ++;
            break;
        }
    }
    for(int I = 1;I<=10;I++){
        if(cntval >0 )break;
        strcpy(rst," ");
        val = changenum(B,A,rst,I,len2);
        if(val ==1){
            printf("%d\n",val+1);
            cntval++;
            break;
        }
    }
    if(cntval ==0)printf("%d",0);
    
    // printf("len1 = %d\n",len1);
   
    // printf("%s",A);
}
//CLikp5tGLE?Qej15J

//FOfhmEEEqJOH TbgOOO
//DMhjoEsHMF RdiOK 
//DMhjoEsHMF RdiOK

//Qej15J
//SchOOL