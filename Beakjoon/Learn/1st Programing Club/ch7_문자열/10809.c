#include  <stdio.h>

int main(){

    char arr[100];
    int alb[26];
    int cnt = 0;
    while (1){
        scanf("%c",&arr[cnt]);
        if(arr[cnt]=='\n') break;
        cnt ++;
    }
    for(int i=0;i<26;i++){
        alb[i] = -1;
    }

    printf("cnt = %d\n",cnt);
    for(int i=0;i<cnt;i++){
        switch(arr[i]){
            case 97: alb[0] = i;break;
            case 98: alb[1] = i;break;
            case 99: alb[2] = i;break;
            case 100: alb[3] = i;break;
            case 101: alb[4] = i;break;
            case 102: alb[5] = i;break;
            case 103: alb[6] = i;break;
            case 104: alb[7] = i;break;
            case 105: alb[8] = i;break;
            case 106: alb[9] = i;break;
            case 107: alb[10] = i;break;
            case 108: alb[11] = i;break;
            case 109: alb[12] = i;break;
            case 110: alb[13] = i;break;
            case 111: alb[14] = i;break;
            case 112: alb[15] = i;break;
            case 113: alb[16] = i;break;
            case 114: alb[17] = i;break;
            case 115: alb[18] = i;break;
            case 116: alb[19] = i;break;
            case 117: alb[20] = i;break;
            case 118: alb[21] = i;break;
            case 119: alb[22] = i;break;
            case 120: alb[23] = i;break;
            case 121: alb[24] = i;break;
            case 122: alb[25] = i;break;
        }
    }
    for(int i=0;i<26;i++){
        printf("%d ",alb[i]);
    }


    

}
// if(spn!=0) printf("\n");//첫번째 줄이 아니면 줄을 띄움
//         spn ++;//줄 띄움 변수 증가

