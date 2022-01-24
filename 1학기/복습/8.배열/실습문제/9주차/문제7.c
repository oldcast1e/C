#include  <stdio.h>
int main(){
    
    int N[10],rst[10];
    int cnt = 0,key,spn=0;;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
    }
    for(int i=0;i<10;i++){
        cnt = 0;
        for(int j=0;j<10;j++){
            if(N[i]==N[j])
                cnt++;
        }
        rst[i] = cnt;
    }
    printf("%d %d\n",N[0],rst[0]);
    for(int i=1;i<10;i++){
        key = 1;
        for(int j=0;j<i;j++){
            if(N[i]==N[j])
                key = 0;
        }
        if(key ==1){
            if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
                printf("\n");
            spn++;//줄 띄움 변수 증가
            printf("%d %d",N[i],rst[i]);
        }
    }


}


