#include<stdio.h>
char grade(int n) {
	if(n <= 100 && n >= 90)
	{
		return 'A'; 
	}
	else if(n < 90 && n >= 80)
	{
		return 'B';
	}
	else if(n < 80 && n >= 70)
	{
		return 'C'; 
	}
	else if( n < 70 && n >= 60)
	{
		return 'D';
	}
	else{
		return 'F';
	}
}

int main () {
	int n = 0;
	scanf("%d",&n);
	printf("%c", grade(n));
}
