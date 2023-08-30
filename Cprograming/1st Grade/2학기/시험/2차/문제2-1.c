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

int main(){
    TAXI system[20];
    int N;scanf("%d",&N); getchar();

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

        printf("%s %s %d\n",system[i].start,system[i].target,system[i].tot);
        //추가 이동거리에 대한 요금 = (이동거리 – 기본거리(2km)) * 1000/100 * 추가 이동거리 100m당 요금
        // 정체시간에 대한 요금 = 정체시간 / 30 * 정체시간 30초당 요금
    }


}
/*
4
aaa bbb 2 180 N
ccc ddd 2.25 135 Y
eee fff 5 0 Y
ggg hhh 7.5 60 N
*/