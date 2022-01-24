#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct _bank {
    int id; // 아이디, T1, T2, T3 대신, 1, 2, 3, ... 으로 한다. 
    int arrival_time; // 도착시간
    int service_time; // 서비스시간
    int waiting_time; // 대기시간
};
void waitingtime(struct _bank guest[], int N){
    //인자(guest): 도착시간과 서비스시간이 저장되어 있는 구조체 배열의 이름
    //N은 대기자 수
    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            guest[i].waiting_time += guest[j].service_time;
        }
        guest[i].waiting_time -= guest[i].arrival_time;
    }
    
}

double avgtime(struct _bank guest[], int N){
    double avg = 0;
    for(int i=0;i<N;i++) avg += guest[i].waiting_time;
    return avg/N;
}
int main(){
    int N;scanf("%d",&N);
    struct _bank system[100];

    for(int i=0;i<N;i++){
        system[i].waiting_time = 0;
        scanf("%d %d %d",&system[i].id,&system[i].arrival_time,&system[i].service_time);
    }
    waitingtime(system,N);
    printf("%.2lf",avgtime(system,N));


}
/*
4
1 0 7
2 2 4
3 4 1
4 5 4
*/