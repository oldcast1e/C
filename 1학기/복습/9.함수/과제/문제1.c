#include  <stdio.h>

int num_digit(int x){
    int cnt=0;
    while (x>0)
    {
        x/=10;
        cnt++;
    }
    return cnt;
}

void convert_top(int x,int y){//정수,자리수

    int num[2100000000];
    for(int i=0;i<y;i++){
        num[i] = x%10;
        x/=10;
        printf("<>");
    }
    //1111112
    for(int i=0;i<y;i++){
        printf("%d",num[i]);
    }
    printf("M");



    // for(int i=0;i<y-1;i+=2){//0123
    //     if('a'<= (char)(num[i]+num[i+1]) && (char)(num[i]+num[i+1]) <= 'z')
    //         printf("%c",(num[i]+num[i+1]));
    //     else if('A'<= (char)(num[i]+num[i+1]) && (char)(num[i]+num[i+1]) <= 'Z')
    //         printf("%c",(num[i]+num[i+1]));
    //     else printf("*");
    // }
    // if('a'<=num[y] && num[y] <='z' ||'A'<=num[y] && num[y] <='Z');
    // else printf("*");

    // return 0;
}

int convert_bottom(int x){
    return 0;

}
int main(){
    
    int n;
    scanf("%d",&n);
    int k = num_digit(n);

    printf("<%d %d>\n",n,k);
    if(k%2==0) convert_bottom(n);
    else convert_top(n,k);//홀수이면 입력받음 n과 자리수 k
    
}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가

