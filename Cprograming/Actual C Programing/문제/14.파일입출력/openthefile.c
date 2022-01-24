#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
int main(){
    double H,W;
    int A;

    char str[100];
    FILE *fp1,*fp2,*fp3;
    fp3 = fopen("another.dat","r");
    if(fp3 == NULL){
        printf("Error\n");
        return -1;

    }
    fgets(str,20,fp3);
    printf("%s",str);
    fclose(fp3);
    // fp1 = fopen("input.dat","r");
    // if(fp1 == NULL){
    //     printf("Error");
    //     return -1;
    // }
    // fp2 = fopen("result.dat","w");

    // for(int i=0;i<3;i++){
    //     fscanf(fp1,"%lf %lf %d",&H,&W,&A);
    //     fprintf(fp2,"%lf %lf %d",H,W,A);
    // }
    // fclose(fp1);
    // fclose(fp2);



}
// 21011898 kimpowe 20
// 21012352 gildong 21
// 21023214 kimnamu 20