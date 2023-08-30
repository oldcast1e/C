#include  <stdio.h>

int N_MX(int *a,int *b,int MX,int *MXdir){
    int *j;
    for(j=a;*j!=0;j++){//MAX찾기
        if(*j>=MX){
            MX = *j;
            MXdir  = j;
        }
    }
    for(j=b;*j!=0;j++){//MAX찾기
        if(*j>=MX){
            MX = *j;
            MXdir  = j;
        }
    }
    return MXdir;
}

int M_SMX(int *a,int *b,int MX,int SMX,int MXdir,int SMXdir){
    int *i;
    for(i = a;*i!=0;i++){//SMAX찾기 = MAX의 자리는 건들면 X
        if(i != MXdir){
            if(MX >= *i && *i >= SMX){
                SMX = *i;
                SMXdir = i;
            } 
        }
    }
    for(i = b;*i!=0;i++){//SMAX찾기 = MAX의 자리는 건들면 X
        if(i != MXdir){
            if(MX >= *i && *i >= SMX){
                SMX = *i;
                SMXdir = i;
            } 
        }
    }

    return SMXdir;
}


int main(){
    int a[10]={0},b[10]={0},*pa = a,*pb = b;
    int n=0,m=0,tmp;
    int MX,SMX = -1,MXdir,SMXdir;
    for(int i=0;;i++){
        scanf("%d",(pa+i));
        if(*(pa+i) == 0){n = i;break;}
    } //n의 개수세기
    for(int i=0;;i++){
        scanf("%d",(pb+i));
        if(*(pb+i) == 0){m = i;break;}
    }//m의 개수세기
    // printf("n = %d | m =  %d",n,m);
    
    
    for(int i = 0;i<n;i++){

        if(i==0){
            MX = *a;
            
        }
    }


}
