#include  <stdio.h>
int main(){
    
    char str1[50],str2[50],chn1,chn2;
    int cnt1 = 0,cnt2=0;
    int stn1=0,stn2=0;
    int gamekey1 = 1,gamekey2 = 1;
    while(1){
        scanf("%c",&str1[cnt1]);
        if(str1[cnt1]=='*')
            break;
        cnt1++;
    }
    getchar();
    while(1){
        scanf("%c",&str2[cnt1]);
        if(str2[cnt1]=='*')
            break;
        cnt2++;
    }

    while(1){
        gamekey1 = 1;
        gamekey2 = 1;

        for(int i= stn1;i<=cnt1;i++){
            if(str1[i]=='a'||str1[i]=='e'||str1[i]=='i'||str1[i]=='o'||str1[i]=='u'){
                chn1 = str1[i];
                stn1 = i+1;
                printf("<1%c>",chn1);
                break;
            }
            else gamekey1 = 0;
        }
        for(int i= stn2;i<=cnt2;i++){
            if(str2[i]=='a'||str2[i]=='e'||str2[i]=='i'||str2[i]=='o'||str2[i]=='u'){
                chn2 = str1[i];
                stn2 = i+1;
                printf("<2%c>",chn2);
                break;
            }
            else gamekey2 = 0;
        }
        str1[stn1-1] = chn2;
        str2[stn2-1] = chn1;
        if(gamekey1 == 0 && gamekey2 ==0){
            for(int i=0;i<cnt1;i++){
                printf("%c",str1[i]);
            }
            printf("*");
            printf("\n");
            for(int i=0;i<cnt2;i++){
                printf("%c",str2[i]);
            }
            printf("*");
            break;
        }
            
        
    }




    

}

// if(spn!=0)//첫번째 줄이 아니면 줄을 띄움
//             printf("\n");
//         spn++;//줄 띄움 변수 증가
