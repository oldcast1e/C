#include  <stdio.h>
int main(){
    int cnt  = 0;
    char *str[3] = {
        "Time is gold",
        "No pain No gain",
        "No sweat No sweet"
    };
    // for(int j=0;j<20;j++){
    //     if(*str[j] == 'a') cnt ++;
    // }
    // char *str[3][20] = {
    //     {"Time is gold"},
    //     {"No pain No gain"},
    //     {"No sweat No sweet"}
    // };
    for(int i=0;i<3;i++){
        for(int j=0;str[i][j];j++) if(str[i][j]=='a') cnt ++;
    }
    printf("%d",cnt);
}