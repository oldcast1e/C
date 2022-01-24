#include  <stdio.h>

int main(){

    int cnt,cntnum,rst,sum=0;
    char str[80];
    scanf("%d",&cnt);
    getchar();
    for(int i=0;i<cnt;i++){
        cntnum = 0;
        sum = 0;
        
        for(int j=0;j<80;j++){
            scanf("%c",&str[j]);
            cntnum ++;
            // printf("%d ",cntnum);
            if(str[j]!= 'O' && str[j]!= 'X') break;
        }

        rst = 0;
        for(int k=0;k<cntnum;k++){
            if(str[k]=='O') rst++;
            else rst = 0;

            sum += rst;
        }
        printf("%d\n",sum);

    }
}


