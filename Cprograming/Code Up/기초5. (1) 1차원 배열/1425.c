#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=0;
    int num[100];
    scanf("%d %d",&a,&b);//a=학생 수 / b= 한줄에 앉을 수 있는 학생 수
    for(int i=0;i<a;i++)scanf("%d",&num[i]);

    for(int i=0;i<a;i++)
        for(int j=i;j<a;j++)
            if(num[i]>num[j]){cnt = num[i];num[i] = num[j];num[j]=cnt;}
        
    for(int i=0;i<a;i++){printf("%d ",num[i]); if((i+1)%b==0)printf("\n");} 
    // for(int i=0;i<a;i++)printf("%d ",num[i]); 
}
/*
키가 작은 순서대로 앞에서부터 앉히는 것이 제일 좋은 방법이라고 결정하게 되었다.

예를 들어, 160, 165, 164, 165, 150, 165, 168, 145, 170의 학생들 키가 주어지고 
한 줄에 6명씩 앉는다면 다음과 같이 앉으면 될 것이다.

*/