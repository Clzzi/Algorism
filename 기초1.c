#pragma warning (disable:4996)
#include<stdio.h>
#define MAXQSIZE 5

int Queue[MAXQSIZE] = { 0, };
int rear = -1;
int front = -1;

void EnQueue(int *rear,int item) {
	//EnQueue, AddQ, 큐에 데이터 삽입
	if (*rear == MAXQSIZE - 1) {
		printf(" 큐가 가득 찼습니다. \n\n");
		return;
	}
	Queue[++ * rear] = item;
	printf(" %d : 큐에 삽입 완료\n\n", item);
}

int DeQueue(int *front,int rear) { // rear에 *가 없는이유 : DeQueue에서 rear의 값을 바꾸지 않을 거라서
	if (*front == rear) {
		printf(" 큐가 비었습니다.\n");
		return 1;
	}
	printf(" %d : 큐 삭제 완료\n\n", Queue[++ * front]);
}

void Display() {
	if (front == rear) {
		printf(" 큐가 비었습니다. \n\n");
	}

	for (int i = front + 1; i < rear + 1; i++) {
		printf(" %d  ", Queue[i]);
	}
	printf("\n\n");
}

int main() {
	int menu, n = 0;
	while (1) {
		printf("* * * * * 1 : EnQueue / 2 : DeQueue / 3 : Display / 4 : Exist * * * * *\n");
		printf(" Insert : ");
		scanf("%d", &menu);
		switch (menu) {
			case 1:
				printf(" 큐에 삽입할 값 : ");
				scanf("%d", &n);
				EnQueue(&rear, n);
				break;
			case 2:
				DeQueue(&front,rear);
				break;
			case 3:
				Display();
				break;
			case 4:
				printf("* * * * * 종료합니다 * * * * *\n");
				return 0;
			default:
				printf(" 다시 입력 하시오. \n\n");
		}
		}
	}