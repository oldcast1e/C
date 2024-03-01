#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include  <math.h>

#define PI 3.141592
double swap_rad_to_angle(double x){
    x = (x*180/PI);
    return x;
}
double swap_angle_to_rad(double x){
    double rst = (x*PI/180);
    return rst;
}

int main(){
    double rad = swap_angle_to_rad(90);
    printf("%lf",rad);
}
