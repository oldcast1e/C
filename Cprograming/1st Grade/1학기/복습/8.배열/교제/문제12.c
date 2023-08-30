#include  <stdio.h>
int main(){
    
    char num[6][5]={{"ZERO-"},{"ONE--"},{"TWO--"}
                        ,{"THREE"},{"FOUR-"},{"FIVE-"}};

    int inp[3],k,spn=0;                    
    for(int i=0;i<3;i++){
        scanf("%d",&inp[i]);
    }

    for(int i=0;i<3;i++){
        if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
            printf("\n");
        spn++;//줄 띄움 변수 증가
        
        for(int j=0;j<5;j++){
            printf("%c",num[inp[i]][j]);
        }
    }

}


