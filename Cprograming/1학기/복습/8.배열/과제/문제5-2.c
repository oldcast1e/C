#include  <stdio.h>
int main(){//x
    
    int A[100];
    int B[100];
    int rst[100],key=1,rstcnt;
    int cnta =0,cntb=0,tmp;
    while(1){
        
        scanf("%d",&A[cnta]);
        if(A[cnta]<0) break;
        cnta++;
    }

    while(1){
        scanf("%d",&B[cntb]);
        if(B[cntb]<0) break;
        cntb++;
    }
    ////////
    rst[0] = A[0];
    ///
    rstcnt = 1;
    for(int i=1;i<cnta;i++){//1~3
        key = 1;
        for(int j=0;j<i;j++){
            if(A[i]==A[j]) key = 0;
            // printf("<%d>",key);
        }
        if(key==1){
            rst[rstcnt] = A[i];
            rstcnt++;
            // printf("okay");
        }
    }
    key = 1;
    for(int j=0;j<rstcnt;j++){
        if(rst[j]==B[0]) key = 0;
    }
    
    if(key==1) rst[rstcnt] = B[0];
        // printf("key = %d/B[0] = %d|",key,B[0]);
    rstcnt++;
    // for(int j=0;j<rstcnt;j++){
    //     printf("<<%d>>",rst[j]);
    // }
    for(int i=1;i<cntb;i++){
        key =1;
        for(int j=0;j<i;j++){
            for(int k=0;k<rstcnt;k++){
                if(B[i]==B[j] || B[i]==rst[k]) key = 0;
            }
        }
        if(key==1){
            rst[rstcnt] = B[i];
            rstcnt++;
        }
    }

    for(int j=0;j<rstcnt-1;j++){
        for(int i=0;i<rstcnt-1;i++){
            if(rst[i+1]<rst[i]){
                tmp = rst[i];
                rst[i] = rst[i+1];
                rst[i+1] = tmp;
            }
        }
    }
    for(int j=0;j<rstcnt;j++){
        printf(" %d",rst[j]);
    }

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
