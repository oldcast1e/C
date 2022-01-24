#include  <stdio.h>
int main(){
    
    char u;
    int n,strcnt=0,numcnt=0;
    int strcntmax=0,numcntmax=0;

    scanf("%d",&n);
    getchar();

    for(int i=0;i<n;i++){
        scanf("%c",&u);
        if(49<=u && u<=57){
            if(strcnt>strcntmax)
                strcntmax = strcnt;
            strcnt = 0;
            numcnt +=1;
        }

        if(97<=u && u<=122 || 65<=u && u<=90 ){
            
            if(numcnt>numcntmax)
                numcntmax = numcnt;
            numcnt=0;
            strcnt +=1;
        }

        
        
    }
    if(numcnt>numcntmax)
        numcntmax = numcnt;
    if(strcnt>strcntmax)
        strcntmax = strcnt;
    printf("%d\n%d",strcntmax,numcntmax);
}
