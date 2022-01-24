#include  <stdio.h>
#include  <string.h>
// #include  <stdlib.h>
struct hotel_info{//hotel_info구조체 정의
    /* data */
    char name[30];//이름
    int rank;//등급
    double reputaion,distance;//거리와 평판
    char morning_meal;//제공여부
};

int in_hotel_info(struct hotel_info *p){//in_hotel_infㅐ수
    //◦ 인자: 호텔 정보를 저장할 구조체 배열에 대한 포인터 p
    int cnt = 0;
    char tmp;
    while(1){//무한 반복
        
        scanf("%s%c",(p+cnt)->name,&tmp);
        if(tmp=='\n'){//0이 입렫됬는지 구문
            // break;
            if(strcmp((p+cnt)->name,"0")==0){//0입력시
                // printf("Break!\n");
                break;//종료
            } 
        }
        else{//아니면
            scanf("%d %lf %lf %c",&(p+cnt)->rank, &(p+cnt)->reputaion, &(p+cnt)->distance, &(p+cnt)->morning_meal);
            getchar();//나머지 ㄱ밧을 다 입력받음
            cnt++;//매개 변수 증가
        }
        
        
    }
    return cnt;//반환
    //◦ 반환 값 : 정보가 입력된 호텔의 수
}
/*
◦ 호텔의 이름, 등급, 평판도, 거리, 조식포함여부를 사용자로부터 입력 받아 배열에 저장한다. 
◦ 호텔 이름으로 “0”이 입력되면, 입력을 종료한다.
◦ 반환 값 : 정보가 입력된 호텔의 수
*/

void out_hotel_info(struct hotel_info *p, int N, int G, double D){//out_hotel_info함수 선언

    int wantedrank=G;double wanteddis=D;
    //원하는 등급 및 거리
    int cnt = N;//반복 수
    int rst = 0;//결과 매개변수
    double maxrep = 0;//최대평판

    for(int i=0;i<cnt;i++){//반복
        // printf("check1!\n");
        if(((p+i)->rank >= wantedrank) && ( wanteddis >= (p+i)->distance) ){
            //해당 조건을 만족시
            if(((p+i)->reputaion) > maxrep){//최대평판 구하기
                // printf("check2!\n");
                maxrep = (p+i)->reputaion;
                rst = i; // 결과위치
                // printf("i = %d\n",i);
            }
        }
    }
    printf("%s %d %.1lf %.1lf %c",(p+rst)->name, (p+rst)->rank,(p+rst)->reputaion, (p+rst)->distance, (p+rst)->morning_meal);//결과 출력
}

int main(){
    struct hotel_info ht[100],*phi = ht;
    //크기 100의 구조체 선언
    int cnt = 0,rst;//매개변수 두개 서언
    int wantedrank;double wanteddis;
    //원하는 등급 및 거리
    cnt = in_hotel_info(phi);//반환값 저장

    for(int i=0;i<cnt;i++){//cnt만큼 반복
        for(int j=i;j<cnt;j++){//i부터 cnt까지
            if(i!=j){
                if(strcmp(ht[i].name,ht[j].name)>0){//배열 비교
                    struct hotel_info tmp;//임의의 구조체 선언
                    tmp = ht[i];
                    ht[i] = ht[j];
                    ht[j] = tmp;//스왑
                }
            }
        }
    }
    // printf("cnt = %d\n",cnt);
    scanf("%d %lf",&wantedrank,&wanteddis);//거리 및 등급 입력받고
    out_hotel_info(ht,cnt,wantedrank,wanteddis);//함수 실행

}
/*
marriott 4 4.7 12.5 Y 
ibis 2 3.5 5.6 N 
novotel 3 3.0 2.7 N 
renaissance 3 3.5 4.8 N 
hyatt 5 3.5 7.4 Y 
bestwestern 2 2.5 3.8 Y
0
3 7.5
*/