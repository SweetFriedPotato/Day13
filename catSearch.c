/*

학번 : 2276337    

이름 : 최지희

프로그램 주제 : 고양이 보호소 신규 입소 고양이들 정보 관리 프로그램



*/

#include <stdio.h>
#include <string.h>

// 고양이 구조체 선언(정의)
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
    printf("## 쉼터 고양이 관리 프로그램 ##\n");
    print_menu();
    while (1) {
        printf("\n메뉴 선택: 출력(1), 등록(2), 종료(3): ");
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
            printf("\n잘못 선택하셨습니다. 다시 선택하세요.\n");
        }
    }
}

// 초기 메뉴 출력
void print_menu() {
    printf("\n------------------\n");
    printf("1. 고양이 출력\n");
    printf("2. 고양이 등록\n");
    printf("3. 끝내기\n");
    printf("------------------\n");
}

// 고양이 출력
void view_cats() {
    char str[200];
    FILE* rfp, * wfp;
    rfp = fopen("cats.txt", "r");
    // 만약 고양이 파일이 없다면, 빈 파일을 생성한다.
    if (rfp == NULL) {
        wfp = fopen("cats.txt", "w");
        fclose(wfp);
        rfp = fopen("cats.txt", "r");
    }
    // 기존 고양이 출력
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
    wfp = fopen("cats.txt", "a"); // 추가 모드
    while (getchar() != '\n');
    while (1) {
        printf("종료시 q 입력 :");
        getchar();
        scanf("%c", &ch);
        if (ch == 'q')
            break;

        printf("\n이름 입력 : ");
        scanf("%s", cat.name);
        printf("\n나이 입력 : ");
        scanf("%d", &cat.age);
        printf("\n성별 입력 (m 또는 f) : ");
        scanf(" %c", &cat.gender);
        printf("\n묘종 입력 : ");
        scanf("%s", cat.breed);
        fprintf(wfp, "%s, %d, %c, %s\n", cat.name, cat.age, cat.gender, cat.breed);
    }
    fclose(wfp);
}