#include  <stdio.h>
int main(){
    
    char str[6][5]={{"ZERO-"},{"ONE--"},{"TWO--"},{"THREE"},{"FOUR-"},{"FIVE-"}};
    int inp[3]={0,},cnt=0;

    for(int i=0;i<3;i++){
        scanf("%d",&inp[i]);
    }
    // printf("%s",str[inp[0]][5]);
    for(int i=0;i<3;i++){
        if(cnt!=0)
            printf("\n");
        cnt++;
        for(int j=0;j<5;j++){
            printf("%c",str[inp[i]][j]);
        }
    }


    
}
