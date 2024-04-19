//1991번
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

int arr[26][2];

void front_fuction(int x) {
	if (x < 0) return;
	printf("%c", x + 'A');
	front_fuction(arr[x][0]);
	front_fuction(arr[x][1]);

	return;
}

void middle_fuction(int x) {
	if (x < 0) return;
	middle_fuction(arr[x][0]);
	printf("%c", x + 'A');
	middle_fuction(arr[x][1]);
	return;
}

void end_fuction(int x) {
	if (x < 0) return;
	end_fuction(arr[x][0]);
	end_fuction(arr[x][1]);
	printf("%c", x + 'A');
	return;
}

int main(){
    
   int N;
   char A,B,C;
   scanf("%d",&N); getchar();
   for(int i=0;i<N;i++){
       scanf("%c %c %c",&A,&B,&C); getchar();
       arr[A-'A'][0] = B - 'A';
       arr[A-'A'][1] = C - 'A';
   }
    front_fuction(0);printf("\n");
	middle_fuction(0);printf("\n");
	end_fuction(0);printf("\n");
}