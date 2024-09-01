#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
//동적할당
int main(){
    int *arr,num;
    printf("원하는 자료의 개수를 입력하세요: "); scanf("%d",&num);
    arr = calloc(num,sizeof(int));
    if(arr == NULL) {printf("메모리 할당에 실패하였습니다."); return 0;}
    else{
        printf("> 입력한 자료의 개수에 자동으로 숫자가 대입되었습니다.\n");
        for(int i=0;i<num;i++) {
            arr[i] = i+1;
            printf("%d ",arr[i]);
        }
    }
}
