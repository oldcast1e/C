#include  <stdio.h>
int main(){
    
    char str[50],chn;//문자를 저장할 배열과 바꿈의 대상이될 변수 chn
    int cnt = 0;//문자의 개수를 저장할 변수
    for(int i=0;i<50;i++){//최대 50번까지 반복
        scanf("%c",&str[i]);//문자를 입력받고
        cnt++;//문자의 개수를 증가
        if(str[i]=='*')//이때 *이나오면 반복 종료
            break;
    }

    for(int i=cnt-1;i>=0;i--){//반대로 시작하여 모음이 있는 위치를 찾음
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            chn = str[i];//해당 위치에 모음이 있다면 chn에 저장후 반복 종료
            break;
        }
        
    }

    for(int i=0;i<cnt;i++){//문자 개수 만큼 반복하여
        if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'){
            str[i] = chn;//모음이 나오면 해당 모음을 chn값으로 바꿈
        }
    }

    for(int j=0;j<cnt;j++){//결과값 출력
        printf("%c",str[j]);
    }
}


