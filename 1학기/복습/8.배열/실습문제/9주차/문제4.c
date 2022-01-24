#include  <stdio.h>
int main(){
    
    int N[10],k,spn=0;
    int a=0,b=0,c=0;

    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
    }
    for(int i=0;i<10;i++){
        if(N[i]==1)
            a++;
        else if(N[i]==2)
            b++;
        else if(N[i]==3)
            c++;
    }

    for(int i=1;i<=3;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가

        printf("%d:",i);
        if(i==1) k = a;
        else if(i==2) k = b;
        else if(i==3) k = c;
        for(int j=0;j<k;j++){
            printf("*");
        }
    }   
}


