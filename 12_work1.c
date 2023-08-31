#include<stdio.h>

int main() {
	FILE* fp = NULL;
	char str[100], name[30];
	int cnt = 0, mid, final, midsum = 0, finalsum = 0;
	double midavg, finalavg;
	fp = fopen("grade.txt", "w");
	printf("이름과 성적(중간, 기말)을 입력하세요\n");
	while (1) {
		scanf("%s %d %d", name, &mid, &final);

		if (cnt >= 3)
			break;

		// 입력된 값을 파일에 씀
		fprintf(fp, "%s %d %d\n", name, mid, final);

		// 중간고사와 기말고사의 총합을 계산
		midsum += mid;
		finalsum += final;

		// 학생 수 증가
		cnt++;
	}
	fclose(fp);

	fp = fopen("grade.txt", "r");
	while (1) {
		if (fscanf(fp, "%s %d %d\n", name, &mid, &final) == EOF)
			break;

		// 중간고사와 기말고사의 총합을 계산
		midsum += mid;
		finalsum += final;

		// 학생 수 증가
		cnt++;
	}
	fclose(fp);

	midavg = (double)midsum / cnt;
	finalavg = (double)finalsum / cnt;
	printf("중간고사 평균: %.2f\n", midavg);
	printf("기말고사 평균: %.2f\n", finalavg);
	return 0;

}