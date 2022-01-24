#include  <stdio.h>
int main() 
{
    int n,m;
    int cnt=-1;

    int overval = 1,oldval;
    int max1=-1,max2=-1;

    scanf("%d",&n);
    for(int i=0;i<n;i++){

        scanf("%d",&m);
        if(i>=1){
            oldval = max1;
            max1 = (max1<m?m:max1);

            max2 =(m<=cnt?cnt:m);
            printf("%d번째 max2의 값: %d\n",i,max2);
            
            if(max1==max2){
                max2 = oldval;
                cnt = max2;
            }
            else
                cnt = m;     
            
        }
        else
            max1 = (max1<m?m:max1);
        

    }    
    max1= max1;
    max2 = max2;
    printf("%d\n",max1);
    printf("%d\n",max2);

}
    
    

