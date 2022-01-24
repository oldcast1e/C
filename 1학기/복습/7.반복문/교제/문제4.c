#include  <stdio.h>
int main(){
    
    int ans,inp;
    scanf("%d",&ans);
    while(1){
        scanf("%d",&inp);
        if(inp<ans)
            printf("UP\n");
        else if(inp>ans)
            printf("DOWN\n");
        else{
            printf("RIGHT");
            break;
        }
    }

}
