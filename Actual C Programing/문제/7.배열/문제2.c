#include  <stdio.h>
int main(){
    
    int N,cnt=0;
    char tmp;
    scanf("%d",&N);
    char str[N];
    scanf("%c",&tmp);
    for(int i=0;i<N;i++){
        scanf("%c",&str[i]);
    }

    for(int i=0;i<N;i++){
        if(str[i]=='c'){
            if(str[i+1]=='a')
                if(str[i+2]=='t')
                    cnt++;
        }
    }
    printf("%d",cnt);
}
