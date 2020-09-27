#include<stdio.h>                              
int main()
{
	int a,b=0;
	scanf("%d%d",&a,&b);
	int r=0;
	for(int i =a;i<=b;i++)
	{
		if(i%2==0)
		r = r-i;
		else
		r = r+i;
	}
	printf("%d",r);
}

