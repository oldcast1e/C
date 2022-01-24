#include  <stdio.h>
int main(){
    
    char ans[3],u,tmp;
    for(int i=0;i<3;i++){
        scanf("%c",&ans[3]);
    }
    int a=0,b=0,c=0;
    int cnta = 0,cntb = 0,cntc = 0;
    scanf("%c",&tmp);
    
    while(1){
        
        if(a==0 && b==0 && c==0){
            scanf("%c%c",&u,&tmp);

            if(ans[0]==u)
                a = ans[0];
            else if(ans[1]==u)
                b  = ans[1];
            else if(ans[2]==u)
                c  = ans[2];
        }

        else if(a == ans[0] && b==0 && c==0){//첫번째 글자 맞춤

            while(1){
                if(cnta==0)
                    printf("%c _ _",ans[0]);
                scanf("%c%c",&u,&tmp);

                if(u==ans[1]){//2번째 글자 맞춤
                    while(1){
                        printf("%c %c _",ans[0],ans[1]);
                        cnta = 1;
                        scanf("%c%c",&u,&tmp);
                        if(u==ans[2]){
                            printf("%c %c %c",ans[0],ans[1],ans[2]);
                            break;
                        }
                    }
                }

                else if(u==ans[2]){//3번째 글자 맞춤
                    while(1){
                        printf("%c _ %c",ans[0],ans[1]);
                        cnta = 1;
                        scanf("%c%c",&u,&tmp);
                        if(u==ans[2]){
                            printf("%c %c %c",ans[0],ans[1],ans[2]);
                            break;
                        }
                    }
                }

             
            }

            
        
    }
    }
}