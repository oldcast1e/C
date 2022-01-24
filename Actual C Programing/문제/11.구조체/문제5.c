#include  <stdio.h>
struct system{
    /* data */
    char name[8],scr;
    double s1,s2,s3,avg;
};

int SC(int avg){
    char rst;
    if(avg>=90) rst = 'A';
    else if(avg>=80) rst = 'B';
    else if(avg>=70) rst = 'C';
    else rst = 'D';

    return rst;
}
int main(){
    int N;
    double sum=0,avg;
    char score;
    struct system sys[20];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%s %lf %lf %lf",sys[i].name,&sys[i].s1,&sys[i].s2,&sys[i].s3);
        sum = 0;
        sum += sys[i].s1 + sys[i].s2 + sys[i].s3;
        sys[i].avg = sum/3;
        sys[i].scr= SC(sys[i].avg);
    }

    for(int i=0;i<N;i++){
        printf("%s %.1lf %c\n",sys[i].name, sys[i].avg, sys[i].scr);
    }


}