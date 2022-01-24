#include  <stdio.h>
int main(){

    int gn;
    int m,a,b;
    scanf("%d",&gn);

    for(int i = 1;i<=gn;i++){
        scanf("%d %d %d",&m,&a,&b);
        if(m<b && m>a){
            printf("A\n");
        }//무조건
        else if(m>b && m<a){
            printf("B\n");
        }//무조건
        
        else if(m<a && m<b  || a==b)
            printf("draw\n");
            
        else{
            a = m-a;
            b = m-b;
            a = (a>0?a:a*(-1));
            b = (b>0?b:b*(-1));
            if(a>b)
                printf("B");
            else
                printf("A");

        }
    }
}
