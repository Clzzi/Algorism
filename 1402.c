#include<stdio.h>
int main() {
	int num = 0;
	int arr[1001] = {0,};
	int i = 0;
	scanf("%d",&num);
	for(i = 1; i<=num;i++) {
		scanf("%d",&arr[i]);
	}
	for(i=num;i>0;i--) {
		printf("%d ",arr[i]);
	}
}
