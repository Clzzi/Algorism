#include<stdio.h>
int main (){
	int num = 0;
	int i = 0;
	int j = 0;
	scanf("%d",&num);
	for(i = 1; i<= num;i++) {
		for(j = 0; j < i;j++) {
			printf("*");
		}
		printf("\n");
	}
}
