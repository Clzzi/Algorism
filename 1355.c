#include<stdio.h>
int main() {
	int num = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf("%d",&num);
	for(i = 0; i< num;i++) {
		for(k = num-i; k<num;k++) {
			printf(" ");
		}
		for(j = num; j > i ;j--) {
			printf("*");
		}
		printf("\n");
	}
}
