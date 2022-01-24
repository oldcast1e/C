#include  <stdio.h> //노 함수 버전

// int N_MAX(int *a){
//     int max,*max_n_dir;
//     max  = *a;
//     max_n_dir = a;
//     for(int i=0;*(a+i)!=0;i++) 
//         if( *(a+i) > max){
//             max = *(a+i);
//             max_n_dir = (a+i);
//         } 
//     return max_n_dir;
// }

// int M_MAX(int *b){
//     int max,*max_m_dir;
//     max  = *b;
//     max_m_dir = b;
//     for(int i=0;*(b+i)!=0;i++) 
//         if( *(b+i) > max){
//             max = *(b+i);
//             max_m_dir = (b+i);
//         } 
//     return max_m_dir;
// }


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
    
    
    for(int i=0;i<n;i++){
        if(i==0){
            MX = *pa;MXdir = *pa;

            for(int j=0;j<n;j++){//MAX찾기
                if(*(pa+j)>=MX){
                    MX = *(pa+j);
                    MXdir  = (pa+j);
                }
            }
            for(int k=0;k<m;k++){
                if(*(pa+k)>=MX){
                    MX = *(pa+k);
                    MXdir  = (pa+k);
                }
            }
/////////////////////////////////////////////////////////

            for(int j=0;j<n;j++){//SMAX찾기 = MAX의 자리는 건들면 X
                if((pa+j)!= MXdir){
                    if(MX >= *(pa+j) && *(pa+j) >= SMX){
                        SMX  = *(pa+j);
                        SMXdir  = (pa+j);
                    }
                }
            }
            for(int j=0;j<m;j++){//SMAX찾기 = MAX의 자리는 건들면 X
                if((pb+j)!= MXdir){
                    if(MX >= *(pb+j) && *(pb+j) >= SMX){
                        SMX  = *(pb+j);
                        SMXdir  = (pb+j);
                    }
                }
            }



        }
    }


}