#include<stdio.h>
typedef struct student {
	char name[20];
	int score;
}STU;

int main() {
	FILE* fp = NULL;
	STU s[10];//����ü �迭 ���� ����
	fp = fopen("output.txt", "w");
	if (fp == NULL)
		printf("���� ���� ����");
	printf("\n �̸��� ���� �Է�\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s", s[i].name);
		scanf("%d", &s[i].score);
	}
	printf("\n ����ü �Էµ� �ڷ�\n");
	for (int i = 0; i < 3; i++)
		printf("%s, %d\n", s[i].name, s[i].score);
	printf("\n���Ͽ� �����\n");
	for (int i = 0; i < 3; i++)
		fprintf(fp, "%s, %d\n", s[i].name, s[i].score);
	fclose(fp);
	return 0;
}