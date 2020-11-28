#include<stdio.h>
int compare(int a,int b) {
	if(a>=b) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	int a,b = 0;
	scanf("%d%d",&a,&b);
	printf("%d",compare(a,b));
}
