#include<stdio.h>
int main() {
	int num = 0;
	scanf("%d",&num);
	if(num > 0) {
		printf("���");
	}
	else if (num < 0) {
		printf("����");
	}
	else {
		printf("0");
	}
}
