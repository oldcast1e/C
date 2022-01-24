#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct student{
    /* data */
    char name[8];
    int ls,es,ms;
    float avg;
};


int main(){
    int N;
    scanf("%d",&N);
    struct student *val = malloc(sizeof(struct student));
    for(int i=0;i<N;i++){
        scanf("%s",val->name);
        scanf("%d %d %d",&val->ls,&val->es,&val->ms);

        val -> avg = ((float)val->ls + (float)val->es + (float)val->ms)/3;
        printf("%s %.1f",val->name,val->avg);
        if(val->ls >= 90|| val->es >= 90|| val->ms >= 90) printf(" GREAT");
        if(val->ls < 70|| val->es < 70|| val->ms < 70) printf(" BAD\n");
    }

}