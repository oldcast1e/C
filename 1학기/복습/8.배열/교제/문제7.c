#include  <stdio.h>
int main(){
    
    int N[100];
    int n,m,cnt=0;
    scanf("%d %d",&n,&m);//n개 입력하여 더해서 m이 되는 경우의 수

    for(int i=0;i<n;i++){
        scanf("%d",&N[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
        if(i!=j){
            if((N[i]+N[j])==m)
                cnt++;
        }
        }
    }
    printf("%d",cnt/2);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
