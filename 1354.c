#include<stdio.h>
int main() {
	int n = 0;
	int i = 0;
	int j = 0;
	scanf("%d",&n);
	for(i = 1; i <=n;i++) {
		for(j=i;j<=n;j++) {
			printf("*");
		}
		printf("\n");
	}
}
