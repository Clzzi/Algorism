#include<stdio.h>
int main() {
	int num = 0;
	scanf("%d",&num);
	if(num > 0) {
		printf("양수");
	}
	else if (num < 0) {
		printf("음수");
	}
	else {
		printf("0");
	}
}
