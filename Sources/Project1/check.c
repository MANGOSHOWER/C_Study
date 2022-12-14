#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "struct.h"
#include "util.h"
#include "function.h"

//예매 내역 로그인, 비회원 선택
void checkIn() {
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
	printf("                                            예매 내역 조회\n");
	printf("\n\n");
	printf("                                    ┌─────────────────────────┐\n");
	printf("                                    │        1. 로그인        │\n");
	printf("                                    └─────────────────────────┘\n");
	printf("                                    ┌─────────────────────────┐\n");
	printf("                                    │      2. 비회원 조회     │\n");
	printf("                                    └─────────────────────────┘\n");
	printf("\n\n");
	printf("                                                          기능 선택 (0으로 돌아가기): ");
	int select = 0;
	while (1) {
		scanf("%d", &select);
		if (select == 2) {
			check();
			return;
		}
		else if (select == 1) {
			check_mem();
			return;
		}
		else if (select == 0) {
			return;
		}
		else {
			gotoxy(0, 23);
			printf("                                                          기능 선택 (0으로 돌아가기):  ");
			rewind(stdin);
			gotoxy(86, 23);
		}
	}
	return;
}

//비회원 예매내역 조회
void check() {
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
	printf("                                           예매 내역 조회\n");
	FILE* fp = fopen("D:/book.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n\n");
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	BOOK book_t = { 0, };

	char name[10] = { 0, };
	char phone[20] = { 0, };

	printf("\n\n");
	printf("                                    ┌─────────────────────────┐\n");
	printf("                                    │ 예매자명:               │\n");
	printf("                                    └─────────────────────────┘\n");
	printf("                                    ┌─────────────────────────┐\n");
	printf("                                    │ 전화번호:               │\n");
	printf("                                    └─────────────────────────┘\n");
	gotoxy(48, 16); scanf(" %s", &name);
	gotoxy(48, 19); scanf(" %s", &phone);
	printf("\n\n\n");
	printf("                                     예매 내역을 조회중입니다...\n");
	Sleep(2000);

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
	printf("                                          %s님의 예매 내역\n", name);
	printf("\n\n\n");

	int count = 0;
	int line1 = 0;
	while (fread(&book_t, sizeof(book_t), 1, fp) == 1) {
		if (strcmp(name, book_t.name) == 0 && strcmp(phone, book_t.phone) == 0) {
			gotoxy(25, 15 + line1); printf("┌──────────────────────────────────────────────────┐\n");
			gotoxy(25, 16 + line1); printf("│                    번째 예매 내역                │\n");
			gotoxy(44, 16 + line1); printf("%d", ++count);
			gotoxy(25, 17 + line1); printf("│     제목:                                        │");
			gotoxy(25, 18 + line1); printf("│     좌석:                                        │");
			gotoxy(25, 19 + line1); printf("│     결제 금액:                                   │");
			gotoxy(25, 20 + line1); printf("└──────────────────────────────────────────────────┘\n");
			gotoxy(37, 17 + line1); printf("                                       ");
			gotoxy(37, 17 + line1); printf("<%s>", book_t.movie);
			gotoxy(37, 18 + line1); printf("                                       ");
			gotoxy(37, 18 + line1); printf("%s %s %s", book_t.seat1, book_t.seat2, book_t.seat3);
			gotoxy(42, 19 + line1); printf("                     ");
			gotoxy(42, 19 + line1); printf("%d", book_t.price);
			printf("\n");
			line1 += 6;
			printf("\n");
		}
	}
	if (count == 0) {
		fclose(fp);
		printf("                                     고객님의 예매 내역이 없습니다.\n");
		printf("                                      아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	printf("\n\n");
	int i;
	gotoxy(0, 19 + line1 - 2); printf("                            ┌─────────────┐             ┌─────────────┐\n");
	gotoxy(0, 20 + line1 - 2); printf("                            │ 1. 돌아가기 │             │ 2. 예매 취소│\n");
	gotoxy(0, 21 + line1 - 2); printf("                            └─────────────┘             └─────────────┘\n");
	printf("\n\n");
	gotoxy(0, 23 + line1 - 2); printf("                                                                            기능 선택: ");
	scanf("%d", &i);
	printf("\n\n");
	while (1) {

		if (i == 1) {
			fclose(fp);
			return;
		}
		else if (i == 2) {
			int i = 0 + (count*6);
			fclose(fp);
			char movie[40] = { 0, };
			char seat[5] = { 0, };
			gotoxy(0, 16 + i); printf("                               ┌────────────────────────────────────┐                          \n");
			gotoxy(0, 17 + i); printf("                               │ 취소할 영화:                       │                          \n");
			gotoxy(0, 18 + i); printf("                               └────────────────────────────────────┘                          \n");
			gotoxy(0, 19 + i); printf("                               ┌────────────────────────────────────┐                          \n");
			gotoxy(0, 20 + i); printf("                               │ 취소할 좌석:                       │                          \n");
			gotoxy(0, 21 + i); printf("                               └────────────────────────────────────┘                          \n");
			gotoxy(0, 22 + i); printf("                                                                                                   \n");
			gotoxy(0, 23 + i); printf("                        예매한 좌석이 여러개인 경우, 첫 번째 좌석을 입력하세요.                        ");
			gotoxy(0, 24 + i); printf("                            0을 입력하면 작업을 취소하고 메뉴로 돌아갑니다.                        ");
			gotoxy(46, 17 + i); scanf(" %[^\n]s", &movie);
			if (strcmp(&movie, "0") == 0) {
				return;
			}
			gotoxy(46, 20 + i); scanf(" %s", &seat);
			delete_name(name, phone, movie, seat);
			return;
		}
		else {
			rewind(stdin);
			gotoxy(0, 23 + line1 - 2); printf("                                                                            기능 선택:    ");
			gotoxy(0, 23 + line1 - 2); printf("                                                                            기능 선택: ");
			scanf("%d", &i);
		}
	}
	fclose(fp);
	return;
}

//비회원 예매 내역 삭제
void delete_name(char* name, char* phone, char* movie, char* seat) {
	FILE* fp = fopen("d:/book.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n");
		printf("\n                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}

	BOOK src = { 0, };
	static BOOK dest[256] = { 0, };
	int idx = 0;
	int found = 0;
	while (fread(&src, sizeof(BOOK), 1, fp) == 1) {
		if (strcmp(name, src.name) == 0 && strcmp(phone, src.phone) == 0 && strcmp(movie, src.movie) == 0 && strcmp(seat, src.seat1) == 0) {
			found = 1;
		}
		else {
			dest[idx++] = src;
		}
	}
	fclose(fp);

	if (found == 0) {
		printf("\n\n\n\n");
		printf("                                입력하신 예매 내역이 존재하지 않습니다.\n");
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}

	fp = fopen("d:/book.txt", "wb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n");
		printf("\n                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].name, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK), 1, fp);
		}
		else break;
	}
	fclose(fp);
	memset(dest, 0, sizeof(BOOK) * 256);
	printf("\n\n\n\n");
	printf("                                     예매를 취소하는 중입니다...                   \n");
	Sleep(1500);
	printf("\n");
	printf("                                     예매 취소가 완료되었습니다.\n");
	printf("                                    아무 키나 누르면 돌아갑니다.\n");
	_getch();
	return;
}

//회원 예매내역 조회
void check_mem() {
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
	printf("                                            예매 내역 조회\n");
	FILE* fp = fopen("D:/book_mem.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n\n");
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	BOOK_MEM book_t = { 0, };

	char id[10] = { 0, };

	printf("\n\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ ID:                           │\n");
	printf("                                 └───────────────────────────────┘\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ 비밀번호:                     │\n");
	printf("                                 └───────────────────────────────┘\n");
	gotoxy(39, 16);
	scanf(" %s", id);
	gotoxy(45, 19);
	char pass;
	char backsp = 0;
	char passwd[20] = { 0, };
	int o = 0;
	while (1) {
		rewind(stdin);
		pass = _getch();
		if (o < 20 && pass >= 48 && pass <= 57) {
			memcpy(&passwd[o], &pass, sizeof(char));
			gotoxy(45 + o, 19);
			printf("*");
			o++;
			gotoxy(45 + o, 19);
		}
		else if (o < 20 && pass >= 65 && pass <= 90) {
			memcpy(&passwd[o], &pass, sizeof(char));
			gotoxy(45 + o, 19);
			printf("*");
			o++;
			gotoxy(45 + o, 19);
		}
		else if (o < 20 && pass >= 97 && pass <= 122) {
			memcpy(&passwd[o], &pass, sizeof(char));
			gotoxy(45 + o, 19);
			printf("*");
			o++;
			gotoxy(45 + o, 19);
		}
		else if (o <= 20 && o != 0 && pass == 8) {
			memcpy(&passwd[o - 1], &backsp, sizeof(char));
			gotoxy(45 + o - 1, 19);
			printf(" ");
			o--;
			gotoxy(45 + o - 1, 19);
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
	int login_chk = 0;
	login_chk = check_ID(id, passwd);
	if (login_chk == 0) {
		printf("\n\n\n");
		printf("                            존재하지 않는 ID이거나, 비밀번호가 틀렸습니다.\n");
		printf("                                     확인 후 다시 시도해주세요.\n");
		printf("                                    아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	printf("\n\n\n");
	printf("                                       로그인에 성공했습니다.\n");
	printf("                                     예매 내역을 조회중입니다...\n");
	Sleep(2000);

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
	printf("                                          %s님의 예매 내역\n", id);
	printf("\n\n\n");

	int count = 0;
	int line2 = 0;
	while (fread(&book_t, sizeof(BOOK_MEM), 1, fp) == 1) {
		if (strcmp(id, book_t.id) == 0 && strcmp(passwd, book_t.pass) == 0) {
			gotoxy(25, 15 + line2); printf("┌──────────────────────────────────────────────────┐\n");
			gotoxy(25, 16 + line2); printf("│                  %d번째 예매 내역                 │\n", ++count);
			gotoxy(25, 17 + line2); printf("│     제목:                                        │");
			gotoxy(25, 18 + line2); printf("│     좌석:                                        │");
			gotoxy(25, 19 + line2); printf("│     결제 금액:                                   │");
			gotoxy(25, 20 + line2); printf("└──────────────────────────────────────────────────┘\n");
			gotoxy(37, 17 + line2); printf("                                       ");
			gotoxy(37, 17 + line2); printf("<%s>", book_t.movie);
			gotoxy(37, 18 + line2); printf("                                       ");
			gotoxy(37, 18 + line2); printf("%s %s %s", book_t.seat1, book_t.seat2, book_t.seat3);
			gotoxy(42, 19 + line2); printf("                     ");
			gotoxy(42, 19 + line2); printf("%d", book_t.price);
			printf("\n");
			line2 += 6;
			printf("\n");
		}
	}
	if (count == 0) {
		fclose(fp);
		printf("                                     고객님의 예매 내역이 없습니다.\n");
		printf("                                      아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	printf("\n\n");
	int i;
	printf("                            ┌─────────────┐             ┌─────────────┐\n");
	printf("                            │ 1. 돌아가기 │             │ 2. 예매 취소│\n");
	printf("                            └─────────────┘             └─────────────┘\n");
	printf("\n\n");
	printf("                                                                           기능 선택: ");
	scanf("%d", &i);
	printf("\n\n");
	while (1) {
		if (i == 1) {
			fclose(fp);
			return;
		}
		else if (i == 2) {
			int i = 0 + (count * 6);
			fclose(fp);
			char movie[40] = { 0, };
			char seat[5] = { 0, };
			printf("\n\n");
			gotoxy(0, 16 + i); printf("                               ┌────────────────────────────────────┐                          \n");
			gotoxy(0, 17 + i); printf("                               │ 취소할 영화:                       │                          \n");
			gotoxy(0, 18 + i); printf("                               └────────────────────────────────────┘                          \n");
			gotoxy(0, 19 + i); printf("                               ┌────────────────────────────────────┐                          \n");
			gotoxy(0, 20 + i); printf("                               │ 취소할 좌석:                       │                          \n");
			gotoxy(0, 21 + i); printf("                               └────────────────────────────────────┘                          \n");
			gotoxy(0, 22 + i); printf("                                                                                                   \n");
			gotoxy(0, 23 + i); printf("                        예매한 좌석이 여러개인 경우, 첫 번째 좌석을 입력하세요.                        ");
			gotoxy(0, 24 + i); printf("                                    0을 입력하면 메뉴로 돌아갑니다.                        ");
			gotoxy(46, 17 + i); scanf(" %[^\n]s", &movie);
			if (strcmp(&movie, "0") == 0) {
				return;
			}
			gotoxy(46, 20 + i); scanf(" %s", &seat);
			delete_mem(id, passwd, movie, seat);
			return;
		}
		else {
			rewind(stdin);
			gotoxy(0, 28); printf("                                                                            기능 선택:    ");
			gotoxy(0, 28); printf("                                                                            기능 선택: ");
			scanf("%d", &i);
		}
	}
	fclose(fp);
	return;
}

//회원 예매내역 삭제
void delete_mem(char* id, char* pass, char* movie, char* seat) {
	FILE* fp = fopen("d:/book_mem.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n");
		printf("\n                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}

	BOOK_MEM src = { 0, };
	static BOOK_MEM dest[256] = { 0, };
	int idx = 0;
	int found = 0;
	while (fread(&src, sizeof(BOOK_MEM), 1, fp) == 1) {
		if (strcmp(id, src.id) == 0 && strcmp(pass, src.pass) == 0 && strcmp(movie, src.movie) == 0 && strcmp(seat, src.seat1) == 0) {
			found = 1;
		}
		else {
			dest[idx++] = src;
		}
	}
	fclose(fp);

	if (found == 0) {
		printf("\n\n\n\n\n");
		printf("                                입력하신 예매 내역이 존재하지 않습니다.\n\n");
		printf("                                     아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}

	fp = fopen("d:/book_mem.txt", "wb");
	if (fp == NULL) {
		printf("\n\n\n\n");
		printf("                                 예매 내역 DB를 불러오지 못했습니다.\n");
		printf("                                      잠시 후 다시 시도해주세요.\n");
		printf("\n                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	for (int i = 0; i < 256; i++) {
		if (strcmp(dest[i].id, "") != 0) {
			fwrite(&dest[i], sizeof(BOOK_MEM), 1, fp);
		}
		else {
			break;
		}
	}
	fclose(fp);
	memset(dest, 0, sizeof(BOOK_MEM) * 256);
	printf("\n\n\n\n");
	printf("                                     예매를 취소하는 중입니다...                   \n");
	Sleep(1500);
	printf("\n");
	printf("                                     예매 취소가 완료되었습니다.\n");
	printf("                                    아무 키나 누르면 돌아갑니다.\n");
	_getch();
	return;
}