#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int arr[8][8] = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    int raw = 7, cal = 0;//raw: 행, cal: 열
    int count = 0;
    while(1){
        if(cal >= 8) break;

        if(arr[raw][cal] == 1){
            printf("[%d][%d] => 1\n",raw,cal);
            count += 1; cal++;
        }
        else if(arr[raw][cal] == 0){
            printf("[%d][%d] %d\n",raw,cal,count);
            //0을 만날때 행을 위로 올림
            //행을 올리면 "올리기전의 열을 더해야함."
            count += cal;
            // cal -=1;
            raw -= 1;
        }
    }
    printf("count = %d",count);

}