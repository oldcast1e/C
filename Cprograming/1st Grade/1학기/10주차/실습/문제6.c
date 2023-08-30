#include  <stdio.h>

int main(){
    
    int X[10],cnt;

    for(int i=0;i<10;i++){//10번 반복하여
        scanf("%d",&X[i]);//x의 요소를 입력받음 
    }

    for(int i=0;i<10;i++){//10번 반복하여
        cnt=0;//자신보다 큰 수의 개수를 0으로 초기화
        for(int j=0;j<10;j++){//10번 반복하여
            if(i!=j)//중복 제외
                if(X[i]<X[j])//자신보다 큰 숫자인 경우
                    cnt++;// 큰수의 개수를 1증가
            
        }
        printf(" %d",cnt);//자신보다 큰 숫자의 개수를 출력
        
    }
    

    return 0;
}
