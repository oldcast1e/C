#include  <stdio.h>
int main() 
{
    int n;
    int a,b;
    scanf("%d",&n);
    a = n/10;
    b = n%10;
    if(n>20){
        if(a==9)
            printf("ninety");
        else if(a==8)
            printf("eighty");
        else if(a==7)
            printf("seventy");
        else if(a==6)
            printf("sixty");
        else if(a==5)
            printf("fifty");
        else if(a==4)
            printf("fourty");
        else if(a==3)
            printf("thirty");
        else if(a==2)
            printf("twenty");
    // else if(a==1)
    //     printf("eighty");

        if(b==9)
            printf("-nine");
        else if(b==8)
            printf("-eight");
        else if(b==7)
            printf("-seven");
        else if(b==6)
            printf("-six");
        else if(b==5)
            printf("-five");
        else if(b==4)
            printf("-four");
        else if(b==3)
            printf("-three");
        else if(b==2)
            printf("-two");
        else if(b==1)
            printf("-one");
    }
    else if(10<=n && n<20){

        if(b==9)
            printf("nineteen");
        else if(b==8)
            printf("eighteen");
        else if(b==7)
            printf("seventeen");
        else if(b==6)
            printf("sixteen");
        else if(b==5)
            printf("fifteen");
        else if(b==4)
            printf("fourteen");
        else if(b==3)
            printf("thirteen");
        else if(b==2)
            printf("twelve");
        else if(b==1)
            printf("eleven");
        else if(b==0)
            printf("ten");
    }
    else
        printf("none");


}