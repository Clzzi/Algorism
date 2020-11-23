#include<stdio.h>
int main() {
	int arr[11] = {0,};
	int i = 0;
	int num = 0;
	for(i = 1 ; i <= 10 ; i++) {
		scanf("%d",&arr[i]);
	}
	scanf("%d",&num);
	printf("%d",arr[num]);
}
