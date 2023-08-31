/*

�й� : 2276337    

�̸� : ������

���α׷� ���� : ����� ��ȣ�� �ű� �Լ� ����̵� ���� ���� ���α׷�



*/

#include <stdio.h>
#include <string.h>

// ����� ����ü ����(����)
typedef struct cat {
    char name[30];
    int age;
    char gender;
    char breed[30];
} Cat;

void print_menu();
void view_cats();
void add_cat();

int main() {
    int select = 0;
    printf("## ���� ����� ���� ���α׷� ##\n");
    print_menu();
    while (1) {
        printf("\n�޴� ����: ���(1), ���(2), ����(3): ");
        scanf("%d", &select);
        switch (select) {
        case 1:
            view_cats();
            break;
        case 2:
            add_cat();
            break;
        case 3:
            return 0;
        default:
            printf("\n�߸� �����ϼ̽��ϴ�. �ٽ� �����ϼ���.\n");
        }
    }
}

// �ʱ� �޴� ���
void print_menu() {
    printf("\n------------------\n");
    printf("1. ����� ���\n");
    printf("2. ����� ���\n");
    printf("3. ������\n");
    printf("------------------\n");
}

// ����� ���
void view_cats() {
    char str[200];
    FILE* rfp, * wfp;
    rfp = fopen("cats.txt", "r");
    // ���� ����� ������ ���ٸ�, �� ������ �����Ѵ�.
    if (rfp == NULL) {
        wfp = fopen("cats.txt", "w");
        fclose(wfp);
        rfp = fopen("cats.txt", "r");
    }
    // ���� ����� ���
    while (1) {
        fgets(str, 200, rfp);
        if (feof(rfp))
            break;
        fputs(str, stdout);
    }
    fclose(rfp);
}

void add_cat() {
    Cat cat;
    char str[2000], ch;
    FILE* wfp;
    wfp = fopen("cats.txt", "a"); // �߰� ���
    while (getchar() != '\n');
    while (1) {
        printf("����� q �Է� :");
        getchar();
        scanf("%c", &ch);
        if (ch == 'q')
            break;

        printf("\n�̸� �Է� : ");
        scanf("%s", cat.name);
        printf("\n���� �Է� : ");
        scanf("%d", &cat.age);
        printf("\n���� �Է� (m �Ǵ� f) : ");
        scanf(" %c", &cat.gender);
        printf("\n���� �Է� : ");
        scanf("%s", cat.breed);
        fprintf(wfp, "%s, %d, %c, %s\n", cat.name, cat.age, cat.gender, cat.breed);
    }
    fclose(wfp);
}