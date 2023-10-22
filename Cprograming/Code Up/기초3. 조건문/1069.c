#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char a; scanf("%c",&a);
    printf("%s",a=='A'?"best!!!":(a=='B'?"good!!":a=='C'?"run!":(a=='D'?"slowly~":"what?")));
}