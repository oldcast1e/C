#include  <stdio.h>
int main(){

    int n,m,k;
    int sum = 0;
    scanf("%d %d %d",&n,&m,&k);
    printf(n==1?"Pizza\n":(n==2?"Bugger\n":(n==3?"Salad\n":(n==4?"Ice cream\n":(n==5?"Beverage\n":"None\n")))));
    printf(m==1?"Pizza\n":(m==2?"Bugger\n":(m==3?"Salad\n":(m==4?"Ice cream\n":(m==5?"Beverage\n":"None\n")))));
    printf(k==1?"Pizza\n":(k==2?"Bugger\n":(k==3?"Salad\n":(k==4?"Ice cream\n":(k==5?"Beverage\n":"None\n")))));
    if(n==1)
        sum +=15000;
    else if(n==2)
        sum+=5000;
    else if(n==3){
        sum += 4500;
    }
    else if(n==4){
        sum += 800;
    }
    else if(n==5){
        sum += 500;
    }

    if(m==1)
        sum +=15000;
    else if(m==2)
        sum+=5000;
    else if(m==3){
        sum += 4500;
    }
    else if(m==4){
        sum += 800;
    }
    else if(m==5){
        sum += 500;
    }

    if(k==1)
        sum +=15000;
    else if(k==2)
        sum+=5000;
    else if(k==3){
        sum += 4500;
    }
    else if(k==4){
        sum += 800;
    }
    else if(k==5){
        sum += 500;
    }

    printf("Total:%dwon",sum);
    


    
}