#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

typedef struct taxi_info TAXI;

struct taxi_info{ 
    char start[11]; // 출발지 : 공백이 없는 영문자 최대 10개
    char target[11]; // 목적지 : 공백이 없는 영문자 최대 10개
    double distance; // 이동거리 : 출발지에서 목적지까지 거리, 단위는 (km) 
    int t_time; // 정체시간 : 출발지에서 목적지까지 이동 중 정체시간, 단위는 (초)
    char late_night; // 심야운행여부 : 'Y' 또는 'N'으로 표시
    int tot; // 최종 taxi 요금
};

TAXI *sel_max(TAXI *p, int N, char *s, char *d){
    // 택시요금 정보가 저장된 구조체 배열의 시작 주소, 
    //구조체 배열 원소의 개수, 
    // 출발지와 도착지를 저장한 두 개 문자 배열의 시작 주소를 인자

    TAXI *rstst;
    int max = -1,cnt=0;
    while(cnt < N){
        if(strcmp(p->start,s)==0){
            // printf("check");
            if(p->tot >max){
                max = p->tot;
                rstst = p;
            }
        }
        p++;
        cnt++;
    }
    

    return rstst;
}

int main(){
    TAXI system[20];
    int N;scanf("%d",&N); getchar();
    ////택시요금 계산 후, 출발지와 목적지 정보를 입력받아
    char startarr[11],endarr[11];

    for(int i=0;i<N;i++){
        system[i].tot = 0;
        scanf("%s %s %lf %d %c",system[i].start, system[i].target, &system[i].distance , &system[i].t_time,&system[i].late_night);
        if(system[i].late_night == 'N'){//낮
            if(system[i].distance < 2 ){//2km보다 가까운 곳
                system[i].tot += 3800;
                // 정체시간에 대한 요금 = 정체시간 / 30 * 정체시간 30초당 요금
                system[i].tot += (int)system[i].t_time/30 * 100;
            }
            else{//추가 이동거리에 대한 요금
                system[i].tot += 3800;
                // printf(">%d\n",system[i].tot);
                // 2km 이후부터 100m 당
                system[i].tot += (int)((system[i].distance - 2)*1000/100)*100;
                // printf(">%d\n",system[i].tot);
                system[i].tot += (int)system[i].t_time/30 * 100;
                
                // printf(">%d\n",system[i].tot);
                // * (100*((system[i].distance - 2)/100));
                //추가 이동거리에 대한 요금 
                //= (이동거리 – 기본거리(2km)) * 1000/100 * 추가 이동거리 100m당 요금
            }
        }
        else if(system[i].late_night == 'Y'){//밤
            /////////////////////////
            if(system[i].distance < 2 ){//2km보다 가까운 곳
                system[i].tot += 4800;
                // 정체시간에 대한 요금 = 정체시간 / 30 * 정체시간 30초당 요금
                system[i].tot += (int)system[i].t_time/30 * 120;
                // printf(">%d\n",system[i].tot);
            }
            else{//추가 이동거리에 대한 요금
                system[i].tot += 4800;
                // printf(">%d\n",system[i].tot);
                // 2km 이후부터 100m 당
                system[i].tot += (int)((system[i].distance - 2)*1000/100)*120;
                // printf(">%d\n",system[i].tot);
                system[i].tot += (int)system[i].t_time/30 * 120;
                // printf(">%d\n",system[i].tot);
                // * (100*((system[i].distance - 2)/100));
                //추가 이동거리에 대한 요금 
                //= (이동거리 – 기본거리(2km)) * 1000/100 * 추가 이동거리 100m당 요금
            }
        }
        

        // printf("%s %s %d\n",system[i].start,system[i].target,system[i].tot);
        //추가 이동거리에 대한 요금 = (이동거리 – 기본거리(2km)) * 1000/100 * 추가 이동거리 100m당 요금
        // 정체시간에 대한 요금 = 정체시간 / 30 * 정체시간 30초당 요금
    }

    // for(int i=0;i<N;i++) printf(">%s -> %s : %d\n",system[i].start,system[i].target,system[i].tot);
    //택시요금 계산 후, 출발지와 목적지 정보를 입력받아
    scanf("%s %s",startarr,endarr);
    TAXI *result;
    // //해당 출발지에서 목적지로의 이동에 소요된 택시요금 중 
    result = sel_max(&system[0],N,startarr,endarr);
        // 택시요금 정보가 저장된 구조체 배열의 시작 주소, 
        //구조체 배열 원소의 개수, 
        // 출발지와 도착지를 저장한 두 개 문자 배열의 시작 주소를 인자
    
    
    // //가장 큰 경우를 찾아 이동거리, 정체시간, 심야할증여부(Y 또는 N)와 택시요금을 출력
    printf("%.2lf %d %c %d",result->distance,result->t_time,result->late_night,result->tot);


}
/*
8
aaa bbb 2.25 480 N
ccc ddd 10 300 Y
eee fff 10 180 Y
aaa bbb 3 180 N
ccc ddd 12 180 Y
ggg hhh 13 60 Y
aaa bbb 4 0 N
aaa bbb 3.2 60 N
aaa bbb
*/