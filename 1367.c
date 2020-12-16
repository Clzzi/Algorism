#include<stdio.h>
int main(){
	int num = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d",&num);
	for(i = 1; i<=num;i++) {
		
		for(j = num - i;j>0;j--) {
			printf(" ");
		}
		
		for(k = 1; k<=num; k++) {
			printf("*");
		}
		printf("\n");
	}
}
