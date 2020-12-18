#include<stdio.h>

int main() {
	int num = 0;
	scanf("%d",&num);
	int n1 = (num%10)*10;
	int n10 = num/10;
	int total = (n1 + n10) * 2;
	if(total >= 100) {
		total = (total%10) + (total/10)%10*10;
		if(total <= 50) {
			printf("%d\n",total);
			printf("GOOD");
		}
		else {
			printf("%d\n",total);
			printf("OH MY GOD");
		}
	}
	else {
		if(total <= 50) {
			printf("%d\n",total);
			printf("GOOD");
		}
		else {
			printf("%d\n",total);
			printf("OH MY GOD");
		}
	}
}
