#include  <stdio.h>
int main(){

    int n;scanf("%d",&n);//2
    getchar();
    int cnt = 0;
    char arr[20],rep;
    for(int i=0;i<n;i++){
        scanf("%c",&rep);//3
        getchar();//' '
        cnt = 0;
        while(1){
            scanf("%c",&arr[cnt]);//ABC
            if(arr[cnt]=='\n') break;// \n
            cnt++;
        }
        for(int j=0;j<cnt;j++){//3
            for(int k=0;k<rep-48;k++)printf("%c",arr[j]);
        }
        printf("\n");
    }
}



