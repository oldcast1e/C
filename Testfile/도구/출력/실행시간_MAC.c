#include <time.h>
#include <stdio.h>

int main(void)
{
    int  i;
    double start, end;

    //for 루프 시작 시간
    start = (double)clock() / CLOCKS_PER_SEC;    



    //for 루프 끝난 시간
    end = (((double)clock()) / CLOCKS_PER_SEC);
    printf("프로그램 수행 시간 :%lf\n", (end-start));
}
