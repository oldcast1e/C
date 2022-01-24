#include  <stdio.h>
int main(){
    
    int n,tmp,rep,spn=0;
    int N[10][10];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&N[i][j]);
        }
    }
    n --;
    rep = n/2;
    for(int i=0;i<rep;i++){
        tmp = N[i][i];
        N[i][i] = N[n-i][n-i];
        N[n-i][n-i] = tmp;
    }
    for(int i=0;i<rep;i++){
        tmp = N[i][n-i];
        N[i][n-i] = N[n-i][i];
        N[n-i][i] = tmp;
    }

    for(int i=0;i<n+1;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        for(int j=0;j<n+1;j++){
            printf("%d ",N[i][j]);
        }
    }

}

// 11 12 13 14 15
// 21 22 23 24 25
// 31 32 33 34 35
// 41 42 43 44 45
// 51 52 53 53 55

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
