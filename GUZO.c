#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<string.h>

#define MAX_NLEN 20 // 최대 이름 길이는 20자 ( Max Name Length )
#define MAX_SUB 2 // 최대 과목 숫자는 2개 ( Max Subject Number )
#define MAX_STU 200 // 최대 학생 수는 200명 ( Max Student Number )
#define MAX_ALEN 300 // 최대 주소 길이는 300자 ( Max Addres Length )
#define MAX_PNLEN 11 // 최대 전화번호 길이는 11자 ( Max PhoneNumber Length )
#define MAX_NUM 3320 // 최대 학번 3320( Max Number )
#define MIN_NUM 1101 // 최소 학번 1101 ( Min Number )

typedef struct _s { // 구조체 생성
	char name[MAX_NLEN]; // 이름
	int stuNum;			 // 학번
	int scores[MAX_SUB]; // [국어,자료구조] 2과목
	char stuAdd[MAX_ALEN]; // 주소
	char stuPN[MAX_PNLEN]; // 전화번호
}Student;

const char* subjName[MAX_SUB] = { "국어","자료구조" }; // const로 국어 자료구조를 변경하지못하게 선언
Student gStu[MAX_NUM]; // 3200개의 전역변수를 만들었음

void Init(); // 초기화 함수
void Run(); // 실행 함수

int main() {
	Init(); // 초기화 
	Run(); // 실행
	return 0;
}

void Init() {
	// 모든 학생들의 모든 과목 점수를 -1로 초기화
	// 받을 수 있는 학생 수는 최대 200명 이지만 생성한 구조체는 3320이기때문에 3320번 for문돌려서 초기화
	for (int i = 0; i < MAX_NUM; i++) 
		for (int j = 0; j < MAX_SUB; j++) // 과목수는 2과목
			gStu[i].scores[j] = -1;
}

int Menu(); // 메인 메뉴 출력 및 선택 함수
void AddStu(); // 학생 추가 및 학생 데이터 입력 함수
void RemoveStu(); // 학생 삭제 함수
void SearchStu(); // 학생 검색 함수
void SeeBestStu(); // 1등 학생 확인 및 출력 함수
void CorrectStu(); // 학생 정보 수정 함수
void SeeStuData(Student* stu); // 입력된 학생의 학번을 받아오는 함수
int IsVaildNum(int sNum); // 유효한 학번인지 검사하는 함수
int IsVaildScore(int score); // 유효한 점수인지 검사하는 함수
int IsVaildName(char* sName); // 유효한 이름인지 검사하는 함수
int IsVaildPNum(char* sPn); // 유효한 전화번호인지 검사하는 함수
int duplicatePNum(char* sPn); // 입력된 전화번호가 중복인지 검사하는 함수 

void Run() { // 실행 함수
	int n = 0;
	while (1) // n에 0이 입력되면 종료됨
	{
		n = Menu();
		switch (n) {
		case 0:
			printf("* * * DGSW 프로그램 종료 * * *\n");
			exit(0); // 0이 입력되면 프로그램 종료
		case 1:			// 1이 입력되면 학생 추가
			AddStu();
			break;
		case 2:			// 2가 입력되면 학생 삭제
			RemoveStu();
			break;
		case 3:			// 3이 입력되면 학생 검색
			SearchStu();
			break;
		case 4:			// 4가 입력되면 각 과목의 1등 학생 출력
			SeeBestStu();
			break;
		case 5:			// 5가 입력되면 학생의 데이터를 수정하는 함수 실행
			CorrectStu();
			break;
		default:		// 1 ~ 5의 숫자가 입력되지 않을시 출력
			printf("  다시 선택해주십시오.\n");
		}
	}
}

int Menu() { // 메인 메뉴 출력 및 선택 함수
	int n = 0;
	printf("\n* * * DGSW 성적 관리 프로그램 메뉴( 0 : 종료 ) * * *\n\n");
	printf("   1 : 학생 추가 및 데이터 입력  2 : 학생 삭제\n");
	printf("   3 : 학생 검색	         4 : 과목 1등 학생 출력  \n");
	printf("                  5 : 학 생 수 정                  \n\n");
	printf("* * * * * * 특 수 문 자 절 대 입 력 금 지 * * * * * *\n");
	printf("* * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("  메뉴 번호 : ");
	scanf("%d%c", &n);
	printf("\n");
	return n;
}

void AddStu() { // 학생 추가 및 학생 데이터 입력 함수
	Student* p_stu = NULL; // NULL 초기화
	int sNum = 0; // student Number - 학번 
	char sPn[MAX_PNLEN]; // student Phone number - 학생 전화번호
	char sName[MAX_NLEN]; // student Name Length - 학생 이름

	printf("  추가할 DGSW 학생 번호 ( 예시 : 학년 반 번호 1312 ) : ");
	scanf("%d%c", &sNum); // 학번입력받기

	if (IsVaildNum(sNum) == 0) { // IsVaildNum --> 학번 유효성을 검사함
		printf("  범위를 벗어난 번호 입니다.\n");
		return;
	}

	// 유효한 학번이라면 기존에 이미 생성한 학번인지 체크해야함
	if (gStu[sNum - 1].stuNum) {
		// gStu라는 구조체의 학번-1에 해당하는곳에 학번이 0이 아닌 다른수로 존재한다면 이미 생성되었다는 뜻
		printf("  학번이 이미 존재합니다.\n");
		return;
	}

	p_stu = gStu + (sNum - 1); // gStu의 주소에 학생의 학번 -1 을 더해줌. 
							   // 즉, gStu의 주소를 학번-1에 해당하는 주소로 만들었다는것. 
	p_stu->stuNum = sNum; // p_stu의 stuNum에 학번을 넣어줌으로써 학번을 입력완료해줌

	while (1) { // 이름을 잘못입력할시 제대로된 이름을 받을때까지 반복함
		printf("  이름 : ");
		gets(sName);// - 수정 
		if (IsVaildName(sName) == 0) { // IsVaildName --> 이름 유효성 검사
			printf("  이름에는 숫자가 들어갈 수 없습니다.\n"); // 만약 유효성검사에서 0을 리턴받았다면 오류 출력
			for (int i = 0; i < MAX_NLEN; i++) { // for문으로 받은 이름을 초기화 해줌
				sName[i] = NULL;
			}
		}
		else { // 유효성 검사에서 1을 리턴받았다면 p_stu->name이라는 공간에 sName을 넣어준다.
			strcpy(p_stu->name, sName);
			break;
		}
	}

	printf("  주소 : ");
	gets(p_stu->stuAdd); // p_stu의 stuAdd라는 공간에 주소를 입력받음 

	while (1) { // 유효한 전화번호를 받을때까지 반복문을 실행.
		printf("  전화번호 ( 입력예시 : 01012345678 ) : ");
		gets(sPn); // sPn에 전화번호를 입력받음

		if (IsVaildPNum(sPn) == 0) { // IsVaildPNum --> 전화번호 유효성 검사
			printf("  전화번호 입력 오류입니다.\n"); // 만약 유효성검사에서 0을 리턴받았다면, 오류출력
			for (int i = 0; i < MAX_PNLEN; i++) { // 오류출력을 해준후 sPn을 반복문을 통해 초기화해줌.
				sPn[i] = NULL;
			}
		}
		else { // 유효성검사에서 1을 리턴받았다면, 또다른 중복 검사를 실행
			if (duplicatePNum(sPn) == 0) { // duplicatePNum --> 중복 검사
				printf("  중복된 전화번호 입니다.\n"); // 만약 중복검사에서 0을 리턴받았다면, 오류 출력
				for (int i = 0; i < MAX_PNLEN; i++) {// 오류출력을 해준후 sPn을 반복문을 통해 초기화 해줌.
					sPn[i] = NULL;
				}
			}
			else { // 중복 검사에서도 1을 리턴받은경우 
				strcpy(p_stu->stuPN, sPn); // strcpy를 통해 p_stu->stuPN에 sPn을 넣어줌.
				break;
			}
		}
	}

	printf("\n  %d 과목 성적 입력단계 \n", MAX_SUB);
	for (int n = 0; n < MAX_SUB; n++) {
		printf("  %s 성적 : ", subjName[n]); // const로 생성해준 subjName과목의 성적을 하나하나 입력받음
		scanf("%d%c", p_stu->scores + n); // p_stu->scores는 주소임, 받을때마다 주소값을 더해주면 그다음주소로 이동해 점수를 받게됨.
		if (IsVaildScore(p_stu->scores[n]) == 0) { // IsVaildScore --> 점수 유효성검사
			p_stu->scores[n] = -1; // 유효성 검사에서 입력이 잘못된 과목의 점수는 -1로 해줌.
			printf("  %s 과목의 점수가 잘못입력되어 -1로 표시됩니다.\n", subjName[n]); // 오류 출력
		}
	}
}

int IsVaildNum(int sNum) {
	// sNum을 받아와서 1101 ~ 1120 / 1201 ~ 1220 / 1301 ~ 1320 / 2101 ~ 2120 / 
	// 2201 ~ 2220 / 2301 ~ 2320 / 3101 ~ 3120 / 3201 ~ 3220 / 3301 ~ 3320 값만 받아오게 조건 지정
	return (
		(sNum >= 1101 && sNum <= 1120) || (sNum >= 1201 && sNum <= 1220)
     || (sNum >= 1301 && sNum <= 1320) || (sNum >= 2101 && sNum <= 2120) 
     || (sNum >= 2201 && sNum <= 2220) || (sNum >= 2301 && sNum <= 2320) 
	 || (sNum >= 3101 && sNum <= 3220) || (sNum >= 3301 && sNum <= 3320));
}

int IsVaildScore(int score) {
	// 받은 점수가 0 ~ 100 사이라면 즉, 조건둘다 맞을시 1(true) , 아니면 0(false) 리턴
	return (score >= 0 && score <= 100);
}

int IsVaildName(char* sName) {
	// sName을 받아와서 sName[i]가 NULL이 아닐때까지 반복문을 돌려준다.
	for (int i = 0; sName[i] != NULL; i++) {
		if (sName[i] >= 48 && sName[i] <= 57) { // 아스키코드의 0 ~ 9 사이의 값이 있다면 0리턴
			return 0;
		}
	}
	return 1; // 아니면 1리턴
}

int IsVaildPNum(char* sPn) { // sPn을 받아와서 유효성 검사해줌
	if (strlen(sPn) == 11) { // 만약 sPn의 길이가 11자 라면
		for (int i = 0; i < 11; i++) { // for문으로 만약 sPn[i]가 숫자가 아니라면 0리턴
			if (sPn[i] < 48 || sPn[i] > 57) {
				return 0;
			}
		}
		return 1; // 11자이면서 모두 숫자라면 1리턴
	}
	else { // 11자가 아니라면 0리턴
		return 0;
	}
}

int duplicatePNum(char* sPn) { // sPn을 받아와서 중복 검사해줌. 
	for (int i = 0; i <= MAX_NUM; i++) { // 3320( MAX_NUM )까지 반복문을 돌려서
		int result = strcmp(gStu[i].stuPN, sPn); // result에 strcmp로 sPn 과 gStu[i].stuPN을 비교한 값을 대입
		if (result == 0) { // 만약 result가 0이라면 즉, sPn 과 gStu[i].stuPN이 같다면 0 리턴
			return 0;
		}
	}
	return 1; // 입력받은 전화번호가 중복이 아니라면 1리턴
}

void RemoveStu() { // 학생 삭제 함수
	Student* p_stu = NULL; // NULL로 초기화
	int s_Num; // student Number - 학번

	printf("  삭제할 학생의 번호( 예시 : 1312 ) : ");
	scanf("%d%c", &s_Num);

	if (!IsVaildNum(s_Num)) { // IsVaildNum(sNum) == 0 과 같음 / 즉,학번 범위를 벗어나면
		printf("  잘못된 학번 입력입니다.\n"); // 오류 출력후 리턴
		return;
	}

	if (gStu[s_Num - 1].stuNum == 0) { // 학번에 해당하는 학생이 없는 경우
		// gStu구조체의 학번-1에 해당하는 칸에 학번이 0이라면 삭제할 학번이 없는것
		printf("  해당 번호 학생은 없습니다.\n");
		return;
	}

	p_stu = gStu + (s_Num - 1); // p_stu에 받은 학번 - 1 에 해당하는 주소를 넣어줌 
	strcpy_s(p_stu->name, sizeof(p_stu->name), "전학"); // 이름 초기화, 이름을 지워버림.

	for (int i = 0; i < MAX_SUB; i++) {
		p_stu->scores[i] = -1; // 교과목 점수 초기화
	}

	for (int j = 0; j < MAX_ALEN; j++) {
		p_stu->stuAdd[j] = NULL; // 주소 초기화
	}

	for (int k = 0; k < MAX_PNLEN; k++) {
		p_stu->stuPN[k] = NULL; // 전화번호 초기화
	}
	printf("  삭제 완료\n");
}


void SearchStu() { // 학생 검색 함수
	Student* p_stu = NULL; // NULL 초기화
	printf("  검색할 DGSW 학생 번호 ( 예시 : 1312 ) : ");
	int s_Num; // student Number
	scanf("%d%c", &s_Num);
	if (!IsVaildNum(s_Num)) { // 학번 범위를 벗어나면
		printf("  유효한 범위를 벗어난 학번입니다. \n");
		return;
	}
	if (gStu[s_Num - 1].stuNum == 0) { // 해당 학생이 없는 경우
		printf("  입력한 번호에 해당하는 학생은 없습니다. \n");
		return;
	}
	p_stu = gStu + (s_Num - 1); // p_stu에 받은 학번 - 1에 해당하는 주소를 넣어줌
	SeeStuData(p_stu); // 입력받은 번호에 해당하는 학생을 출력함수로 출력해줌.
}

void SeeStuData(Student* p_stu) { // 학생 검색시에 입력받은 번호에 해당하는 학생 출력
	printf("  번호 : %d \n", p_stu->stuNum);
	printf("  이름 : %s \n", p_stu->name);
	for (int i = 0; i < MAX_SUB; i++)
		printf("  %s점수 : %d \n", subjName[i], p_stu->scores[i]);
	printf("  전화번호 : %s \n", p_stu->stuPN);
	printf("  주소 : %s", p_stu->stuAdd);
	printf("\n\n");
}

void SeeBestStu() {
	int MaxLan = -1; // 최고점수 - 국어
	int MaxGuZo = -1; // 최고점수 - 자료구조

	for (int i = MIN_NUM; i <= MAX_NUM; i++)
		if (gStu[i].stuNum) // 만약 gStu[i]의 stuNum(학번)이라는 공간에 값이 있다면(= 0이 아니라면)
			if (MaxLan <= gStu[i].scores[0]) { // gStu[i]의 stuNum(학번)이라는 공간에 값이 있고 국어 최고점수보다 값이 크다면
				MaxLan = gStu[i].scores[0]; // 국어 최고점수에 현재점수를 넣어주고
			}

	for (int i = MIN_NUM; i <= MAX_NUM; i++)
		if (gStu[i].stuNum) // 만약 gStu[i]의 stuNum(학번)이라는 공간에 값이 있다면 (= 0이 아니라면)
			if (MaxGuZo < gStu[i].scores[1]) { // gStu[i]의 stuNum(학번)이라는 공간에 값이 있고 자료구조 최고점수보다 값이 크다면
				MaxGuZo = gStu[i].scores[1]; // 자료구조 최고점수에 현재점수를 넣어주고
			}

	if (MaxLan == -1 || MaxGuZo == -1) { // 만약 MaxLan 또는 MaxGuZo가 -1 이라면 즉, 입력된 데이터가 아무것도 없다면
		printf(" 입력된 학생이 없습니다.\n"); // 오류 출력
	}
	else {
		printf("- 국어 1등 - \n");
		for (int i = MIN_NUM; i <= MAX_NUM; i++) { // gStu[i]의 scores[0] 의 점수가 MaxLan이라면 gStu[i]의 정보를 출력
			if (gStu[i].scores[0] == MaxLan) {
				SeeStuData(&gStu[i]);
				printf("\n");
			}
		}
		printf("- 자료구조 1등 - \n");
		for (int i = MIN_NUM; i <= MAX_NUM; i++) { // gStu[i]의 scores[0] 의 점수가 MaxGuZo이라면 gStu[i]의 정보를 출력
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
	char sPn[MAX_PNLEN]; // student Phone number - 학생 전화번호
	char sName[MAX_NLEN]; // student Name Length - 학생 이름
	printf("  수정할 학생의 학번을 입력하세요 : ");
	scanf("%d%c", &s_Num);

	if (!IsVaildNum(s_Num)) { // IsVaildNum(sNum) == 0 과 같음 / 즉,학번 범위를 벗어나면
		printf("   잘못된 학번 입력입니다.\n"); // 오류 출력후 리턴
		return;
	}

	if (gStu[s_Num - 1].stuNum == 0) { // 학번에 해당하는 학생이 없는 경우
		// gStu구조체의 학번-1에 해당하는 칸에 학번이 0이라면 삭제할 학번이 없는것
		printf("   해당 번호 학생은 없습니다.\n");
		return;
	}

	p_stu = gStu + (s_Num - 1); // p_stu에 받은 학번 - 1 에 해당하는 주소를 넣어줌 

	for (int i = 0; i < MAX_SUB; i++) {
		p_stu->scores[i] = -1; // 교과목 점수 초기화
	}

	for (int j = 0; j < MAX_ALEN; j++) {
		p_stu->stuAdd[j] = NULL; // 주소 초기화
	}

	for (int k = 0; k < MAX_PNLEN; k++) {
		p_stu->stuPN[k] = NULL; // 전화번호 초기화
	}

	while (1) { // 이름을 잘못입력할시 제대로된 이름을 받을때까지 반복함
		printf("  수정할 이름 : ");
		gets(sName);
		if (IsVaildName(sName) == 0) { // IsVaildName --> 이름 유효성 검사
			printf("   이름에는 숫자가 들어갈 수 없습니다.\n"); // 만약 유효성검사에서 0을 리턴받았다면 오류 출력
			for (int i = 0; i < MAX_NLEN; i++) { // for문으로 받은 이름을 초기화 해줌
				sName[i] = NULL;
			}
		}
		else { // 유효성 검사에서 1을 리턴받았다면 p_stu->name이라는 공간에 sName을 넣어준다.
			strcpy(p_stu->name, sName);
			break;
		}
	}

	printf("  수정할 주소 : ");
	gets(p_stu->stuAdd); // p_stu의 stuAdd라는 공간에 주소를 입력받음 

	while (1) { // 유효한 전화번호를 받을때까지 반복문을 실행.
		printf("  수정할 전화번호 ( 입력예시 : 01012345678 ) : ");
		gets(sPn); // sPn에 전화번호를 입력받음

		if (IsVaildPNum(sPn) == 0) { // IsVaildPNum --> 전화번호 유효성 검사
			printf(" 전화번호 입력 오류입니다.\n"); // 만약 유효성검사에서 0을 리턴받았다면, 오류출력
			for (int i = 0; i < MAX_PNLEN; i++) { // 오류출력을 해준후 sPn을 반복문을 통해 초기화해줌.
				sPn[i] = NULL;
			}
		}
		else { // 유효성검사에서 1을 리턴받았다면, 또다른 중복 검사를 실행
			if (duplicatePNum(sPn) == 0) { // duplicatePNum --> 중복 검사
				printf("  중복된 전화번호 입니다.\n"); // 만약 중복검사에서 0을 리턴받았다면, 오류 출력
				for (int i = 0; i < MAX_PNLEN; i++) {// 오류출력을 해준후 sPn을 반복문을 통해 초기화 해줌.
					sPn[i] = NULL;
				}
			}
			else { // 중복 검사에서도 1을 리턴받은경우 
				strcpy(p_stu->stuPN, sPn); // strcpy를 통해 p_stu->stuPN에 sPn을 넣어줌.
				break;
			}
		}
	}

	printf("\n  수정할 %d 과목 성적 입력단계 \n", MAX_SUB);
	for (int n = 0; n < MAX_SUB; n++) {
		printf("  %s 성적 : ", subjName[n]); // const로 생성해준 subjName과목의 성적을 하나하나 입력받음
		scanf("%d%c", p_stu->scores + n); // p_stu->scores는 주소임, 받을때마다 주소값을 더해주면 그다음주소로 이동해 점수를 받게됨.
		if (IsVaildScore(p_stu->scores[n]) == 0) { // IsVaildScore --> 점수 유효성검사
			p_stu->scores[n] = -1; // 유효성 검사에서 입력이 잘못된 과목의 점수는 -1로 해줌.
			printf("  %s 과목의 점수가 잘못입력되어 -1로 표시됩니다.\n", subjName[n]); // 오류 출력
		}
	}
}
