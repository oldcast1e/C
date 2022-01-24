#include  <stdio.h>
int main(){
    
    char ans[3],inp,rst[3]={'_','_','_'};
    int cnt = 0,spn=0;
    for(int i=0;i<3;i++){
        scanf("%c",&ans[i]);
    }
    getchar();
    while(5>cnt){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        scanf("%c",&inp);
        for(int i=0;i<3;i++){
            if(ans[i]==inp){
                rst[i] = inp; 
            }
        }
        for(int i=0;i<3;i++){
            printf("%c ",rst[i]);
        }
        if(rst[0]==ans[0] && rst[1]==ans[1] && rst[2]==ans[2])
            break;
        getchar();
        cnt++;
    }

}


