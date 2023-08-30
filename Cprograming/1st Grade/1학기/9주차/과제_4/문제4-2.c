#include  <stdio.h>
int main(){
    
    int num[20],n,cnt=0;//크기가 20인 배열 선언, 입력받을 정수 n선언
    int max[20],min[20];
    int rep;
    scanf("%d",&n); //n을 입력받음
    for(int i=0;i<n;i++){//n번 반복하여
        scanf("%d",&num[i]);//배열값을 입력받음
    }
    for(int i=0;i<20;i++){
        min[i] = 21;
    }

    for(int i=n-1;i>=0;i--){//n-1번째 부터 0번째 배열 요소를 
        printf(" %d",num[i]);//출력
    }
    printf("\n");

    for(int i=0;i<20;i+=3){
        if(num[i]>num[i+1] && num[i]>num[i+2] )
            max[cnt] = num[i];
        else if(num[i+1]>num[i] && num[i+1]>num[i+2] )
            max[cnt] = num[i+1];
        else if(num[i+2]>num[i] && num[i+2]>num[i+1] )
            max[cnt] = num[i+2];
        cnt++;
            
    }
    cnt =0;
    
    if(n%3==0){//ㄱ
        for(int i=0;i<20;i+=3){
        if(num[i]<num[i+1] && num[i]<num[i+2] )
            min[cnt] = num[i];
        else if(num[i+1]<num[i] && num[i+1]<num[i+2] )
            min[cnt] = num[i+1];
        else if(num[i+2]<num[i] && num[i+2]<num[i+1] )
            min[cnt] = num[i+2];
        cnt++;
            
        }
    }
    else if(n%3==1){

        for(int i=0;i<n-1;i+=3){
        if(num[i]<num[i+1] && num[i]<num[i+2] )
            min[cnt] = num[i];
        else if(num[i+1]<num[i] && num[i+1]<num[i+2] )
            min[cnt] = num[i+1];
        else if(num[i+2]<num[i] && num[i+2]<num[i+1] )
            min[cnt] = num[i+2];
        cnt++;
            
    }
    min[cnt] = num[n-1];
    }

    else if(n%3==2){

        for(int i=0;i<n-2;i+=3){
        if(num[i]<num[i+1] && num[i]<num[i+2] )
            min[cnt] = num[i];
        else if(num[i+1]<num[i] && num[i+1]<num[i+2] )
            min[cnt] = num[i+1];
        else if(num[i+2]<num[i] && num[i+2]<num[i+1] )
            min[cnt] = num[i+2];
        cnt++;
            
    }
    min[cnt] = (num[n-1]>num[n-2]?num[n-2]:num[n-1]);
    }



    if(n%3==0)
        rep = n/3;
    else
        rep = n/3+1;

    for(int k=0;k<rep;k++){
        printf(" %d",max[k]);
    }
    printf("\n");
    for(int k=0;k<rep;k++){
        printf(" %d",min[k]);
    }
}
