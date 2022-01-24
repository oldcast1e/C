#include<stdio.h>
int main(){
    int a,b,c,a2,b2,c2;
    scanf("%d/%d/%d",&a,&b,&c);
    scanf("%d/%d/%d",&a2,&b2,&c2);

    if(a>a2){
        printf("%02d/%02d/%02d",a2,b2,c2);
    }
    else if(a==a2){ //  연도가 같은 경우

        if(b>b2)
            printf("%02d/%02d/%02d",a2,b2,c2);
        
        else if(b==b2)

            if(c>c2)
                printf("%02d/%02d/%02d",a2,b2,c2);
            else if(c<c2)
                printf("%02d/%02d/%02d",a,b,c);
            else
                printf("%02d/%02d/%02d*",a2,b2,c2);
        
        else 
            printf("%02d/%02d/%02d",a,b,c);
    }
    else if(a<a2){
        printf("%02d/%02d/%02d",a,b,c);
    }
        
}