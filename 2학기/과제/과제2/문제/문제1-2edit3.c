#include  <stdio.h>
#include<string.h>
int changearra(char *arra,char *arrb,int N,char *rst,int len){
    for(int i=0;i<10;i++)*(rst+i) = 0;
    int result = 0,cnt = 0,num,finalresult = 0,key = 1;
    // printf("입력받은 문자열: %s\n",arra);
    // printf("입력받은 정수: N = %d\n",N);
    for(int i=0;i<len;i++){
        
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

        else if(('0'<= *(arra+i) && *(arra+i)<='9')){//숫자인 경우
            // printf("><><");
            if('0'<= *(arra+i+1)&& *(arra+i+1)<='9'){//십의 자리
            key = 0;
               num = (*(arra+i) - 48)*10 + *(arra+i+1)-48;

            //    *(arra+i+1) = -1;
            //    printf("+");
               for(int j= 0;j<N;j++){
                   *(rst+cnt)=num+64;
                   cnt ++;
               }
            }
            else if(key == 1){//일의 '자리
                // printf("  --  ");
               for(int j= 0;j<N;j++){
                   *(rst+cnt) = *(arra+i)+16;
                   cnt++;
               }
            }
            
        }
        else{
            *(rst+cnt) = ' ';
            cnt ++;
        } 

    }
    result = (int)strncmp(rst,arrb,len)==0?1:0;//1이면 충족
    // printf("바꾼 문자열: %s\n",rst);
    // printf("rst  = %d\n",result);
    return result;
}

int main(){

    char A[20],B[20],*arra  = A,*arrb = B;
    char rst[20],*prst = rst,key = 0;
    int N,cnt,result = 0;

    int lena=0,lenb=0;
    for(int i=0;i<20;i++){
        scanf("%c",(arra+i));
        if(*(arra+i)=='\n') break;
        lena ++;
    }

    for(int i=0;i<20;i++){
        scanf("%c",(arrb+i));
        if(*(arrb+i)=='\n') break;
        lenb ++;
    }

    // printf("%d %d",lena,lenb);
    for(int i=1;i<=10;i++){//10->1 test
        result = changearra(A,B,i,rst,lena);//두배열이 같으면 1
        if(result == 1){
            printf("%d",1);
            key = 1;
            break;//A->B가능 = 일단 1은 충족
        } 
    }
 
    
    for(int i=1;i<=10;i++){//10->1 test
        result = changearra(B,A,i,rst,lenb);//두배열이 같으면 1
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