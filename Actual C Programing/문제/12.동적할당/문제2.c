#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    int N;
    scanf("%d",&N);
    float *num = NULL,min;
    num = (float *)malloc(N*sizeof(float));

    for(int i=0;i<N;i++){
        scanf("%f",&num[i]);
        if(i==0)min = num[i];
    }
    for(int i=1;i<N;i++) if(min>num[i]) min = num[i];
    // printf("%f\n",min);
    for(int i=0;i<N;i++) printf("%.2f ",num[i] - min);
    


}