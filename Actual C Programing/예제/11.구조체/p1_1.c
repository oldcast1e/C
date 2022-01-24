#include  <stdio.h>
int main(){
    int md,sd[3]={0},bvg;
    int total=0,tot[5];
    printf("Main dish: ");
    scanf("%d",&md);

    tot[0] = md;
    for(int i=0;i<3;i++){
        printf("Side dish %d: ",i+1);
        scanf("%d",&sd[i]);
        tot[i+1] = sd[i];
    }
    printf("Beverage: ");
    scanf("%d",&bvg);
    tot[4] = bvg;

    total += md;
    for(int i=0;i<3;i++)total += sd[i];
    total += bvg;

    printf("Total: ");
    for(int i=0;i<5;i++){
        printf("%d ",tot[i]);
        if(i!=4)printf("+ ");
    }
    printf("= %d",total);
    


}