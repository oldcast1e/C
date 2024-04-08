#include<stdio.h>

#define Max_ele 100
#define Sentinel 0 // 종료 입력값
#define True 1
#define False 0

int main(){
    
    int arr[Max_ele],ipt,cnt = 0;
    printf("임의의 정수값을 입력하세요.\n");
    printf("0을 입력하면 입력을 종료합니다.\n");
    while(1){

        printf("=> ");scanf("%d",&ipt); if(ipt == Sentinel) break;
        arr[cnt] = ipt; cnt++;
    }
    int *new_arr;
    new_arr = (int*)malloc(cnt*sizeof(int));
    for(int j=0;j<cnt;j++) new_arr[j] = arr[cnt - j];//9-0-1
    
}
    for (int i = 0; i < cnt; i++) printf("%d\n", new_arr[i]);

}