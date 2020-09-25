#include<stdio.h>
int fc(int a)
{
	if(a == 1)
		printf("1\n");
	else
	{
		printf("%d\n",a);
		return fc(a-1);
	}
}

int main(){
	int n = 0;
	scanf("%d",&n);
	fc(n);
}

