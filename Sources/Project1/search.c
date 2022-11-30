#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include "struct.h"
#include "function.h"
#include "util.h"

void search() {
	system("cls");
	printf("======================================================================================================\n");
	printf("                ___   _  _______    _______  ___  __    _  _______  __   __  _______\n");
	printf("               |   | | ||  _    |  |       ||   ||  |  | ||       ||  |_|  ||   _   |\n");
	printf("               |   |_| || |_|   |  |       ||   ||   |_| ||    ___||       ||  |_|  |\n");
	printf("               |      _||       |  |       ||   ||       ||   |___ |       ||       |\n");
	printf("               |     |_ |  _   |   |      _||   ||  _    ||    ___||       ||       |\n");
	printf("               |    _  || |_|   |  |     |_ |   || | |   ||   |___ | ||_|| ||   _   |\n");
	printf("               |___| |_||_______|  |_______||___||_|  |__||_______||_|   |_||__| |__|\n");
	printf("\n");
	printf("======================================================================================================\n");
	printf("\n\n");
	printf("                                            장르별 검색\n");
	printf("\n\n");

	FILE* fpr = fopen("d:/NOW_MV_LIST.txt", "rb");
	if (fpr == NULL) {
		printf("                                  상영작 목록을 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n\n");
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	NOW now_t = { 0, };
	char genre[20] = { 0, };
	printf("                                 ┌──────────────────────────────┐\n");
	printf("                                 │ 검색할 장르:                 │\n");
	printf("                                 └──────────────────────────────┘\n");
	printf("\n");
	printf("                        장르 키워드: 액션, 공포, 드라마, 코미디, 판타지, 범죄");
	gotoxy(48, 16);
	scanf(" %s", &genre);

	int i = 0;
	int count = 0;
	while (fread(&now_t, sizeof(now_t), 1, fpr) == 1) {
		if (strcmp(now_t.genre, genre) == 0) {
			gotoxy(20, 15 + i); printf("     ┌──────────────────────────────────────────────────┐\n");
			gotoxy(20, 16 + i); printf("     │                                                  │\n");
			gotoxy(20, 17 + i); printf("     │     제목:                                        │");
			gotoxy(20, 18 + i); printf("     │     장르:                                        │");
			gotoxy(20, 19 + i); printf("     │                                                  │");
			gotoxy(20, 20 + i); printf("     └──────────────────────────────────────────────────┘\n");
			gotoxy(37, 17 + i); printf("                                       ");
			gotoxy(37, 17 + i); printf("<%s>", now_t.name);
			gotoxy(37, 18 + i); printf("                                       ");
			gotoxy(37, 18 + i); printf("%s", now_t.genre);
			count++; i += 6;
		}
	}
	fclose(fpr);
	if (count != 0) {
		printf("\n\n\n\n");
		printf("                            현재 상영작 중 %s 장르에 해당하는 영화입니다.\n", genre);
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	if (count <= 0) {
		printf("\n\n\n\n");
		printf("                        현재 상영작 중 %s 장르에 해당하는 영화가 없습니다.\n", genre);
		printf("                                  아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
}