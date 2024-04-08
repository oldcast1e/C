#include  <stdio.h>
int main(){
    
    int num[6]={0,1,2,3,4,5};
    int inp[3];

    for(int i=0;i<3;i++){
        scanf("%d",&inp[i]);
    }

    for(int j=0;j<3;j++){
        if(inp[j]==0)
            printf("");
    }
}
