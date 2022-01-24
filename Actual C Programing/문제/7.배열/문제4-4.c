#include  <stdio.h>
int main(){
    
    char ans[3],u,tmp;
    for(int i=0;i<3;i++){
        scanf("%c",&ans[i]);
    }
    scanf("%c",&tmp);

    int cnt = 0,spn=0;
    int a=0,b=0,c=0;

    while(cnt<5){
        if(cnt==5)
            break;

        scanf("%c%c",&u,&tmp);
        
        cnt ++;
        if(u==ans[0])
            a= 1;
        else if(u==ans[1])
            b=1;
        else if(u==ans[2])
            c=1;

        if(a==1 && b==0 && c==0)
            printf("%c _ _\n",ans[0]);
        else if(a==0 && b==1 && c==0)
            printf("_ %c _\n",ans[1]);
        else if(a==0 && b==0 && c==1)
            printf("_ _ %c\n",ans[2]);//3C1



        else if(a==1 && b==1 && c==0)
            printf("%c %c _\n",ans[0],ans[1]);

        else if(a==1 && b==0 && c==1)
            printf("%c _ %c\n",ans[0],ans[2]);

        else if(a==0 && b==1 && c==1)
            printf("_ %c %c\n",ans[1],ans[2]);


        else if(a==1 && b==1 && c==1){
            printf("%c %c %c",ans[0],ans[1],ans[2]);
            break;
        }
        
    }
}
