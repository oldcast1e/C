#include  <stdio.h>
int main(){
    
    char E[9];
    int cnt;
    for(int i=0;i<9;i++){
        scanf("%c",&E[i]);
    }
    for(int i=0;i<9;i++){
        cnt =0;
        for(int j=0;j<9;j++){
            if(E[i]==E[j])
                cnt ++;
        }
        printf("%d ",cnt);
    }
}
