#include  <stdio.h>
int main(){
    int alb[26];
    for(int i=0;i<26;i++) alb[i] = -1;
    char arr[100],cnt =0;//arr[] -> 입력한 문자열
    int key = 0;
    while(1){
        scanf("%c",&arr[cnt]);
        if(arr[cnt]=='\n') break;
        cnt++;
    }
    alb[arr[0]-97] = 0;
    for(int i=1;i<cnt;i++){//cnt = 반복횟수 = 입력한 글자의 수
        key = 1;
        for(int j=0;j<i;j++){
            if(arr[i]==arr[j])key = 0;
        }
        if(key == 1)alb[arr[i]-97] = i;
    }
    for(int i=0;i<26;i++)printf("%d ",alb[i]);
}


