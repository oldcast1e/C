#include  <stdio.h>
struct student
{
    /* data */
    char name[9];
    double score;

}st1,st2,st3,st4,st5;

int main(){
    double total = 0,avg;
    scanf("%s %lf",st1.name,&st1.score); total +=st1.score;
    scanf("%s %lf",st2.name,&st2.score); total +=st2.score;
    scanf("%s %lf",st3.name,&st3.score); total +=st3.score;
    scanf("%s %lf",st4.name,&st4.score); total +=st4.score;
    scanf("%s %lf",st5.name,&st5.score); total +=st5.score;
    // printf("total = %lf\n",total);
    avg = total/5;
    // printf("avg = %lf\n",total/5);
    if(avg>=st1.score)printf("%s\n",st1.name);
    if(avg>=st2.score)printf("%s\n",st2.name);
    if(avg>=st3.score)printf("%s\n",st3.name);
    if(avg>=st4.score)printf("%s\n",st4.name);
    if(avg>=st5.score)printf("%s",st5.name);


}