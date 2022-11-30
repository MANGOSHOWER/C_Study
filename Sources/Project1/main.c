#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "struct.h"
#include "function.h"
#include "util.h"

int main() {
	SetConsoleTitle(TEXT("KB 시네마 영화 예매 시스템"));
	system("mode con cols=102");
	intro();
	Sleep(1500);
	system("cls");
	system("color 0F");
	
	while (1) {
		rewind(stdin);
		switch (main_menu()) {
		case RESERVATION:
			choose_List(print_List());
			break;
		case CHECK:
			checkIn();
			break;
		case RECOMMEND:
			my_rec();
			break;
		case GENRE_SEARCH:
			search();
			break;
		case MANAGE:
			admin_menu();
			break;
		case HELP:
			help();
			break;
		case QUIT:
			quit();
		}
		system("cls");
	}
}
