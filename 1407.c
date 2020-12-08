#include<stdio.h>
#include<stdlib.h>
int main() {
	char arr[101];
	int i = 0;
	gets(arr);
	for(i = 0; arr[i] != '\0';i++) {
		if(arr[i] != ' ') {
			printf("%c",arr[i]);
		}
	}
}


/*
#include <stdio.h>
int main() {
    char string[101];
    gets(string);
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] != ' ') {
            printf("%c", string[i]);
        }
    }
}
*/
