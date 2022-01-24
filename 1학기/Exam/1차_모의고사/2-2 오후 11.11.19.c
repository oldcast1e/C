#include  <stdio.h>
int main(){

    char u;
    char smamin='a'-1,lagmin='Z'+1;
    int key=0,cnt=0,lakey=0;
    //소문자: 가장 나중 문자
    //대문자: 가장 빠른 문자
    while(1){
        scanf("%c",&u);
        if(u=='0')
            break;
        else{
            if('a'<=u && u<='z'){//소문자
                key = 1;
                if(u>smamin)
                    smamin = u;
            }
            else{//대문자
                key =2;
                if(u<lagmin)
                    lagmin = u;

            }
        }
        if(cnt==0){
            lakey = key;
            cnt++;
        }

    }
    //대문자 먼저 입력시 대문자 부터
    if(lakey==1){
        if(smamin != 'a'-1){
            printf("%c",smamin);
        }
        if(lagmin!='Z'+1){
            printf("%c",lagmin);
        }
    }
    else{
        if(lagmin!='Z'+1){
        printf("%c",lagmin);
    }
        if(smamin != 'a'-1){
        printf("%c",smamin);
    }
    
    }


}


