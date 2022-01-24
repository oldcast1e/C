#include  <stdio.h>
#include<string.h>
int changearra(char *arra,char *arrb,int N,char *rst){
    for(int i=0;i<10;i++)*(rst+i) = 0;
    int result = 0,cnt = 0,num,finalresult = 0;
    // printf("입력받은 문자열: %s\n",arra);
    // printf("입력받은 정수: N = %d\n",N);
    for(int i=0;i<strlen(arra);i++){
        
        if('A'<= *(arra+i) && *(arra+i)<='Z'){//대문자인경우
            *(rst+cnt) = *(arra+i)+ N;
            // if(*(arra+i)>= '[') *(rst+cnt) = 'a'+N-1;//소문자를 벗어난 경우
            cnt ++;
        }
        else if('a'<= *(arra+i) && *(arra+i)<='z'){//소문자인경우
            *(rst + cnt) = *(arra+i) -  N;
            // if(*(arra+i)<= 96) *(rst + cnt) = 'z'-N+1;
            cnt ++;
        }

        else if(('1'<= *(arra+i) && *(arra+i)<='9')){//숫자인 경우
            
            if('1'<= *(arra+i+1)&& *(arra+i+1)<='9'){//십의 자리 = 다음 요소도 숫자인 경우
                // printf("><");
                num = (*(arra+i) - 48)*10 + *(arra+i+1)-48;
                // 다음 숫자에 변화를 주지않고 다음 요소값을 점프해야함.
                //printf("\ncnt = %d\n",cnt);
                for(int j= 0;j<N;j++){
                    if('1'<= *(arra+i+1)&& *(arra+i+1)<='9'){
                        *(rst+cnt) = num+64;
                        cnt ++;
                    }
                    
                }
            }
            else{//일의 자리
                // printf("  --  ");
                if('1'< *(arra+i-1) && *(arra+i-1) <'9'){
                    printf("<>");
                    for(int j= 0;j<N;j++){
                        *(rst+cnt) = *(arra+i)+16;
                        cnt ++;
                    }
                }
                //하나 전의 요소가 숫자가 아니면
                for(int j= 0;j<N;j++){
                   *(rst+cnt) = *(arra+i)+16;
                   cnt ++;
                }
            }
        }
        else{
            *(rst+cnt) = ' ';
            cnt ++;
        } 

    }
    result = (int)strcmp(rst,arrb)==0?1:0;//1이면 충족
    printf("바꾼 문자열: %s\n",rst);
    // printf("rst  = %d\n",result);
    return result;
}

int main(){

    char A[20],B[20],*arra  = A,*pb = B;
    char rst[20],*prst = rst,key = 0;
    int N,cnt,result = 0;
    scanf("%s",A);
    scanf("%s",B);

    for(int i=1;i<=10;i++){//10->1 test
        result = changearra(A,B,i,rst);//두배열이 같으면 1
        if(result == 1){
            printf("%d",1);
            key = 1;
            break;//A->B가능 = 일단 1은 충족
        } 
    }
    
    
    for(int i=1;i<=10;i++){//10->1 test
        result = changearra(B,A,i,rst);//두배열이 같으면 1
        if(result == 1){
            printf("%d",2);
            key = 1;
            break;
        } 
    }
    
    if(key == 0 )printf("%d",0);
    
}
//Qej15J
//SchOOL