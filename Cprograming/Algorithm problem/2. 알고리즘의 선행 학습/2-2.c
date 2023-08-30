#include<stdio.h>

int main(){
    
    int num[100];
    printf("5개의 점수를 입력하세요.\n");
    for(int i=0;i<5;i++){
        printf("%d차 점수: ",i+1);
        scanf("%d",&num[i]);
    }

    float sum = 0; for(int i=0;i<5;i++)sum += num[i];
    printf("평균은 다음과 같습니다: %f",sum/5);

}