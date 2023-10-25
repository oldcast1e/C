#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    int a,b,c,d,cnt=7,key=0;
    int n[2][7];
    for(int i=0;i<2;i++){ if(i==1) cnt = 6;
        for(int j=0;j<cnt;j++) scanf("%d",&n[i][j]);};
    cnt = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(n[0][i] == n[1][j]) cnt ++;
        }
    }
    if(cnt == 5){
        for(int j=0;j<6;j++){
            if(n[0][6]==n[1][j]){key=1;break;}
        }
    }

    if(key==1) printf("2");
    else {
        switch (cnt)
        {
        case 3: printf("5");
            break;
        case 4: printf("4");
            break;
        case 5: printf("3");
            break;
        case 6: printf("1");
            break;
        
        default: printf("0");
            break;
        }
    }
/**
13 23 24 35 40 45 7
24 13 7 23 40 23
 */
} 