#include  <stdio.h>
int main(){
    
    char U[10],rst[10];
    int cnt,key;
    for(int i=0;i<10;i++){
        scanf("%c",&U[i]);
    }
    for(int i=1;i<10;i++){
        key = 1;
        for(int j=0;j<10;j++){
            if(i!=j){
                if(U[i]==U[j])
                    key = 0;
            }   
        }
        if(key==1){
            rst[cnt] = U[i];
            cnt++; 
        }
    }
    for(int i=0;i<cnt;i++){
        printf(" %c",rst[i]);
    }

}


