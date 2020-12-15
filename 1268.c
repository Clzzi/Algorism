#include<stdio.h>
int main() {
	int num = 0;
	scanf("%d",&num);
	int i = 0;
	int a = 0;
	int cnt = 0;
	for(i = 0; i < num;i++) {
		scanf("%d",&a);
		if(a%2==0) {
			cnt++;
		}
	}
	printf("%d",cnt);
}
