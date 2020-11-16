#include<stdio.h>
int main() {
	int a,b=0;
	int i = 0;
	scanf("%d%d",&a,&b);
	for(i = a; i<= 89;i=i+5) {
		b++;
	}
	printf("%d",b);
}
