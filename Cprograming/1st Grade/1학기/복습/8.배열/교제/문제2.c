#include  <stdio.h>
int main(){
    
    int n,cnt=0;
    char U[100];
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        scanf("%c",&U[i]);
    }
    for(int i=0;i<n;i++){
        if(U[i]=='c')
            if(U[i+1]=='a')
                if(U[i+2]=='t')
                    cnt++;
    }
    printf("%d",cnt);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
