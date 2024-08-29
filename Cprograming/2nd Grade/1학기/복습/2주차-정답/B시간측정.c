#include <stdio.h>
#include <Windows.h>
/*
라이브러리 함수 가운데 일반적인 시간측정 함수인 clock()을 사용하면 시간이 정밀하게 나오지 않는 문제가 발생한다. 대안으로 QueryPerformanceCounter() 함수를 사용하면 정밀한 시간을 출력할 수 있다. 구체적인 사용 방법은 다음과 같다.
- 헤더파일로 windows.h를 추가한 후,
- LARGE_INTEGER 변수 선언하고,
- QueryPerformanceFrequency() 함수를 통해 타이머의 주파수를 변수에 저장한 후,
- 시간을 측정하고 싶은 작업의 전후에 QueryPerformanceCounter()를 호출하고 그 반환값들을 이용하여 계산, 출력하면 된다.


*/
int main(void){
    LARGE_INTEGER ticksPerSec; 
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec); 
    QueryPerformanceCounter(&start);
    // 시간을 측정하고 싶은 작업(예: 함수 호출)을 이곳에 삽입 
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("time: %.12f sec\n\n", ((double)diff.QuadPart/(double)ticksPerSec.QuadPart)); return 0;
}
/*
◦ 작동 원리: 메인보드에 고해상도의 타이머가 존재하는데 
    이를 이용하여 특정 실행 시점들의 CPU 클럭수들을 얻어온 후 
    그 차이를 이용하여 작업 시간을 구한다. 
    clock() 함수와 달리 1us 이하의 시간까지 측정한다.
QueryPerformanceFrequency() : 타이머의 주파수(초당 진동수)를 얻는 함수
QueryPerformanceCounter() : 타이머의 CPU 클럭수를 얻는 함수

작업 전후의 클럭수 차를 주파수로 나누면 
    작업 시간(초, sec)을 구할 수 있고, 
    ms단위로 출력하기 위해선 결과 값에 1,000을 곱해주면 된다.

◦ clock() 함수와 비교: clock()은 초당 1,000번의 측정을 통해 
    1ms의 시간을 측정할 수 있는 데 비해, 
    QueryPerformanceCounter()는 초당 10,000,000번의 측정으로 0.1us의 시간까지
    측정할 수 있다. 초당 클럭수는 time.h를 헤더로 추가한 후 
    CLOCKS_PER_SEC을 출력하여 알 수 있고, 
    타이머의 주파수는 QueryPerformanceFrequency()를 통해 알 수 있다.


*/