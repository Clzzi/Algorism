#include<stdio.h>
int main() {
	int arr[1001] = {0,};
	int n = 0;
	int i = 0;
	int cnt = 0;
	scanf("%d",&n);
	for(i = 0; i<n;i++) {
		scanf("%d",&arr[i]);
		if(arr[i]%5==0) {
			cnt = cnt + arr[i];
		}
	}
	printf("%d",cnt);
}
