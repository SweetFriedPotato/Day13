#include<stdio.h>
#define MAX_SIZE 20
int main()
{
	FILE* fp = NULL;
	char name[MAX_SIZE];
	int age;
	double score,sum=0;
	fp = fopen("output.txt", "w");
	
	for (int i = 0; i < 2; i++) {
		printf("%d번째 학생 정보 입력(이름, 나이, 성적) : ", i + 1);
		scanf("%s %d %lf", name, &age, &score);
		fprintf(fp, "%10s %3d %3lf\n", name, age, score);
	}
	fclose(fp);
	fp = fopen("output.txt", "r");
	if (fp == NULL)
		printf("파일 열기 실패\n");
	/*for (int i = 0; i < 2; i++) {
		fscanf(fp, "%s %d %lf", name, &age, &score);
		printf("%s %d %lf\n", name, age, score);
		sum += score;
	}*/

	//while (!feof(fp)) { // 마지막 데이터를 한번 더 읽는다.
	//	fscanf(fp, "%s %d %lf", name, &age, &score);
	//	printf("%s %d %lf\n", name, age, score);
	//	sum += score;
	//}
	while (1) { // 마지막 데이터를 한번 더 읽는다.
		fscanf(fp, "%s %d %lf", name, &age, &score);
		if (feof(fp))break;
		printf("%s %d %lf\n", name, age, score);
		sum += score;
	}
	printf("점수 평균 : %.2f\n", sum / 2);
}