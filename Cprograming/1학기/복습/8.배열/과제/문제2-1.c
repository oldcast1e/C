#include  <stdio.h>
int main(){
    
    char str[50],chn;
    int cnt = 0;
    while(1){
        scanf("%c",&str[cnt]);
        if(str[cnt]=='*')
            break;
        cnt++;
    }
    for(int i=cnt;i>=0;i--){
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'){
            chn = str[i];
            break;
        }
    }

    for(int i=0;i<cnt;i++){
        if(str[i]=='a' ||str[i]=='e' ||str[i]=='i' ||str[i]=='o' ||str[i]=='u'){
            printf("%c",chn);
        }
        else printf("%c",str[i]);
    }
    printf("*");

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
