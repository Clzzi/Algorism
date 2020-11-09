#include<stdio.h>
int main() {
	int arr[10001]= {0,};
	int temp,i,j,n = 0;
	int max = 10000;
	
	scanf("%d",&n);
	
	for(i = 0;i<n;i++) {
		scanf("%d",&arr[i]);
		if (max > arr[i]) {
			max = arr[i];
		}
	}
		
	printf("%d",max);
}
