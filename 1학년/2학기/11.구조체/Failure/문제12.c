#include  <stdio.h>
#include  <string.h>
struct quizscore{

    char name[10];
    double s1,s2,s3;
    double avg;
}student[11];

void read_data( struct quizscore *data){

    for(int i=0;i<10;i++){
        scanf("%s %lf %lf %lf",(data+i)->name,&(data+i)->s1,&(data+i)->s2,&(data+i)->s3);
    }
    // printf("-");
}
/*- read_data( ) 함수
◦ 인자: 구조체 배열
◦ 10명 학생의 이름과 학생당 3회 퀴즈 점수를 입력 받아, 구조체 배열에 저장합니다. ◦ 학생의 이름은 공백 없이 최대 9개 영어 문자이다.
◦ 반환값: 없음
*/
void cal_avg(struct quizscore *data ){
    for(int i=0;i<10;i++){
        (data+i)->avg = ((data+i)->s1 + (data+i)->s2 + (data+i)->s3)/3;
    }
    
}
/*
- cal_avg( ) 함수
◦ 인자: 구조체 배열
◦ 각 학생의 퀴즈 점수 평균값을 계산합니다. ◦ 반환값: 없음
*/
void sort( struct quizscore student[10]){
    ///구조체를 전제 복사!!!!!!
    for(int i=0;i<10;i++){
        for(int j=0;j<9;j++){
            if(student[i].avg > student[j].avg){
                struct quizscore tmp;
                tmp = student[i];
                student[i] = student[j];
                student[j] = tmp;
            }
        }
    }
    
}
/*
 - sort( ) 함수
◦ 인자: 구조체 배열
◦ 평균값에 따라 학생들의 이름과 퀴즈점수들을 내림차순으로 정렬하여 저장합니다. ◦ 반환값: 없음
*/
void print_score(struct quizscore *data ){

    double totalavg = 0;
    for(int i=0;i<10;i++){totalavg += (data+i)->avg;}
    totalavg/=10;

    printf("%s %.2lf\n",data->name,data->avg);
    printf("%s %.2lf\n",(data+9)->name,(data+9)->avg);

    printf("%s %.2f\n", (data+7)->name, (data+7)->avg);
    printf("%s %.2f\n", (data+8)->name, (data+8)->avg);
    printf("%s %.2f\n", (data+9)->name, (data+9)->avg);
    // for(int i=0;i<10;i++){
    //     if(totalavg*0.7 >= (data+i)->avg){
    //         printf("%s %.2lf\n",(data+i)->name,(data+i)->avg);
    //     }
    // }
    
}
//- print_score( ) 함수
//◦ 인자: 구조체 배열
// ◦ 최고평균점, 최저평균점, 하위 30%의 평균점을 받은 학생들의 이름과 평균 점수를 출력 합니다. 평균은 소수점 이하 둘째자리까지 출력합니다.
// ◦ 반환값: 없음
// - 평균이 동점인 경우는 없는 것으로 한다.

int main(){

    struct quizscore *stu = &student[10];
    read_data(stu);
    cal_avg(stu);
    sort(stu);
    print_score(stu);

    printf("--------\n");
    for(int i=0;i<10;i++){
        printf("%s %.2lf\n",(stu+i)->name,(stu+i)->avg);
    }



}
//최고 평균 점수
/*
10명 학생의 이름과 3회 퀴즈 점수를 입력으로 받아 퀴즈 평균 점수 가 최고점과 최저점인 학생의 이름과 평균 점수를 출력하고,
 퀴즈 평균 점수가 하위 30%에 속하 는 학생의 이름과 퀴즈 평균 점수를 출력하는 프로그램을 다음 함수들을 사용하여 작성합니다.
*/

/*
AKim 80 80 80 
BKim 90 90 90 
CKim 81 81 81 
ALee 82 82 82 
BLee 83 83 83 
CLee 84 84 84 
APark 85 85 85 
BPark 86 86 86 
CPark 87 87 87 
DPark 88 88 88





*/