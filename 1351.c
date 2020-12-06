#include<stdio.h>
int main() {
	int a = 0;
	int b = 0;
	int k = 0;
	int j = 0;
	scanf("%d%d",&a,&b);
	for(k = a; k <= b;k++) {
		for(j = 1; j <= 9; j++) {
			printf("%d*%d=%d\n",k,j,k*j);	
		}
	}		
}
