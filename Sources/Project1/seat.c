#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "function.h"
#include "struct.h"
#include "util.h"
#define ANSI_COLOR_RED      "\x1b[31m"
#define ANSI_COLOR_GREEN     "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_RESET    "\x1b[0m"


void seatselect(char* movie, int many) {
	system("cls");
	int book[6][10] = { 0 };
	char title[40] = { 0, };
	char id[20] = { 0, };
	char passwd[20] = { 0, };

	strcpy(title, movie);
	BOOK book2 = { 0, };
	BOOK_MEM book3 = { 0, };
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
	printf("                                              S C R E E N\n");
	printf("──────────────────────────────────────────────────────────────────────────────────────────────────────\n");

	char seat[5] = { 0, };
	char seat2[5] = { 0, };
	char seat3[5] = { 0, };
	
	FILE* fp = fopen("D:/book.txt", "rb"); //파일 열어서 예매된 좌석 있나 조회하고 있으면 배열의 변수 1로 바꿈
	if (fp != NULL) {
		while (fread(&book2, sizeof(book2), 1, fp) == 1) {
			int i, j;
			strcpy(seat, book2.seat1);
			if (seat[2] == NULL && strcmp(movie, book2.movie) == 0) {
				i = (int)seat[0] - 65;
				j = (int)seat[1] - 49;
				book[i][j] = 1;
			}
			else if (seat[1] == '1' && seat[2] == '0' && strcmp(movie, book2.movie) == 0) {
				i = (int)seat[0] - 65;
				j = 9;
				book[i][j] = 1;
			}
			if (book2.seat2[0] != NULL) {
				strcpy(seat2, book2.seat2);
				if (seat2[2] == NULL && strcmp(movie, book2.movie) == 0) {
					i = (int)seat2[0] - 65;
					j = (int)seat2[1] - 49;
					book[i][j] = 1;
				}
				else if (seat2[1] == '1' && seat2[2] == '0' && strcmp(movie, book2.movie) == 0) {
					i = (int)seat2[0] - 65;
					j = 9;
					book[i][j] = 1;
				}
			}
			if (book2.seat3[0] != NULL) {
				strcpy(seat3, book2.seat3);
				if (seat3[2] == NULL && strcmp(movie, book2.movie) == 0) {
					i = (int)seat3[0] - 65;
					j = (int)seat3[1] - 49;
					book[i][j] = 1;
				}
				else if (seat3[1] == '1' && seat3[2] == '0' && strcmp(movie, book2.movie) == 0) {
					i = (int)seat3[0] - 65;
					j = 9;
					book[i][j] = 1;
				}
			}
		}
		fclose(fp);
	}
	else if (fp == NULL) {	}

	fp = fopen("D:/book_mem.txt", "rb"); //파일 열어서 예매된 좌석 있나 조회하고 있으면 배열의 변수 1로 바꿈
	if (fp != NULL) {
		while (fread(&book3, sizeof(book3), 1, fp) == 1) {
			int i, j;
			strcpy(seat, book3.seat1);
			if (seat[2] == NULL && strcmp(movie, book3.movie) == 0) {
				i = (int)seat[0] - 65;
				j = (int)seat[1] - 49;
				book[i][j] = 1;
			}
			else if (seat[1] == '1' && seat[2] == '0' && strcmp(movie, book3.movie) == 0) {
				i = (int)seat[0] - 65;
				j = 9;
				book[i][j] = 1;
			}
			if (book3.seat2[0] != NULL) {
				strcpy(seat2, book3.seat2);
				if (seat2[2] == NULL && strcmp(movie, book3.movie) == 0) {
					i = (int)seat2[0] - 65;
					j = (int)seat2[1] - 49;
					book[i][j] = 1;
				}
				else if (seat2[1] == '1' && seat2[2] == '0' && strcmp(movie, book3.movie) == 0) {
					i = (int)seat2[0] - 65;
					j = 9;
					book[i][j] = 1;
				}
			}
			if (book3.seat3[0] != NULL) {
				strcpy(seat3, book3.seat3);
				if (seat3[2] == NULL && strcmp(movie, book3.movie) == 0) {
					i = (int)seat3[0] - 65;
					j = (int)seat3[1] - 49;
					book[i][j] = 1;
				}
				else if (seat3[1] == '1' && seat3[2] == '0' && strcmp(movie, book3.movie) == 0) {
					i = (int)seat3[0] - 65;
					j = 9;
					book[i][j] = 1;
				}
			}
		}
		fclose(fp);
	}
	else if (fp == NULL) {}

	int count = 0;

	for (int i = 0; i < 6; i++) { //좌석 예매 현황 출력(0=이용가능, 1=예약완료)
		printf("\n         1        2        3        4        5        6        7        8        9        10\n");
		printf("   ");
		printf("%c ", 65 + i);
		for (int j = 0; j < 10; j++) {
			if (book[i][j] == 0) {
				printf(" 이용가능");
			}
			else if (book[i][j] == 1) {
				printf(ANSI_COLOR_YELLOW " 이용불가" ANSI_COLOR_RESET);
				count++;
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("──────────────────────────────────────────────────────────────────────────────────────────────────────\n");
	if (count == 60) {
		gotoxy(0, 33);
		printf("                                                                 선택하신 영화는 매진되었습니다.\n");
		gotoxy(0, 34);
		printf("                                                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	else if (many > (60 - count)) {
		gotoxy(0, 33);
		printf("                                                      입력하신 인원 수가 남은 자리보다 많습니다.\n");
		gotoxy(0, 34);
		printf("                                                                   아무 키나 누르면 돌아갑니다.\n");
		_getch();
		return;
	}
	char seatwant[4][5] = { 0, };
	gotoxy(0, 33);
	printf("                                                              선택한 영화: %s\n", movie);
	int x = 0, y = 34;
	int arr = 3, col = 9;
	for (int i = 0; i < many; i++) {
		memset(&seatwant[i], NULL, sizeof(char) * 5);
		int a = 0, b = 0;
		gotoxy(x, y);
		printf("                                                              %d번째 좌석 선택:                       ", i+1);
		gotoxy(x+79, y);
		y += 1;
		scanf(" %s", seatwant[i]);
		if (seatwant[i][0] < 65 || seatwant[i][0] > 70) { //좌석번호 첫째글자가 A~F가 아닐때
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (seatwant[i][1] > 49 && seatwant[i][2] != NULL) { //좌석번호 숫자가 20 이상일때
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (seatwant[i][1] >= 49 && seatwant[i][2] != NULL && seatwant[i][2] != 48) { //좌석번호 숫자가 11 이상일때
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (seatwant[i][3] != NULL || seatwant[i][4] != NULL) { //좌석번호 숫자가 세자리수 이상일때
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (seatwant[i][1] <= 48 || seatwant[i][1]>57) { // 특수 문자 입력시
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (strcmp(seatwant[i], seatwant[i - 1]) == 0 || strcmp(seatwant[i], seatwant[i-2])==0) { //고른 자리 또 고르면
			printf("\n");
			gotoxy(x + 79, y - 1);
			printf("잘못 입력하셨습니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		else if (seatwant[i][2] == NULL) { //좌석번호 숫자가 10번일때
			a = (int)seatwant[i][0] - 65;
			b = (int)seatwant[i][1] - 49;
		}
		else if (seatwant[i][1] == '1' && seatwant[i][2] == '0') { //좌석번호 숫자가 10번일때
			a = (int)seatwant[i][0] - 65;
			b = 9;
		}
		if (book[a][b] == 1) {
			printf("\n");
			gotoxy(x + 79, y-1); 
			printf("예약된 좌석입니다.");
			Sleep(1000);
			i--; y--;
			continue;
		}
		int difarr = (int)seatwant[i][0] - 65;
		int difcol = 0;
		if (seatwant[i][1] == '1' && seatwant[i][2] == '0') {
			difcol = 9;                                                           
		}
		else{
			difcol = (int)seatwant[i][1] - 49;
		}
		gotoxy(6 + col * difcol, 14 + arr*difarr);
		printf(ANSI_COLOR_GREEN "선택완료" ANSI_COLOR_RESET);
	}
	gotoxy(0, 38);
	printf("                                                              좌석 선택이 완료되었습니다.\n");
	printf("                                                              진행하시려면 아무 키나 누르세요.\n");
	_getch();

	// 로그인 추가
	Login(id, passwd);

	if (id[0] == NULL)
	{
		payment(title, &seatwant, many);
	}
	else
	{
		payment_mem(id, passwd, title, &seatwant, many);
	}	
}
