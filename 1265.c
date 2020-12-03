#include<stdio.h>
int main() {
	int num = 0;
	int i = 0;
	
	scanf("%d",&num);
	
	for(i=1;i<=9;i++) {
		printf("%d*%d=%d\n",num,i,num * i);
	}
	
}
