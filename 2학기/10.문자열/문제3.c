#include  <stdio.h>
int main(){

    char arr[101],*parr= arr,tmp;//크기 101의 배열 선언, 포인터 연결
    int len=0;//문자열의 길이
    scanf("%s",arr);//문자열을 입력받음
    for(int i=0;i<101;i++){//20번 반복
        if(*(parr+i)== '\0') break;//널 문자가 입력되면 = 문자열 입력이 종료되면
        len ++;//문자 개수 변수 증가
    }
    // printf("%d",len);
    printf("%s\n",arr);
    for(int i=0;i<len-1;i++){//문자열의 길이- 1번 반복 = 하나씩 미룰까기 때문
        tmp = *(parr);//임의의값 저장
        for(int j=0;j<len-1;j++){//문자열의 길이- 1번 반복
            *(parr+j) = *(parr+j+1);//뒷 요소를 앞에 저장
        }   
            *(parr+len-1) = tmp;//새로운 첫번째 요소 초기화
        printf("%s\n",arr);//결과 출력
       
    }
    //처음부터 5까지
    //두번째부터 5까지 + 첫번째부터 첫번째 까지
    //세번째 부터 5까지 + 첫번째에서 두번째까지


}