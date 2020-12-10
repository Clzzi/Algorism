// ���� ���
#pragma warning (disable:4996)
#include <stdio.h>
int n;
int map[31][31];
int visited[31];

void DFS(int v) {
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i] == 1 && !visited[i]) {
			// ����v�� i�� ����Ǿ� �ְ� , i�� �湮���� �ʾҴٸ�
			printf("%d --> %d\n",v,i);
			DFS(i);
		}
	}
}

int main() {
	int startV = 0;
	int v1 = 0;
	int v2 = 0;
	printf("Vertex ���� : ");
	scanf("%d", &n);
	printf("���� ��� : ");
	scanf("%d", &startV);
	while (1) {
		scanf("%d%d", &v1, &v2);
		if (v1 == -1 && v2 == -1) // Ż������
			break;
		map[v1][v2] = map[v2][v1] = 1; // �밢������ �߶����� ������
	}
	DFS(startV);
	return 0;
}
