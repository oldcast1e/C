#include  <stdio.h>
int main(){
    
    char str1[50],str2[50],chn1,chn2;//문자를 저장할 배열과 바꿈의 대상이될 변수 chn
    int cnt1 = 0,cnt2=0;//문자의 개수를 저장할 변수
    int stt1=0,stt2=0,bef1=0,bef2=0;

    int gamekey1 = 1,gamekey2 = 1;

    for(int i=0;i<50;i++){//최대 50번까지 반복
        scanf("%c",&str1[i]);//문자를 입력받고
        cnt1++;//문자의 개수를 증가
        if(str1[i]=='*')//이때 *이나오면 반복 종료
            break;
    }
    getchar();
    for(int i=0;i<50;i++){//최대 50번까지 반복
        scanf("%c",&str2[i]);//문자를 입력받고
        cnt2++;//문자의 개수를 증가
        if(str2[i]=='*')//이때 *이나오면 반복 종료
            break;
    }
    ///////////////////////////////////////////

    while(cnt1-1>stt1 && cnt2-1>stt2 || (gamekey1+gamekey2)!=2){

        for(int i=stt1;i<cnt1;i++){//
        if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'){
            chn1 = str1[i];//해당 위치에 모음이 있다면 chn1에 저장후 반복 종료
            bef1 = stt1;////이전 stt값을 bef에 저장하여 모음변환시 중복이 안되도록함
            stt1 = i+1; //stt:똑같은 위치에서 모음이 바꾸지 않도록 함.
            gamekey1 = 1;//반복조건

            break;
        }
        else //모음이 없다면
            gamekey1 = 0;//반복조건값을 0으로
        
    }
    for(int i=stt2;i<cnt2;i++){//
        if(str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u'){
            chn2 = str2[i];//해당 위치에 모음이 있다면 chn2에 저장후 반복 종료
            bef2 = stt2;//이전 stt값을 bef에 저장하여 모음변환시 중복이 안되도록함
            stt2 = i+1;//stt:똑같은 위치에서 모음이 바꾸지 않도록 함.
            gamekey2 = 1;//반복조건
            break;
        }
        else    //모음이 없다면
            gamekey2 =0;//반복조건값을 0으로
        
    }
    if((gamekey1+gamekey2)!=2)//반복조건값이 유효하지 않다면
        break;//반복 종료

    for(int i=bef1;i<cnt1;i++){//(ㄷ)
        if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'){
            str1[i] = chn2;//해당 위치에 모음이 있다면 chn에 저장후 반복 종료
            break;
        }
        
    }
    for(int i=bef2;i<cnt2;i++){//
        if(str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u'){
            str2[i]= chn1;//해당 위치에 모음이 있다면 chn에 저장후 반복 종료
            break;
        }
        
    }
    }


    //////////////////////
    for(int j=0;j<cnt1;j++){//결과값 출력
        printf("%c",str1[j]);
    }
    printf("\n");
    for(int j=0;j<cnt2;j++){//결과값 출력
        printf("%c",str2[j]);
    }


    
}


