#include  <stdio.h>
int main() 
{
    int n,firstrst=0;
    int cnt;
    int opt=1;


    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        firstrst +=i;
        if(i==n)
            break;
        firstrst *= 10;
    }
    int secondrst=firstrst;//5자리 기본형
    printf("%d\n",firstrst);
    
    for(int i=0;i<n-1;i++){
        opt *= 10;
    }


    for(int i=1;i<n;i++){

        if(i%2==0){
            firstrst=(secondrst%opt);//4자리수로 만듦.
            cnt = secondrst/opt;
            secondrst = firstrst*10+cnt;
            // firstrst += (secondrst%10)
            printf("%d\n",secondrst);
            firstrst = secondrst;
            cnt = 0;
            
        
        }
        else {

            secondrst = (firstrst%opt);
            cnt = firstrst/opt;
            firstrst = secondrst*10+cnt;
            printf("%d\n",firstrst);
            secondrst = firstrst;
            cnt = 0;

            
        }
        
    }

}