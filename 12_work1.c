#include<stdio.h>

int main() {
	FILE* fp = NULL;
	char str[100], name[30];
	int cnt = 0, mid, final, midsum = 0, finalsum = 0;
	double midavg, finalavg;
	fp = fopen("grade.txt", "w");
	printf("�̸��� ����(�߰�, �⸻)�� �Է��ϼ���\n");
	while (1) {
		scanf("%s %d %d", name, &mid, &final);

		if (cnt >= 3)
			break;

		// �Էµ� ���� ���Ͽ� ��
		fprintf(fp, "%s %d %d\n", name, mid, final);

		// �߰����� �⸻����� ������ ���
		midsum += mid;
		finalsum += final;

		// �л� �� ����
		cnt++;
	}
	fclose(fp);

	fp = fopen("grade.txt", "r");
	while (1) {
		if (fscanf(fp, "%s %d %d\n", name, &mid, &final) == EOF)
			break;

		// �߰����� �⸻����� ������ ���
		midsum += mid;
		finalsum += final;

		// �л� �� ����
		cnt++;
	}
	fclose(fp);

	midavg = (double)midsum / cnt;
	finalavg = (double)finalsum / cnt;
	printf("�߰���� ���: %.2f\n", midavg);
	printf("�⸻��� ���: %.2f\n", finalavg);
	return 0;

}