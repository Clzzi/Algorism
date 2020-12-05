#include<stdio.h>
int main() {
	int num = 0;
	int i = 0;
	int arr[1001] = {0,}; 
	int cnt = 0;
	scanf("%d",&num);
	for(i = 0; i < num;i++) {
		scanf("%d",&arr[i]);
	}
	
	for(i = 0; i<num;i++) {
		cnt = cnt + arr[i];
	}
	printf("%d",cnt);
}
