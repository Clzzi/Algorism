#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NLEN 20 // �ִ� �̸� ���̴� 20�� ( Max Name Length )
#define MAX_SUB 2 // �ִ� ���� ���ڴ� 2�� ( Max Subject Number )
#define MAX_STU 200 // �ִ� �л� ���� 200�� ( Max Student Number )
#define MAX_ALEN 300 // �ִ� �ּ� ���̴� 300�� ( Max Addres Length )
#define MAX_PNLEN 11 // �ִ� ��ȭ��ȣ ���̴� 11�� ( Max PhoneNumber Length )
#define MAX_NUM 3320 // �ִ� �й� 3320( Max Number )
#define MIN_NUM 1101 // �ּ� �й� 1101 ( Min Number )

typedef struct _s { // ����ü ����
	char name[MAX_NLEN]; // �̸�
	int stuNum;			 // �й�
	int scores[MAX_SUB]; // [����,�ڷᱸ��] 2����
	char stuAdd[MAX_ALEN]; // �ּ�
	char stuPN[MAX_PNLEN]; // ��ȭ��ȣ
}Student;

const char* subjName[MAX_SUB] = { "����","�ڷᱸ��" }; // const�� ���� �ڷᱸ���� �����������ϰ� ����
Student gStu[MAX_NUM]; // 3200���� ���������� �������

void Init(); // �ʱ�ȭ �Լ�
void Run(); // ���� �Լ�

int main() {
	Init(); // �ʱ�ȭ 
	Run(); // ����
	return 0;
}

void Init() {
	// ��� �л����� ��� ���� ������ -1�� �ʱ�ȭ
	// ���� �� �ִ� �л� ���� �ִ� 200�� ������ ������ ����ü�� 3320�̱⶧���� 3320�� for�������� �ʱ�ȭ
	for (int i = 0; i < MAX_NUM; i++) 
		for (int j = 0; j < MAX_SUB; j++) // ������� 2����
			gStu[i].scores[j] = -1;
}

int Menu(); // ���� �޴� ��� �� ���� �Լ�
void AddStu(); // �л� �߰� �� �л� ������ �Է� �Լ�
void RemoveStu(); // �л� ���� �Լ�
void SearchStu(); // �л� �˻� �Լ�
void SeeBestStu(); // 1�� �л� Ȯ�� �� ��� �Լ�
void CorrectStu(); // �л� ���� ���� �Լ�
void SeeStuData(Student* stu); // �Էµ� �л��� �й��� �޾ƿ��� �Լ�
int IsVaildNum(int sNum); // ��ȿ�� �й����� �˻��ϴ� �Լ�
int IsVaildScore(int score); // ��ȿ�� �������� �˻��ϴ� �Լ�
int IsVaildName(char* sName); // ��ȿ�� �̸����� �˻��ϴ� �Լ�
int IsVaildPNum(char* sPn); // ��ȿ�� ��ȭ��ȣ���� �˻��ϴ� �Լ�
int duplicatePNum(char* sPn); // �Էµ� ��ȭ��ȣ�� �ߺ����� �˻��ϴ� �Լ� 

void Run() { // ���� �Լ�
	int n = 0;
	while (1) // n�� 0�� �ԷµǸ� �����
	{
		n = Menu();
		switch (n) {
		case 0:
			printf("* * * DGSW ���α׷� ���� * * *\n");
			exit(0); // 0�� �ԷµǸ� ���α׷� ����
		case 1:			// 1�� �ԷµǸ� �л� �߰�
			AddStu();
			break;
		case 2:			// 2�� �ԷµǸ� �л� ����
			RemoveStu();
			break;
		case 3:			// 3�� �ԷµǸ� �л� �˻�
			SearchStu();
			break;
		case 4:			// 4�� �ԷµǸ� �� ������ 1�� �л� ���
			SeeBestStu();
			break;
		case 5:			// 5�� �ԷµǸ� �л��� �����͸� �����ϴ� �Լ� ����
			CorrectStu();
			break;
		default:		// 1 ~ 5�� ���ڰ� �Էµ��� ������ ���
			printf("  �ٽ� �������ֽʽÿ�.\n");
		}
	}
}

int Menu() { // ���� �޴� ��� �� ���� �Լ�
	int n = 0;
	printf("\n* * * DGSW ���� ���� ���α׷� �޴�( 0 : ���� ) * * *\n\n");
	printf("   1 : �л� �߰� �� ������ �Է�  2 : �л� ����\n");
	printf("   3 : �л� �˻�	         4 : ���� 1�� �л� ���  \n");
	printf("                  5 : �� �� �� ��                  \n\n");
	printf("* * * * * * Ư �� �� �� �� �� �� �� �� �� * * * * * *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("  �޴� ��ȣ : ");
	scanf("%d%c", &n);
	printf("\n");
	return n;
}

void AddStu() { // �л� �߰� �� �л� ������ �Է� �Լ�
	Student* p_stu = NULL; // NULL �ʱ�ȭ
	int sNum = 0; // student Number - �й� 
	char sPn[MAX_PNLEN]; // student Phone number - �л� ��ȭ��ȣ
	char sName[MAX_NLEN]; // student Name Length - �л� �̸�

	printf("  �߰��� DGSW �л� ��ȣ ( ���� : �г� �� ��ȣ 1312 ) : ");
	scanf("%d%c", &sNum); // �й��Է¹ޱ�

	if (IsVaildNum(sNum) == 0) { // IsVaildNum --> �й� ��ȿ���� �˻���
		printf("  ������ ��� ��ȣ �Դϴ�.\n");
		return;
	}

	// ��ȿ�� �й��̶�� ������ �̹� ������ �й����� üũ�ؾ���
	if (gStu[sNum - 1].stuNum) {
		// gStu��� ����ü�� �й�-1�� �ش��ϴ°��� �й��� 0�� �ƴ� �ٸ����� �����Ѵٸ� �̹� �����Ǿ��ٴ� ��
		printf("  �й��� �̹� �����մϴ�.\n");
		return;
	}

	p_stu = gStu + (sNum - 1); // gStu�� �ּҿ� �л��� �й� -1 �� ������. 
							   // ��, gStu�� �ּҸ� �й�-1�� �ش��ϴ� �ּҷ� ������ٴ°�. 
	p_stu->stuNum = sNum; // p_stu�� stuNum�� �й��� �־������ν� �й��� �Է¿Ϸ�����

	while (1) { // �̸��� �߸��Է��ҽ� ����ε� �̸��� ���������� �ݺ���
		printf("  �̸� : ");
		gets(sName);// - ���� 
		if (IsVaildName(sName) == 0) { // IsVaildName --> �̸� ��ȿ�� �˻�
			printf("  �̸����� ���ڰ� �� �� �����ϴ�.\n"); // ���� ��ȿ���˻翡�� 0�� ���Ϲ޾Ҵٸ� ���� ���
			for (int i = 0; i < MAX_NLEN; i++) { // for������ ���� �̸��� �ʱ�ȭ ����
				sName[i] = NULL;
			}
		}
		else { // ��ȿ�� �˻翡�� 1�� ���Ϲ޾Ҵٸ� p_stu->name�̶�� ������ sName�� �־��ش�.
			strcpy(p_stu->name, sName);
			break;
		}
	}

	printf("  �ּ� : ");
	gets(p_stu->stuAdd); // p_stu�� stuAdd��� ������ �ּҸ� �Է¹��� 

	while (1) { // ��ȿ�� ��ȭ��ȣ�� ���������� �ݺ����� ����.
		printf("  ��ȭ��ȣ ( �Է¿��� : 01012345678 ) : ");
		gets(sPn); // sPn�� ��ȭ��ȣ�� �Է¹���

		if (IsVaildPNum(sPn) == 0) { // IsVaildPNum --> ��ȭ��ȣ ��ȿ�� �˻�
			printf("  ��ȭ��ȣ �Է� �����Դϴ�.\n"); // ���� ��ȿ���˻翡�� 0�� ���Ϲ޾Ҵٸ�, �������
			for (int i = 0; i < MAX_PNLEN; i++) { // ��������� ������ sPn�� �ݺ����� ���� �ʱ�ȭ����.
				sPn[i] = NULL;
			}
		}
		else { // ��ȿ���˻翡�� 1�� ���Ϲ޾Ҵٸ�, �Ǵٸ� �ߺ� �˻縦 ����
			if (duplicatePNum(sPn) == 0) { // duplicatePNum --> �ߺ� �˻�
				printf("  �ߺ��� ��ȭ��ȣ �Դϴ�.\n"); // ���� �ߺ��˻翡�� 0�� ���Ϲ޾Ҵٸ�, ���� ���
				for (int i = 0; i < MAX_PNLEN; i++) {// ��������� ������ sPn�� �ݺ����� ���� �ʱ�ȭ ����.
					sPn[i] = NULL;
				}
			}
			else { // �ߺ� �˻翡���� 1�� ���Ϲ������ 
				strcpy(p_stu->stuPN, sPn); // strcpy�� ���� p_stu->stuPN�� sPn�� �־���.
				break;
			}
		}
	}

	printf("\n  %d ���� ���� �Է´ܰ� \n", MAX_SUB);
	for (int n = 0; n < MAX_SUB; n++) {
		printf("  %s ���� : ", subjName[n]); // const�� �������� subjName������ ������ �ϳ��ϳ� �Է¹���
		scanf("%d%c", p_stu->scores + n); // p_stu->scores�� �ּ���, ���������� �ּҰ��� �����ָ� �״����ּҷ� �̵��� ������ �ްԵ�.
		if (IsVaildScore(p_stu->scores[n]) == 0) { // IsVaildScore --> ���� ��ȿ���˻�
			p_stu->scores[n] = -1; // ��ȿ�� �˻翡�� �Է��� �߸��� ������ ������ -1�� ����.
			printf("  %s ������ ������ �߸��ԷµǾ� -1�� ǥ�õ˴ϴ�.\n", subjName[n]); // ���� ���
		}
	}
}

int IsVaildNum(int sNum) {
	// sNum�� �޾ƿͼ� 1101 ~ 1120 / 1201 ~ 1220 / 1301 ~ 1320 / 2101 ~ 2120 / 
	// 2201 ~ 2220 / 2301 ~ 2320 / 3101 ~ 3120 / 3201 ~ 3220 / 3301 ~ 3320 ���� �޾ƿ��� ���� ����
	return (
		(sNum >= 1101 && sNum <= 1120) || (sNum >= 1201 && sNum <= 1220)
     || (sNum >= 1301 && sNum <= 1320) || (sNum >= 2101 && sNum <= 2120) 
     || (sNum >= 2201 && sNum <= 2220) || (sNum >= 2301 && sNum <= 2320) 
	 || (sNum >= 3101 && sNum <= 3220) || (sNum >= 3301 && sNum <= 3320));
}

int IsVaildScore(int score) {
	// ���� ������ 0 ~ 100 ���̶�� ��, ���ǵѴ� ������ 1(true) , �ƴϸ� 0(false) ����
	return (score >= 0 && score <= 100);
}

int IsVaildName(char* sName) {
	// sName�� �޾ƿͼ� sName[i]�� NULL�� �ƴҶ����� �ݺ����� �����ش�.
	for (int i = 0; sName[i] != NULL; i++) {
		if (sName[i] >= 48 && sName[i] <= 57) { // �ƽ�Ű�ڵ��� 0 ~ 9 ������ ���� �ִٸ� 0����
			return 0;
		}
	}
	return 1; // �ƴϸ� 1����
}

int IsVaildPNum(char* sPn) { // sPn�� �޾ƿͼ� ��ȿ�� �˻�����
	if (strlen(sPn) == 11) { // ���� sPn�� ���̰� 11�� ���
		for (int i = 0; i < 11; i++) { // for������ ���� sPn[i]�� ���ڰ� �ƴ϶�� 0����
			if (sPn[i] < 48 || sPn[i] > 57) {
				return 0;
			}
		}
		return 1; // 11���̸鼭 ��� ���ڶ�� 1����
	}
	else { // 11�ڰ� �ƴ϶�� 0����
		return 0;
	}
}

int duplicatePNum(char* sPn) { // sPn�� �޾ƿͼ� �ߺ� �˻�����. 
	for (int i = 0; i <= MAX_NUM; i++) { // 3320( MAX_NUM )���� �ݺ����� ������
		int result = strcmp(gStu[i].stuPN, sPn); // result�� strcmp�� sPn �� gStu[i].stuPN�� ���� ���� ����
		if (result == 0) { // ���� result�� 0�̶�� ��, sPn �� gStu[i].stuPN�� ���ٸ� 0 ����
			return 0;
		}
	}
	return 1; // �Է¹��� ��ȭ��ȣ�� �ߺ��� �ƴ϶�� 1����
}

void RemoveStu() { // �л� ���� �Լ�
	Student* p_stu = NULL; // NULL�� �ʱ�ȭ
	int s_Num; // student Number - �й�

	printf("  ������ �л��� ��ȣ( ���� : 1312 ) : ");
	scanf("%d%c", &s_Num);

	if (!IsVaildNum(s_Num)) { // IsVaildNum(sNum) == 0 �� ���� / ��,�й� ������ �����
		printf("  �߸��� �й� �Է��Դϴ�.\n"); // ���� ����� ����
		return;
	}

	if (gStu[s_Num - 1].stuNum == 0) { // �й��� �ش��ϴ� �л��� ���� ���
		// gStu����ü�� �й�-1�� �ش��ϴ� ĭ�� �й��� 0�̶�� ������ �й��� ���°�
		printf("  �ش� ��ȣ �л��� �����ϴ�.\n");
		return;
	}

	p_stu = gStu + (s_Num - 1); // p_stu�� ���� �й� - 1 �� �ش��ϴ� �ּҸ� �־��� 
	strcpy_s(p_stu->name, sizeof(p_stu->name), "����"); // �̸� �ʱ�ȭ, �̸��� ��������.

	for (int i = 0; i < MAX_SUB; i++) {
		p_stu->scores[i] = -1; // ������ ���� �ʱ�ȭ
	}

	for (int j = 0; j < MAX_ALEN; j++) {
		p_stu->stuAdd[j] = NULL; // �ּ� �ʱ�ȭ
	}

	for (int k = 0; k < MAX_PNLEN; k++) {
		p_stu->stuPN[k] = NULL; // ��ȭ��ȣ �ʱ�ȭ
	}
	printf("  ���� �Ϸ�\n");
}


void SearchStu() { // �л� �˻� �Լ�
	Student* p_stu = NULL; // NULL �ʱ�ȭ
	printf("  �˻��� DGSW �л� ��ȣ ( ���� : 1312 ) : ");
	int s_Num; // student Number
	scanf("%d%c", &s_Num);
	if (!IsVaildNum(s_Num)) { // �й� ������ �����
		printf("  ��ȿ�� ������ ��� �й��Դϴ�. \n");
		return;
	}
	if (gStu[s_Num - 1].stuNum == 0) { // �ش� �л��� ���� ���
		printf("  �Է��� ��ȣ�� �ش��ϴ� �л��� �����ϴ�. \n");
		return;
	}
	p_stu = gStu + (s_Num - 1); // p_stu�� ���� �й� - 1�� �ش��ϴ� �ּҸ� �־���
	SeeStuData(p_stu); // �Է¹��� ��ȣ�� �ش��ϴ� �л��� ����Լ��� �������.
}

void SeeStuData(Student* p_stu) { // �л� �˻��ÿ� �Է¹��� ��ȣ�� �ش��ϴ� �л� ���
	printf("  ��ȣ : %d \n", p_stu->stuNum);
	printf("  �̸� : %s \n", p_stu->name);
	for (int i = 0; i < MAX_SUB; i++)
		printf("  %s���� : %d \n", subjName[i], p_stu->scores[i]);
	printf("  ��ȭ��ȣ : %s \n", p_stu->stuPN);
	printf("  �ּ� : %s", p_stu->stuAdd);
	printf("\n\n");
}

void SeeBestStu() {
	int MaxLan = -1; // �ְ����� - ����
	int MaxGuZo = -1; // �ְ����� - �ڷᱸ��

	for (int i = MIN_NUM; i <= MAX_NUM; i++)
		if (gStu[i].stuNum) // ���� gStu[i]�� stuNum(�й�)�̶�� ������ ���� �ִٸ�(= 0�� �ƴ϶��)
			if (MaxLan <= gStu[i].scores[0]) { // gStu[i]�� stuNum(�й�)�̶�� ������ ���� �ְ� ���� �ְ��������� ���� ũ�ٸ�
				MaxLan = gStu[i].scores[0]; // ���� �ְ������� ���������� �־��ְ�
			}

	for (int i = MIN_NUM; i <= MAX_NUM; i++)
		if (gStu[i].stuNum) // ���� gStu[i]�� stuNum(�й�)�̶�� ������ ���� �ִٸ� (= 0�� �ƴ϶��)
			if (MaxGuZo < gStu[i].scores[1]) { // gStu[i]�� stuNum(�й�)�̶�� ������ ���� �ְ� �ڷᱸ�� �ְ��������� ���� ũ�ٸ�
				MaxGuZo = gStu[i].scores[1]; // �ڷᱸ�� �ְ������� ���������� �־��ְ�
			}

	if (MaxLan == -1 || MaxGuZo == -1) { // ���� MaxLan �Ǵ� MaxGuZo�� -1 �̶�� ��, �Էµ� �����Ͱ� �ƹ��͵� ���ٸ�
		printf(" �Էµ� �л��� �����ϴ�.\n"); // ���� ���
	}
	else {
		printf("- ���� 1�� - \n");
		for (int i = MIN_NUM; i <= MAX_NUM; i++) { // gStu[i]�� scores[0] �� ������ MaxLan�̶�� gStu[i]�� ������ ���
			if (gStu[i].scores[0] == MaxLan) {
				SeeStuData(&gStu[i]);
				printf("\n");
			}
		}
		printf("- �ڷᱸ�� 1�� - \n");
		for (int i = MIN_NUM; i <= MAX_NUM; i++) { // gStu[i]�� scores[0] �� ������ MaxGuZo�̶�� gStu[i]�� ������ ���
			if (gStu[i].scores[1] == MaxGuZo) {
				SeeStuData(&gStu[i]);
				printf("\n");
			}
		}
	}
}

void CorrectStu() {
	Student* p_stu = NULL;
	int s_Num;
	char sPn[MAX_PNLEN]; // student Phone number - �л� ��ȭ��ȣ
	char sName[MAX_NLEN]; // student Name Length - �л� �̸�
	printf("  ������ �л��� �й��� �Է��ϼ��� : ");
	scanf("%d%c", &s_Num);

	if (!IsVaildNum(s_Num)) { // IsVaildNum(sNum) == 0 �� ���� / ��,�й� ������ �����
		printf("   �߸��� �й� �Է��Դϴ�.\n"); // ���� ����� ����
		return;
	}

	if (gStu[s_Num - 1].stuNum == 0) { // �й��� �ش��ϴ� �л��� ���� ���
		// gStu����ü�� �й�-1�� �ش��ϴ� ĭ�� �й��� 0�̶�� ������ �й��� ���°�
		printf("   �ش� ��ȣ �л��� �����ϴ�.\n");
		return;
	}

	p_stu = gStu + (s_Num - 1); // p_stu�� ���� �й� - 1 �� �ش��ϴ� �ּҸ� �־��� 

	for (int i = 0; i < MAX_SUB; i++) {
		p_stu->scores[i] = -1; // ������ ���� �ʱ�ȭ
	}

	for (int j = 0; j < MAX_ALEN; j++) {
		p_stu->stuAdd[j] = NULL; // �ּ� �ʱ�ȭ
	}

	for (int k = 0; k < MAX_PNLEN; k++) {
		p_stu->stuPN[k] = NULL; // ��ȭ��ȣ �ʱ�ȭ
	}

	while (1) { // �̸��� �߸��Է��ҽ� ����ε� �̸��� ���������� �ݺ���
		printf("  ������ �̸� : ");
		gets(sName);
		if (IsVaildName(sName) == 0) { // IsVaildName --> �̸� ��ȿ�� �˻�
			printf("   �̸����� ���ڰ� �� �� �����ϴ�.\n"); // ���� ��ȿ���˻翡�� 0�� ���Ϲ޾Ҵٸ� ���� ���
			for (int i = 0; i < MAX_NLEN; i++) { // for������ ���� �̸��� �ʱ�ȭ ����
				sName[i] = NULL;
			}
		}
		else { // ��ȿ�� �˻翡�� 1�� ���Ϲ޾Ҵٸ� p_stu->name�̶�� ������ sName�� �־��ش�.
			strcpy(p_stu->name, sName);
			break;
		}
	}

	printf("  ������ �ּ� : ");
	gets(p_stu->stuAdd); // p_stu�� stuAdd��� ������ �ּҸ� �Է¹��� 

	while (1) { // ��ȿ�� ��ȭ��ȣ�� ���������� �ݺ����� ����.
		printf("  ������ ��ȭ��ȣ ( �Է¿��� : 01012345678 ) : ");
		gets(sPn); // sPn�� ��ȭ��ȣ�� �Է¹���

		if (IsVaildPNum(sPn) == 0) { // IsVaildPNum --> ��ȭ��ȣ ��ȿ�� �˻�
			printf(" ��ȭ��ȣ �Է� �����Դϴ�.\n"); // ���� ��ȿ���˻翡�� 0�� ���Ϲ޾Ҵٸ�, �������
			for (int i = 0; i < MAX_PNLEN; i++) { // ��������� ������ sPn�� �ݺ����� ���� �ʱ�ȭ����.
				sPn[i] = NULL;
			}
		}
		else { // ��ȿ���˻翡�� 1�� ���Ϲ޾Ҵٸ�, �Ǵٸ� �ߺ� �˻縦 ����
			if (duplicatePNum(sPn) == 0) { // duplicatePNum --> �ߺ� �˻�
				printf("  �ߺ��� ��ȭ��ȣ �Դϴ�.\n"); // ���� �ߺ��˻翡�� 0�� ���Ϲ޾Ҵٸ�, ���� ���
				for (int i = 0; i < MAX_PNLEN; i++) {// ��������� ������ sPn�� �ݺ����� ���� �ʱ�ȭ ����.
					sPn[i] = NULL;
				}
			}
			else { // �ߺ� �˻翡���� 1�� ���Ϲ������ 
				strcpy(p_stu->stuPN, sPn); // strcpy�� ���� p_stu->stuPN�� sPn�� �־���.
				break;
			}
		}
	}

	printf("\n  ������ %d ���� ���� �Է´ܰ� \n", MAX_SUB);
	for (int n = 0; n < MAX_SUB; n++) {
		printf("  %s ���� : ", subjName[n]); // const�� �������� subjName������ ������ �ϳ��ϳ� �Է¹���
		scanf("%d%c", p_stu->scores + n); // p_stu->scores�� �ּ���, ���������� �ּҰ��� �����ָ� �״����ּҷ� �̵��� ������ �ްԵ�.
		if (IsVaildScore(p_stu->scores[n]) == 0) { // IsVaildScore --> ���� ��ȿ���˻�
			p_stu->scores[n] = -1; // ��ȿ�� �˻翡�� �Է��� �߸��� ������ ������ -1�� ����.
			printf("  %s ������ ������ �߸��ԷµǾ� -1�� ǥ�õ˴ϴ�.\n", subjName[n]); // ���� ���
		}
	}
}
