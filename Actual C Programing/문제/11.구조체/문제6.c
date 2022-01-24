#include  <stdio.h>
struct bodyscore{
    /* data */
    int s,m,h;
}bs;

int manscore(int m,int h){
    int rank;
    if(60>m){
        if(165>h) rank = 1;
        else if(175>h) rank = 2;
        else rank = 3;
    }
    else if(70>m){
        if(165>h) rank = 3;
        else if(175>h) rank = 1;
        else rank = 2;
    }
    else {
        if(165>h) rank = 2;
        else if(175>h) rank = 3;
        else rank = 1;
    }

    return rank;
}

int womanscore(int m,int h){
    int rank;
    if(50>m){
        if(165>h) rank = 1;
        else if(175>h) rank = 2;
        else rank = 3;
    }
    else if(60>m){
        if(165>h) rank = 3;
        else if(175>h) rank = 1;
        else rank = 2;
    }
    else {
        if(165>h) rank = 2;
        else if(175>h) rank = 3;
        else rank = 1;
    }
    
    return rank;
}

int main(){
    int N,cnt;
    int rank1=0,rank2=0,rank3=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d %d",&bs.s,&bs.m,&bs.h);
        if(bs.s == 1)cnt = manscore(bs.m,bs.h);
        else cnt = womanscore(bs.m,bs.h);

        if(cnt == 1) rank1 ++;
        else if(cnt == 2) rank2 ++;
        else if(cnt == 3) rank3 ++;
    }
    printf("%d %d %d",rank1,rank2,rank3);

}