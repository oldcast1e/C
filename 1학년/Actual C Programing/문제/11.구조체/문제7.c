#include  <stdio.h>
struct num{
    int n,rank;
};
int main(){
    int N,cnt,A,B;
    struct num prs[10];
    for(int i=0;i<10;i++){
        scanf("%d",&prs[i].n);
    }
    for(int i=0;i<10;i++){
        cnt = 0;
        for(int j=0;j<10;j++){
            if(i!=j){
                if(prs[i].n<prs[j].n) cnt ++;
            }
        }
        prs[i].rank = cnt +1;
    }
    for(int i=0;i<10;i++){
        if(prs[i].rank==3 ||prs[i].rank==7) printf("%d ",prs[i].n);
    }
}
//78 65 23 43 82 95 31 15 8 54