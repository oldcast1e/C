#include  <stdio.h>
int main(){
    
    int N,spn=0;
    int num[10];
    char str[10];
    scanf("%d",&N);
    getchar();
    for(int i=0;i<N;i++){
        scanf("%c",&str[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
    }

    for(int i=0;i<N;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        printf("x[%d%%%d]=x[%d]=%c",num[i],N,num[i]%N,str[num[i]%N]);
    }


}


