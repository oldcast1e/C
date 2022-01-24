#include  <stdio.h>
int main(){
    
    char inp[7];
    int cnt = 0;
    for(int i=0;i<7;i++){
        scanf("%c",&inp[i]);
    }

    for(int i=0;i<7;i++){
        if(inp[i]=='c')
            if(inp[i+1]=='a')
                if(inp[i+2]=='t') 
                    cnt++;
                    
    }
    printf("%d",cnt);
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
