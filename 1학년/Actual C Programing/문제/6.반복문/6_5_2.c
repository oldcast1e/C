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

        oldval = max1;
        max1 = (max1<m?m:max1);


        if(i>=1){
            if(max1>=max2){
                max2 = oldval;
            }
        }
        else
            max2 = oldval;
        

    }   
    printf("%d\n",max1);
    printf("%d\n",max2);

}
    
    

