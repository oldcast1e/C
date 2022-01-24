#include  <stdio.h>
struct time{
    /* data */
    int hour,min,sec;
}t1,t2;

int main(){
    int minus = 0;
    int rsthour,rstmin,rstsec;
    scanf("%d %d %d",&t1.hour,&t1.min,&t1.sec);
    scanf("%d %d %d",&t2.hour,&t2.min,&t2.sec);
    minus = (t2.hour*3600 +  t2.min*60 + t2.sec)- (t1.hour*3600 +  t1.min*60 + t1.sec);

    rsthour = minus/3600%24;
    rstmin = minus/60%60;
    rstsec = minus%60;
    printf("%d %d %d",rsthour,rstmin,rstsec);

}