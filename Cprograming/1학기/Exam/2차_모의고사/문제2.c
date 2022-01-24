#include  <stdio.h>
int main(){
    
    int N,spn=0;
    scanf("%d",&N);
    int A = 900;
    int B = 750;
    int C = 200;


    for(int a = 1;a< N/a;a++){
        for(int b = 1;b< N/b;b++){
            for(int c = 1;c< N/c;c++){
                if(b%2==0){
                    if(c<a || c<b){
                        if(N==(A*a+B*b+C*c)){
                            if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
                                printf("\n");
                            spn++;//줄 띄움 변수 증가
                            printf("%d %d %d",a,b,c);
                        }
                            
                    }
                }
            }
        }
    }

}



