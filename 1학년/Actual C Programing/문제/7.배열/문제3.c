#include  <stdio.h>
int main(){
    
    char str[5],tmp;
    int cnt =0;
    for(int i=0;i<5;i++){
        scanf("%c",&str[i]);
    }

    for(int i=0;i<5;i++){
        if(cnt!=0)
            printf("\n");
        cnt ++;

        for(int j=0;j<5;j++){
            printf("%c",str[j]);
            }
            
        tmp = str[4];
        for(int k=0;k<=3;k++){
            str[4-k]= str[3-k]; 
        }
        str[0]= tmp;
    }

  



}
