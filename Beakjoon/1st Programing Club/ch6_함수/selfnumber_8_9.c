#include  <stdio.h>
int arr[10000] = {0};
int selfnumber(int num){int selfnum = num;
    while(num>0){selfnum += num%10; num /= 10;}
    return selfnum;
}
int main(){
    for(int i=0;i<10000;i++){arr[i] = i+1;}
    int cnt = 0;
    while(10000>cnt){
        int sn = selfnumber(cnt);
        for(int i=0;i<10000;i++){
            if(arr[i]==sn) arr[i] = -1;}
        cnt ++;}
    for(int i=0;i<10000;i++){
        if(arr[i]!=-1) printf("%d\n",arr[i]);
    }
}

//자신의 수와 자신의 각 자리수를 더한 값
//예) 33 -> 33 + 3+ 3 = 39 _____ 이때 33은 39의 생성자
//예) 39 -> 39 + 3 +9 = 51 _____ 이때 39는 51의 생성자

//생성자는 1개 이상인 경우 존재
// 생성자가 없는 숫자를 셀프 넘버라고 함 = 셀프넘버로 만들 수 없는 숫자
// 10000보다 작거나 같은 셀프 넘버를 한줄에 하나씩 출력하는 코드를 만들어라




// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

