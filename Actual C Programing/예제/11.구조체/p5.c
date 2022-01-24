#include  <stdio.h>
struct lb{
    /* data */
    int md,sd[3],bvg;
};

int main(){

    struct lb lunch,*pl = &lunch;

    int total = 0,tot[5];
    printf("Main Dish: ");
    scanf("%d",&pl->md);
    tot[0] = lunch.md;

    for(int i=0;i<3;i++){
        printf("Side dish %d: ",i+1);
        scanf("%d",&pl->sd[i]);
        tot[i+1] = lunch.sd[i];
    }

    printf("Beverage: ");
    scanf("%d",&pl->bvg);
    tot[4] = lunch.bvg;
    printf("Total: ");
    for(int i=0;i<5;i++){
        total += tot[i];
        printf("%d ",tot[i]);
        if(i!=4)printf("+ ");
    }
    printf("= %d",total);

}