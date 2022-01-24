#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct hotel_info{
    /* data */
    char name[31];
    int rank;//등급
    double reputaion;//평판도
    double distance;//거리
    char diner;
    //호텔의 이름, 등급, 평판도,  거리,  조식포함여부 순으로 입력
    //marriott   4    4.7   12.5      Y
};

//호텔은 최대 100개까지 사용자로부터 입력 받는다.
int in_hotel_info(struct hotel_info *p){
    //호텔 정보를 저장할 구조체 배열에 대한 포인터 p
    // struct hotel_info *tmp  = p;
    int cnt = 0;
    char space;
    while(1){
        scanf("%s%c",(p+cnt)->name,&space);
        if(space == '\n'){
            if(strcmp((p+cnt)->name,"0")==0){//0입력시
            // printf("Break!\n");
            break;//종료
       
        } 
        else{
            scanf("%d %lf %lf %c",&(p+cnt)->rank,&(p+cnt)->reputaion,&(p+cnt)->distance,&(p+cnt)->diner);
            getchar();
            cnt++;
        }
        
    }
    
    //호텔의 이름, 등급, 평판도, 거리, 조식포함여부를 사용자로부터 입력 받아 배열에 저장
    //호텔 이름으로 “0”이 입력되면, 입력을 종료한다.
    return cnt;//반환 값 : 정보가 입력된 호텔의 수
}

void out_hotel_info(struct hotel_info *p, int N, int G, double D){
    //호텔 정보가 저장된 구조체 배열에 대한 포인터 p, 
    //배열의 크기 N, 원하는 호텔 등급 G, 원하는 호텔의 거리 D
    struct hotel_info result;
    double maxrep = -1;
    for(int i=0;i<N;i++){
        if((p+i)->rank > G){
            if((p+i)->distance < D){
                if((p+i)->reputaion > maxrep){
                    maxrep = (p+i)->reputaion ;
                    result = *(p+i);
                }
                else if((p+i)->reputaion == maxrep){
                    if(strcmp((p+i)->name,result.name)<0){
                        maxrep = (p+i)->reputaion ;
                        result = *(p+i);
                    }
                }
                
            }
        }
    }
    printf("%s %d %.1lf %.1lf %c\n",result.name,result.rank,result.reputaion,result.distance,result.diner);
    //배열에 저장된 호텔 중 G 이상의 등급과 D 이하의 거리를 갖는 호텔을 검색
    //>>>평판도가 가장 높은 호텔의 정보를 화면에 출력

    //. 만약, 해당 조건을 만족하고 평판 도가 가장 높은 호텔이 두 개 이상 있는 경우에는 호텔 이름이 사전 순서 상 가장 빠른 호텔의 정보를 출력
}

int main(){
    int G;
    double D;
    struct hotel_info sys[100];
    int cnt = in_hotel_info(sys);
    scanf("%d %lf",&G,&D);
    out_hotel_info(sys,cnt,G,D);


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

novotel 5 3.5 7.4 N
renaissance 5 3.5 7.4 N
hyatt 5 3.5 7.4 Y
bestwestern 5 3.5 7.4 Y
0
3 7.5
*/