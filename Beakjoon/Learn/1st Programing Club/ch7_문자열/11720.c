#include  <stdio.h>
int main(){
    
    int sum = 0,n;
    scanf("%d",&n);
    getchar();
    char arr[100];
    for(int i=0;i<n;i++){
        scanf("%c",&arr[i]);
        sum += ((int)arr[i]-48);
    }
    printf("%d",sum);

}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

