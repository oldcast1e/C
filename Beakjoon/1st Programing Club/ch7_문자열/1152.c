#include  <stdio.h>
int main(){
    char arr[1000001];
    int cnt,sp=0;
    while(1){
        scanf("%c",&arr[cnt]);

        if(cnt==0 && arr[0]==' ') sp--;
        if(arr[cnt]=='\n'){
            if(arr[cnt-1]==' ') sp--;
            cnt++;
            break;
        } 
        cnt++;
    }
    for(int i=0;i<cnt;i++){if(arr[i]==' ') sp ++;}
    printf("%d",sp+1);
}
