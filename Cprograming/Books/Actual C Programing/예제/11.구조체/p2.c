#include  <stdio.h>
struct lb{
    /* data */
    int md,sd[3],bvg;
};

int main(){

    struct lb lunch1,lunch2;
    int total = 0,tot[5];
    printf("Main Dish: ");
    scanf("%d",&lunch1.md);
    tot[0] = lunch1.md;

    for(int i=0;i<3;i++){
        printf("Side dish %d: ",i+1);
        scanf("%d",&lunch1.sd[i]);
        tot[i+1] = lunch1.sd[i];
    }

    printf("Beverage: ");
    scanf("%d",&lunch1.bvg);


    lunch2 = lunch1;
    
    total += lunch2.md + lunch2.bvg;
    for(int i=0;i<3;i++) total += lunch2.sd[i];

    printf("Total: %d",total);


}