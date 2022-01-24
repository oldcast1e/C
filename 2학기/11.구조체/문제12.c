#include  <stdio.h>
struct quiz{
    char name[9];
    double s1,s2,s3;
    double avg;
}q1,q2,q3,q4,q5,q6,q7,q8,q9,q10;

void read_data(struct quiz student){
    scanf("%s %lf %lf %lf",student.name,&student.s1,&student.s2,&student.s3);
    cal_avg(student);

}

void cal_avg( struct quiz student){
    double ravg = 0;
    ravg = (student.s1+student.s2+student.s3);
    student.avg = ravg;
}

void sort( ){

}

void print_score( ) {

}
int main(){
    struct quiz student;
    read_data(q1);read_data(q2);read_data(q3);read_data(q4);read_data(q5);
    read_data(q6);read_data(q7);read_data(q8);read_data(q9);read_data(q10);


    


}