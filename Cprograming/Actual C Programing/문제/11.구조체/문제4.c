#include  <stdio.h>
struct system{
    /* data */
    char name[19],scr;
    double s1,s2,s3;
};

int SC(int avg){
    char rst;
    if(avg>=90) rst = 'A';
    else if(avg>=80) rst = 'B';
    else if(avg>=70) rst = 'C';
    else rst = 'F';

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
        sum += sys[i].s1 + sys[i].s2 + sys[i].s3;

        avg = sum/3;

        printf("%s %.1lf %c",sys[i].name,avg,SC(avg));
    }
    // avg = sum/N;
    // for(int i=0;i<N;i++){
    //     if(avg>=sys[i].scr)
    // }


}