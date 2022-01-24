#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){

    int passanger,cnt = 0,key,notrp=0;
    int seat[22],*pst = seat;
    int repeat[21];

    int passpoint =1;
    

    scanf("%d",&passanger);
    for(int k=0;k<passanger;k++) repeat[k] = 0;

    if(passanger < 5) passpoint = -1;

    while(1){
        scanf("%d",(pst+cnt));
        cnt++;
        if(cnt == passanger) break;
    }

    if(passpoint == 1){

        for(int i=0;i<passanger;i++){
            for(int j=0;j<passanger;j++){
                if(i!=j){
                    if(*(pst+i) == *(pst+j)) repeat[i] ++;
                }
            }
        }

        for(int i=0;i<passanger;i++){
        //
            key = 1;
            for(int j=0;j<i;j++){
                if(seat[i]==seat[j]) key = -1;
            }
            if(repeat[i]>0 && key == 1){
                notrp ++;
                printf("%d %d\n",seat[i],repeat[i]+1);
            }
        }
    }

    if(notrp == 0 && passpoint == 1)printf("%d",0);
    if(passpoint == -1)printf("%d",-1);

}