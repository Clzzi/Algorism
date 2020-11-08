#include<stdio.h>
int main() {
	int arr[101]= {0,};
	int temp,i,j,n = 0;
	
	scanf("%d",&n);
	for(i = 0;i<n;i++) {
		scanf("%d",&arr[i]);
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++) {
			if(arr[j] < arr[j + 1]) {
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for(i = 0; i < n;i++) {
		printf("%d ",arr[i]);
	}
}
