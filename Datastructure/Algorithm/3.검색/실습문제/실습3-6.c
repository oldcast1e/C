#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct system{
    char name[10];
    int age;
    int number;
} person[6];

int int_cmp(struct system *a,struct system *b){
    return strcmp(a->name,b->name);
}

int main() {
    int num=6,cnt = 0;
    srand(time(NULL));
    struct system person[6]={
        {"김영준",0,0},
        {"박현규",0,0},
        {"이수진",0,0},
        {"최윤미",0,0},
        {"함진아",0,0},
        {"홍연의",0,0},
    };

    while(cnt < 6){
        person[cnt].age = rand()%20+10;
        person[cnt].number = rand()%900000+21000000;
        cnt ++;
    }


    puts("이름으로 검색합니다.");
    do{
        struct system tmp;
        printf("이름: ");scanf("%s",tmp.name);
        struct system *rst = bsearch(&tmp,
                        person,
                        num,
                        sizeof(struct system),
                        (int(*)(const void *,const void *))int_cmp
                    );
        if(rst == NULL) puts("검색에 실패하였습니다.");
        else{
            printf("검색 성공!\n");
            for(int i=0;i<10;i++)printf("-"); printf("\n");
            printf("이름: %s\n나이: %d\n번호: %d",rst->name,rst->age,rst->number);
            break;

        }
        // else printf("%d는 x[%d]에 있습니다.\n",key,(int)(rst-arr));
    }while(0);
    

}	
