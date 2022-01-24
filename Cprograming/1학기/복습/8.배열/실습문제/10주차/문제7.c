#include  <stdio.h>
int main(){
    
    int N[10];
    int cnt,key,spn=0;
    for(int i=0;i<10;i++){
        scanf("%d",&N[i]);
    }

    printf(" %d",N[0]);
    for(int i=1;i<10;i++){
        key = 1;
        for(int j=0;j<i;j++){
           if(N[i]==N[j])
            key = 0;
        }
        
        if(key ==1){
            // if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            //     printf("\n");
            // spn++;//줄 띄움 변수 증가
            printf(" %d",N[i]);
        }
            
    }

}


