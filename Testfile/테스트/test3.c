#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void x(){ }

void y(){ }

void z(){ 
    x();
    y();
}

int main() {
    z();
}	
