#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "struct.h"
#include "util.h"
#include "function.h"

//¿¹¸Å ³»¿ª ·Î±×ÀÎ, ºñÈ¸¿ø ¼±ÅÃ
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
	printf("                                            ¿¹¸Å ³»¿ª Á¶È¸\n");
	printf("\n\n");
	printf("                                    ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                    ¦¢        1. ·Î±×ÀÎ        ¦¢\n");
	printf("                                    ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("                                    ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                    ¦¢      2. ºñÈ¸¿ø Á¶È¸     ¦¢\n");
	printf("                                    ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("\n\n");
	printf("                                                          ±â´É ¼±ÅÃ (0À¸·Î µ¹¾Æ°¡±â): ");
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
			printf("                                                          ±â´É ¼±ÅÃ (0À¸·Î µ¹¾Æ°¡±â):  ");
			rewind(stdin);
			gotoxy(86, 23);
		}
	}
	return;
}

//ºñÈ¸¿ø ¿¹¸Å³»¿ª Á¶È¸
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
	printf("                                           ¿¹¸Å ³»¿ª Á¶È¸\n");
	FILE* fp = fopen("D:/book.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n\n");
		printf("                                     ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}
	BOOK book_t = { 0, };

	char name[10] = { 0, };
	char phone[20] = { 0, };

	printf("\n\n");
	printf("                                    ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                    ¦¢ ¿¹¸ÅÀÚ¸í:               ¦¢\n");
	printf("                                    ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("                                    ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                    ¦¢ ÀüÈ­¹øÈ£:               ¦¢\n");
	printf("                                    ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	gotoxy(48, 16); scanf(" %s", &name);
	gotoxy(48, 19); scanf(" %s", &phone);
	printf("\n\n\n");
	printf("                                     ¿¹¸Å ³»¿ªÀ» Á¶È¸ÁßÀÔ´Ï´Ù...\n");
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
	printf("                                          %s´ÔÀÇ ¿¹¸Å ³»¿ª\n", name);
	printf("\n\n\n");

	int count = 0;
	int line1 = 0;
	while (fread(&book_t, sizeof(book_t), 1, fp) == 1) {
		if (strcmp(name, book_t.name) == 0 && strcmp(phone, book_t.phone) == 0) {
			gotoxy(25, 15 + line1); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
			gotoxy(25, 16 + line1); printf("¦¢                    ¹øÂ° ¿¹¸Å ³»¿ª                ¦¢\n");
			gotoxy(44, 16 + line1); printf("%d", ++count);
			gotoxy(25, 17 + line1); printf("¦¢     Á¦¸ñ:                                        ¦¢");
			gotoxy(25, 18 + line1); printf("¦¢     ÁÂ¼®:                                        ¦¢");
			gotoxy(25, 19 + line1); printf("¦¢     °áÁ¦ ±Ý¾×:                                   ¦¢");
			gotoxy(25, 20 + line1); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
		printf("                                     °í°´´ÔÀÇ ¿¹¸Å ³»¿ªÀÌ ¾ø½À´Ï´Ù.\n");
		printf("                                      ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}
	printf("\n\n");
	int i;
	gotoxy(0, 19 + line1 - 2); printf("                            ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤             ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	gotoxy(0, 20 + line1 - 2); printf("                            ¦¢ 1. µ¹¾Æ°¡±â ¦¢             ¦¢ 2. ¿¹¸Å Ãë¼Ò¦¢\n");
	gotoxy(0, 21 + line1 - 2); printf("                            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥             ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("\n\n");
	gotoxy(0, 23 + line1 - 2); printf("                                                                            ±â´É ¼±ÅÃ: ");
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
			gotoxy(0, 16 + i); printf("                               ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                          \n");
			gotoxy(0, 17 + i); printf("                               ¦¢ Ãë¼ÒÇÒ ¿µÈ­:                       ¦¢                          \n");
			gotoxy(0, 18 + i); printf("                               ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                          \n");
			gotoxy(0, 19 + i); printf("                               ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                          \n");
			gotoxy(0, 20 + i); printf("                               ¦¢ Ãë¼ÒÇÒ ÁÂ¼®:                       ¦¢                          \n");
			gotoxy(0, 21 + i); printf("                               ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                          \n");
			gotoxy(0, 22 + i); printf("                                                                                                   \n");
			gotoxy(0, 23 + i); printf("                        ¿¹¸ÅÇÑ ÁÂ¼®ÀÌ ¿©·¯°³ÀÎ °æ¿ì, Ã¹ ¹øÂ° ÁÂ¼®À» ÀÔ·ÂÇÏ¼¼¿ä.                        ");
			gotoxy(0, 24 + i); printf("                            0À» ÀÔ·ÂÇÏ¸é ÀÛ¾÷À» Ãë¼ÒÇÏ°í ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.                        ");
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
			gotoxy(0, 23 + line1 - 2); printf("                                                                            ±â´É ¼±ÅÃ:    ");
			gotoxy(0, 23 + line1 - 2); printf("                                                                            ±â´É ¼±ÅÃ: ");
			scanf("%d", &i);
		}
	}
	fclose(fp);
	return;
}

//ºñÈ¸¿ø ¿¹¸Å ³»¿ª »èÁ¦
void delete_name(char* name, char* phone, char* movie, char* seat) {
	FILE* fp = fopen("d:/book.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
		printf("\n                                   ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
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
		printf("                                ÀÔ·ÂÇÏ½Å ¿¹¸Å ³»¿ªÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n");
		printf("                                     ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}

	fp = fopen("d:/book.txt", "wb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
		printf("\n                                   ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
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
	printf("                                     ¿¹¸Å¸¦ Ãë¼ÒÇÏ´Â ÁßÀÔ´Ï´Ù...                   \n");
	Sleep(1500);
	printf("\n");
	printf("                                     ¿¹¸Å Ãë¼Ò°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
	printf("                                    ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
	_getch();
	return;
}

//È¸¿ø ¿¹¸Å³»¿ª Á¶È¸
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
	printf("                                            ¿¹¸Å ³»¿ª Á¶È¸\n");
	FILE* fp = fopen("D:/book_mem.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n\n");
		printf("                                     ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}
	BOOK_MEM book_t = { 0, };

	char id[10] = { 0, };

	printf("\n\n");
	printf("                                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                 ¦¢ ID:                           ¦¢\n");
	printf("                                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("                                 ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                                 ¦¢ ºñ¹Ð¹øÈ£:                     ¦¢\n");
	printf("                                 ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
		printf("                            Á¸ÀçÇÏÁö ¾Ê´Â IDÀÌ°Å³ª, ºñ¹Ð¹øÈ£°¡ Æ²·È½À´Ï´Ù.\n");
		printf("                                     È®ÀÎ ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
		printf("                                    ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}
	printf("\n\n\n");
	printf("                                       ·Î±×ÀÎ¿¡ ¼º°øÇß½À´Ï´Ù.\n");
	printf("                                     ¿¹¸Å ³»¿ªÀ» Á¶È¸ÁßÀÔ´Ï´Ù...\n");
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
	printf("                                          %s´ÔÀÇ ¿¹¸Å ³»¿ª\n", id);
	printf("\n\n\n");

	int count = 0;
	int line2 = 0;
	while (fread(&book_t, sizeof(BOOK_MEM), 1, fp) == 1) {
		if (strcmp(id, book_t.id) == 0 && strcmp(passwd, book_t.pass) == 0) {
			gotoxy(25, 15 + line2); printf("¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
			gotoxy(25, 16 + line2); printf("¦¢                  %d¹øÂ° ¿¹¸Å ³»¿ª                 ¦¢\n", ++count);
			gotoxy(25, 17 + line2); printf("¦¢     Á¦¸ñ:                                        ¦¢");
			gotoxy(25, 18 + line2); printf("¦¢     ÁÂ¼®:                                        ¦¢");
			gotoxy(25, 19 + line2); printf("¦¢     °áÁ¦ ±Ý¾×:                                   ¦¢");
			gotoxy(25, 20 + line2); printf("¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
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
		printf("                                     °í°´´ÔÀÇ ¿¹¸Å ³»¿ªÀÌ ¾ø½À´Ï´Ù.\n");
		printf("                                      ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}
	printf("\n\n");
	int i;
	printf("                            ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤             ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤\n");
	printf("                            ¦¢ 1. µ¹¾Æ°¡±â ¦¢             ¦¢ 2. ¿¹¸Å Ãë¼Ò¦¢\n");
	printf("                            ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥             ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥\n");
	printf("\n\n");
	printf("                                                                           ±â´É ¼±ÅÃ: ");
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
			gotoxy(0, 16 + i); printf("                               ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                          \n");
			gotoxy(0, 17 + i); printf("                               ¦¢ Ãë¼ÒÇÒ ¿µÈ­:                       ¦¢                          \n");
			gotoxy(0, 18 + i); printf("                               ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                          \n");
			gotoxy(0, 19 + i); printf("                               ¦£¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¤                          \n");
			gotoxy(0, 20 + i); printf("                               ¦¢ Ãë¼ÒÇÒ ÁÂ¼®:                       ¦¢                          \n");
			gotoxy(0, 21 + i); printf("                               ¦¦¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¥                          \n");
			gotoxy(0, 22 + i); printf("                                                                                                   \n");
			gotoxy(0, 23 + i); printf("                        ¿¹¸ÅÇÑ ÁÂ¼®ÀÌ ¿©·¯°³ÀÎ °æ¿ì, Ã¹ ¹øÂ° ÁÂ¼®À» ÀÔ·ÂÇÏ¼¼¿ä.                        ");
			gotoxy(0, 24 + i); printf("                                    0À» ÀÔ·ÂÇÏ¸é ¸Þ´º·Î µ¹¾Æ°©´Ï´Ù.                        ");
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
			gotoxy(0, 28); printf("                                                                            ±â´É ¼±ÅÃ:    ");
			gotoxy(0, 28); printf("                                                                            ±â´É ¼±ÅÃ: ");
			scanf("%d", &i);
		}
	}
	fclose(fp);
	return;
}

//È¸¿ø ¿¹¸Å³»¿ª »èÁ¦
void delete_mem(char* id, char* pass, char* movie, char* seat) {
	FILE* fp = fopen("d:/book_mem.txt", "rb");
	if (fp == NULL) {
		printf("\n\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
		printf("\n                                   ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
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
		printf("                                ÀÔ·ÂÇÏ½Å ¿¹¸Å ³»¿ªÀÌ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.\n\n");
		printf("                                     ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
		_getch();
		return;
	}

	fp = fopen("d:/book_mem.txt", "wb");
	if (fp == NULL) {
		printf("\n\n\n\n");
		printf("                                 ¿¹¸Å ³»¿ª DB¸¦ ºÒ·¯¿ÀÁö ¸øÇß½À´Ï´Ù.\n");
		printf("                                      Àá½Ã ÈÄ ´Ù½Ã ½ÃµµÇØÁÖ¼¼¿ä.\n");
		printf("\n                                   ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
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
	printf("                                     ¿¹¸Å¸¦ Ãë¼ÒÇÏ´Â ÁßÀÔ´Ï´Ù...                   \n");
	Sleep(1500);
	printf("\n");
	printf("                                     ¿¹¸Å Ãë¼Ò°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù.\n");
	printf("                                    ¾Æ¹« Å°³ª ´©¸£¸é µ¹¾Æ°©´Ï´Ù.\n");
	_getch();
	return;
}