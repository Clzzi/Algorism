#include<stdio.h>
int main() {
	int n = 0;
	int i = 0;
	int num = 0;
	int com = 0;
	scanf("%d",&n);
	for(i= 0; i < n; i++) {
		scanf("%d",&num);
		if(num >= com) {
			com = num;
		}
	}
	
	printf("%d",com);
}
