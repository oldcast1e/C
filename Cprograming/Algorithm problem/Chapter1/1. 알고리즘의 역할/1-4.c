#include<stdio.h>

int main(){
    //무식한 검색 프로그램
    int num=0,ipt;
    int data[100];

    while(num<100){data[num]= num+ 1; num++;}

    printf("검색할 값을 입력하세요: "); scanf("%d",&ipt);

    for(int i=0;i<100;i++){ if(data[i]==ipt) {printf("찾으시는 값은 data 배열의 %d 번째에 있습니다.",i); break;}    }
    
}