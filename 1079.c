#include<stdio.h>
int main(void){
	char n;
		do{
			scanf("%c", &n);
			if(n!=' ') 
			printf("%c\n", n);			
		} while (n != 'q');
}
