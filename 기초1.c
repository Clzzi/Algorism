#pragma warning (disable:4996)
#include<stdio.h>
#define MAXQSIZE 5

int Queue[MAXQSIZE] = { 0, };
int rear = -1;
int front = -1;

void EnQueue(int *rear,int item) {
	//EnQueue, AddQ, ť�� ������ ����
	if (*rear == MAXQSIZE - 1) {
		printf(" ť�� ���� á���ϴ�. \n\n");
		return;
	}
	Queue[++ * rear] = item;
	printf(" %d : ť�� ���� �Ϸ�\n\n", item);
}

int DeQueue(int *front,int rear) { // rear�� *�� �������� : DeQueue���� rear�� ���� �ٲ��� ���� �Ŷ�
	if (*front == rear) {
		printf(" ť�� ������ϴ�.\n");
		return 1;
	}
	printf(" %d : ť ���� �Ϸ�\n\n", Queue[++ * front]);
}

void Display() {
	if (front == rear) {
		printf(" ť�� ������ϴ�. \n\n");
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
				printf(" ť�� ������ �� : ");
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
				printf("* * * * * �����մϴ� * * * * *\n");
				return 0;
			default:
				printf(" �ٽ� �Է� �Ͻÿ�. \n\n");
		}
		}
	}