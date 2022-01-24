#include  <stdio.h>
int main(){
    
    char ans[3],inp[3]={'_','_','_'},u;
    int cnt = 0,spn=0;
    for(int i=0;i<3;i++){
        scanf("%c",&ans[i]);
    }
    getchar();
    while(5>cnt){
        scanf("%c",&u);
        getchar();
        for(int i=0;i<3;i++){
            if(ans[i]==u){
                inp[i] = u;
            }
        }
        for(int j=0;j<3;j++){
            printf("%c ",inp[j]);
        }
   
        if(ans[0]==inp[0] && ans[1]==inp[1] && ans[2]==inp[2])
            break;
        cnt++;
        if(cnt!=5)
            printf("\n");

    }


}


