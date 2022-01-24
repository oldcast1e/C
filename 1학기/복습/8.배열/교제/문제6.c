#include  <stdio.h>
int main(){

    int N[10],num,cnt,spn=0;
    int key  = 1;
    int rst[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
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

    printf("%d %d\n",N[0],1);
    for(int i=1;i<10;i++){//4
        key = 1;
        for(int j=0;j<i;j++){//
            if(N[i]==N[j])
                key = 0;
        }
        if(key == 1){
            if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
                printf("\n");
            spn++;//줄 띄움 변수 증가
            printf("%d %d",N[i],rst[i]);
        }
    }

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
