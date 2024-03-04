#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int int_cmp(const int *a, const int *b){
    if(*a<*b) return -1;
    else if(*a > *b) return 1;
    else return 0;
}

int main() {
    int num,key;
    puts("bseach 함수를 사용하여 검색 ");
    printf("요소 개수: ");scanf("%d",&num);

    int *arr = (int*)malloc(sizeof(int)*num);

    printf("오름차순으로 입력하세요.\n");
    for(int i=0;i<num;i++){printf("x[%d]: ",i);scanf("%d",&arr[i]);}

    printf("검색값을 입력하세요: ");scanf("%d",&key);

    int *rst = bsearch(&key,
                        arr,
                        num,
                        sizeof(int),
                        (int(*)(const void *,const void *))int_cmp
                    );

    if(rst == NULL) puts("검색에 실패하였습니다.");
    else printf("%d는 x[%d]에 있습니다.\n",key,(int)(rst-arr));
}