#include <stdio.h>
//����ó ����ü ����(����)
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
	printf("## ģ�� �ּҷ� ���� ���α׷� ##\n");
	print_menu();
	while (1) {
		printf("\n�޴� ����: ���(1), ���(2), ����(3)");
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
			printf("\n�߸� �����ϼ̽��ϴ�. �ٽ� �����ϼ���\n");
		}
	}
}
//�ʱ� �޴� ���
void print_menu() {
	printf("\n------------------\n");
	printf("1. ����ó ���\n");
	printf("2. ����ó ���\n");
	printf("3. ������\n");
	printf("------------------\n");
}
//����ó ���
void view_juso() {
	char str[200];
	FILE* rfp, * wfp;
	rfp = fopen("juso.txt", "r");
	//���� ����ó ������ ���ٸ�, �� ������ �����Ѵ�. 
	if (rfp == NULL) {
		wfp = fopen("juso.txt", "w");
		fclose(wfp);
		rfp = fopen("juso.txt", "r");
	}
	//���� ����ó ���
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
	wfp = fopen("juso.txt", "a");//�߰� ���
	while (getchar() != '\n');
	//fflush(stdin);
	while (1) {
		printf("����� q �Է� : ");
		getchar();
		scanf("%c", &ch);
		if (ch == 'q')break;

		printf("�̸� �Է� : ");
		scanf("%s", adr.name);
		printf("���� �Է� : ");
		scanf("%d", &adr.age);
		printf("��ȭ��ȣ �Է� : ");
		scanf("%s", adr.phone);
		fprintf(wfp, "%s, %d, %s\n", adr.name, adr.age, adr.phone);
	}
	fclose(wfp);
}