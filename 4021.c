#include<stdio.h>
int main() {
	int i = 0;
	int sum = 0;
	int arr[7] = {0,};
	
	for(i = 0; i<7;i++) {
		scanf("%d",&arr[i]);
	}
	
	for(i = 0; i<8;i++) {
		if(arr[i] % 2 == 1)
			sum = sum + arr[i];
	}
	
	if(sum == 0)
		printf("-1");
	else
		printf("%d",sum);
}
