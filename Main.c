#pragma warning (disable:4996)
#include<stdio.h>
int main() {
	int n = 0;
	int m = 0;
	int mok = 0;
	int namuzi = 0;
	
	scanf("%d%d", &n, &m);
	
	mok = n / m;
	namuzi = n % m;
	
	if (namuzi >= 1)
		printf("%d", mok + 1);
	else
		printf("%d", mok);
}