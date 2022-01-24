#include  <stdio.h>
int main(){
    
    int mon,na=0,nb=0,nc=0;
    int A=900,B=750,C=200;

    int cnt = 0,spn=0;

    scanf("%d",&mon);//A:900  B:750  C:200
    
    for(int na=1;na<=mon/A;na++){//11
        if(mon<(A+2*B+C)){
            printf("none");
            break;
        }
        for(int nb=1;nb<=mon/B;nb++){//13
            for(int nc=1;nc<=mon/C;nc++){//50

                if(na> nc || nb>nc){
                    if(nb%2==0){
                        if((900*na + 750*nb + 200*nc)==mon){
                            if(spn!=0)
                                printf("\n");
                            spn++;
                            printf("%d %d %d",na,nb,nc);
                        }
                            
                       } 
                }     
                
            }
        }
    }
    
}
