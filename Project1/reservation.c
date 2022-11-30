#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "function.h"
#include "struct.h"
#include "util.h"

int print_List() { //현재 상영작을 출력
	int x = 24, y = 18;
	int i = 0;
	int count = 0;
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
	printf("                                             빠른 예매\n");
	printf("\n\n");
	printf("                  ┌──────────┬───────────────────────────────┬────────────────────┐\n");
	printf("                  │   번호   │              제목             │         장르       │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  ├──────────┼───────────────────────────────┼────────────────────│\n");
	printf("                  │          │                               │                    │\n");
	printf("                  └──────────┴───────────────────────────────┴────────────────────┘\n");
	FILE* fp = fopen("D:/NOW_MV_LIST.txt", "rb");
	NOW now = { 0, };
	if (fp == NULL) {
		fp = fopen("D:/NOW_MV_LIST.txt", "wb");
		fclose(fp);
		return 0;
	}
	while (fread(&now, sizeof(now), 1, fp) == 1) {
		gotoxy(x, y + i); printf("%d", ++count);
		gotoxy(x + 7, y + i); printf("%s", now.name);
		gotoxy(x + 39, y + i); printf("%s", now.genre);
		i += 2;
	}
	fclose(fp);
	return count;
}

void choose_List(int count) { //예매할 영화를 선택
	if (count == 0) { //출력된 상영작이 없을 경우
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
		printf("                                   현재 상영중인 영화가 없습니다.\n");
		printf("                                    아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	char cho_MV[40] = { 0, };
	
	int many = 0;
	char mv_list[11][40] = { 0, };
	NOW now = { 0, };
	int i = 0;
	int count2 = 0;
	FILE* fp = fopen("D:/NOW_MV_LIST.txt", "rb");
	while (fread(&now, sizeof(now), 1, fp) == 1) {
		memcpy(&mv_list[i++], &now.name, sizeof(char) * 40);
		count2++;
	}
	fclose(fp);
	int select = 0;
	gotoxy(30, 40);
	printf("영화를 선택하세요(0 입력으로 취소):    ");
	gotoxy(66, 40);
	scanf("%d", &select);
	while (1) {
		if (select < 0 || select > count2) {
			gotoxy(37, 41);
			printf("존재하지 않는 영화입니다.");
			gotoxy(30, 40);
			printf("영화를 선택하세요(0 입력으로 취소):    ");
			gotoxy(66, 40);
			scanf("%d", &select);
			rewind(stdin);
		}
		else if (select > 0 && select <= count2) {
			strcpy(&cho_MV, &mv_list[select - 1]);
			printf("\n");
			while (1) {
				gotoxy(37, 41);
				printf("인원을 선택하세요(최대 3인):     ");
				gotoxy(37, 41);
				printf("인원을 선택하세요(최대 3인): ");
				scanf("%d", &many);
				if (many == 1 || many == 2 || many == 3) {
					seatselect(&cho_MV, many);
					return;
				}
				else {
					gotoxy(37, 42);
					printf("잘못 입력하셨습니다.");
					rewind(stdin);
					continue;
				}
			}
		}
		else if (select == 0) {
			return;
		}
		else {
			gotoxy(37, 41);
			printf("잘못 입력하셨습니다.");
			gotoxy(30, 40);
			printf("영화를 선택하세요(0 입력으로 취소):    ");
			gotoxy(66, 40);
			scanf("%d", &select);
			rewind(stdin);
		}
	}
}
