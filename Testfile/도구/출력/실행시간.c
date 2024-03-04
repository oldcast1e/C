// #include <stdio.h>
// // #include <Windows.h>
// int main(void){
//     LARGE_INTEGER ticksPerSec; 
//     LARGE_INTEGER start, end, diff;
//     QueryPerformanceFrequency(&ticksPerSec); 
//     QueryPerformanceCounter(&start);
//     // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입 QueryPerformanceCounter(&end);
//     // 측정값으로부터 실행시간 계산
//     diff.QuadPart = end.QuadPart – start.QuadPart;
//     printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)); 
//     return 0;
// }