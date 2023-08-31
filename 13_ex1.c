#include<stdio.h>
typedef struct student {
	char name[20];
	int score;
}STU;

int main() {
	FILE* fp = NULL;
	STU s[10];//구조체 배열 변수 선언
	fp = fopen("output.txt", "w");
	if (fp == NULL)
		printf("파일 쓰기 실패");
	printf("\n 이름과 성적 입력\n");
	for (int i = 0; i < 3; i++) {
		scanf("%s", s[i].name);
		scanf("%d", &s[i].score);
	}
	printf("\n 구조체 입력된 자료\n");
	for (int i = 0; i < 3; i++)
		printf("%s, %d\n", s[i].name, s[i].score);
	printf("\n파일에 저장됨\n");
	for (int i = 0; i < 3; i++)
		fprintf(fp, "%s, %d\n", s[i].name, s[i].score);
	fclose(fp);
	return 0;
}