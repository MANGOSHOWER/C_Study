#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "struct.h"
#include "function.h"
#include <Windows.h>
#include <conio.h>

void admin_menu() {
	char id[10] = { 0, };
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
	printf("                                  관리자 로그인(0 입력으로 돌아가기)\n");
	printf("\n\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ ID:                           │\n");
	printf("                                 └───────────────────────────────┘\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ 비밀번호:                     │\n");
	printf("                                 └───────────────────────────────┘\n");
	while (1) {
		gotoxy(39, 16); printf("              ");
		gotoxy(45, 19); printf("              ");
		gotoxy(39, 16); scanf(" %s", id);
		if (strcmp(&id, "0") == 0) {
			return;
		}
		gotoxy(45, 19);
		char pass;
		char backsp = 0;
		char passwd[20] = { 0, };
		int i = 0;
		while (1) {
			rewind(stdin);
			pass = _getch();
			if (i < 20 && pass >= 48 && pass <= 57) {
				memcpy(&passwd[i], &pass, sizeof(char));
				gotoxy(45 + i, 19);
				printf("*");
				i++;
				gotoxy(45 + i, 19);
			}
			else if (i < 20 && pass >= 65 && pass <= 90) {
				memcpy(&passwd[i], &pass, sizeof(char));
				gotoxy(45 + i, 19);
				printf("*");
				i++;
				gotoxy(45 + i, 19);
			}
			else if (i < 20 && pass >= 97 && pass <= 122) {
				memcpy(&passwd[i], &pass, sizeof(char));
				gotoxy(45 + i, 19);
				printf("*");
				i++;
				gotoxy(45 + i, 19);
			}
			else if (i < 20 && i != 0 && pass == 8) {
				memcpy(&passwd[i - 1], &backsp, sizeof(char));
				gotoxy(45 + i - 1, 19);
				printf(" ");
				i--;
				gotoxy(45 + i - 1, 19);
			}
			else if (pass == -32) {
				_getch();
				rewind(stdin);
				continue;
			}
			else if (pass == 13) {
				break;
			}
		}
		if (strcmp(&id, "admin") == 0 && strcmp(&passwd, "1111") == 0) {
			while (1) {
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
			printf("                                        KB 시네마 관리자용 메뉴\n");
			printf("\n\n\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 1. 현재 상영작 추가         │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 2. 현재 상영작 삭제         │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 3. 현재 상영작 조회         │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 4. 영화 추천 기능용 DB 추가 │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 5. 영화 추천 기능용 DB 삭제 │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 6. 영화 추천 기능용 DB 조회 │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 7. 예매 내역 초기화         │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("                                   ┌─────────────────────────────┐\n");
			printf("                                   │ 8. 돌아가기                 │\n");
			printf("                                   └─────────────────────────────┘\n");
			printf("\n\n\n\n\n");
			printf("                                                                           메뉴 선택: ");
			
			int num;
			gotoxy(86, 45); printf("    ");
			gotoxy(86, 45); scanf("%d", &num);
			rewind(stdin);

			char name[20] = { 0, };
			switch (num) {
				case 1:
					admin_NOW_MV_input();
					break;
				case 2:
					NOW_MV_del();
					break;
				case 3:
					NOW_MV_read();
					break;
				case 4:
					admin_REC_MV_input();
					break;
				case 5:
					REC_MV_del();
					break;
				case 6:
					REC_MV_read();
					break;
				case 7:
					book_init();
					break;
				case 8:
					return;
				}
			}
		}
		else {
			gotoxy(34, 23);
			printf("ID 또는 비밀번호가 틀렸습니다.\n");
		}
	}
}