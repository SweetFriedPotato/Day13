#include <stdio.h>
//연락처 구조체 선언(정의)
typedef struct address {
	char name[30];
	int age;
	char phone[15];
}ADDR;
void print_menu();
void view_juso();
void add_juso();

int main() {
	int select = 0;
	printf("## 친구 주소록 관리 프로그램 ##\n");
	print_menu();
	while (1) {
		printf("\n메뉴 선택: 출력(1), 등록(2), 종료(3)");
		scanf("%d", &select);
		switch (select) {
		case 1:
			view_juso();
			break;
		case 2:
			add_juso();
			break;
		case 3:
			return 0;
			break;
		default:
			printf("\n잘못 선택하셨습니다. 다시 선택하세요\n");
		}
	}
}
//초기 메뉴 출력
void print_menu() {
	printf("\n------------------\n");
	printf("1. 연락처 출력\n");
	printf("2. 연락처 등록\n");
	printf("3. 끝내기\n");
	printf("------------------\n");
}
//연락처 출력
void view_juso() {
	char str[200];
	FILE* rfp, * wfp;
	rfp = fopen("juso.txt", "r");
	//만약 연락처 파일이 없다면, 빈 파일을 생성한다. 
	if (rfp == NULL) {
		wfp = fopen("juso.txt", "w");
		fclose(wfp);
		rfp = fopen("juso.txt", "r");
	}
	//기존 연락처 출력
	while (1) {
		fgets(str, 200, rfp);
		if (feof(rfp))break;
		fputs(str, stdout);
	}
	fclose(rfp);
}

void add_juso() {
	ADDR adr;
	char str[2000], ch;
	FILE* wfp;
	wfp = fopen("juso.txt", "a");//추가 모드
	while (getchar() != '\n');
	//fflush(stdin);
	while (1) {
		printf("종료시 q 입력 : ");
		getchar();
		scanf("%c", &ch);
		if (ch == 'q')break;

		printf("이름 입력 : ");
		scanf("%s", adr.name);
		printf("나이 입력 : ");
		scanf("%d", &adr.age);
		printf("전화번호 입력 : ");
		scanf("%s", adr.phone);
		fprintf(wfp, "%s, %d, %s\n", adr.name, adr.age, adr.phone);
	}
	fclose(wfp);
}