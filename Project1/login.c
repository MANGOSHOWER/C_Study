#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "function.h"
#include "struct.h"
#include "util.h"

// 가입하기
void SignUP() {
	LOGIN LOG = { 0, };
	LOGIN LOG2 = { 0, };
	char id[20] = { 0, };
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
	printf("                                              회원 가입\n");
	printf("\n\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ ID:                           │\n");
	printf("                                 └───────────────────────────────┘\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ 비밀번호:                     │\n");
	printf("                                 └───────────────────────────────┘\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ E-Mail:                       │\n");
	printf("                                 └───────────────────────────────┘\n");
	printf("                                 ┌───────────────────────────────┐\n");
	printf("                                 │ 전화번호:                     │\n");
	printf("                                 └───────────────────────────────┘\n");
	gotoxy(39, 16);
	scanf(" %s", id);
	FILE* fp = fopen("D:/save_ID.txt", "rb");
	if (fp != NULL) {
		while (fread(&LOG, sizeof(LOG), 1, fp) == 1) {
			while (strcmp(id, LOG.ID) == 0) {
				gotoxy(39, 16); printf("이미 존재하는 ID입니다.");
				Sleep(1000);
				gotoxy(39, 16); printf("                         ");
				gotoxy(39, 16); scanf(" %s", id);
			}
		}
	}
	else if (fp == NULL) {
		fp = fopen("D:/save_ID.txt", "wb");
	}
	fclose(fp);
	
	strcpy(&LOG2.ID, &id);
	gotoxy(45, 19);

	//비밀번호 입력하면 별표로 뜨게 하기
	char pass; //한글자씩 입력받을 변수
	char backsp = 0; //백스페이스 입력시 덮어씌울 null값
	char passwd[20] = { 0, }; //입력한 글자 저장될 문자열
	int i = 0; //몇번째 글자인지
	while (1) {
		rewind(stdin);
		pass = _getch(); //_getch로 엔터키 필요없이 바로바로 한글자씩 입력받음
		if (i < 20 && pass >= 48 && pass <= 57) { //입력한 글자가 숫자인 경우
			memcpy(&passwd[i], &pass, sizeof(char)); //i번째 글자에 입력한 글자 저장
			gotoxy(45 + i, 19); //i번째 글자로 커서 이동해서
			printf("*"); //별표 출력
			i++;
			gotoxy(45 + i, 19); //다음칸으로 커서 이동
		}
		else if (i < 20 && pass >= 65 && pass <= 90) { //영대문자인 경우
			memcpy(&passwd[i], &pass, sizeof(char));
			gotoxy(45 + i, 19);
			printf("*");
			i++;
			gotoxy(45 + i, 19);
		}
		else if (i < 20 && pass >= 97 && pass <= 122) { //영소문자인 경우
			memcpy(&passwd[i], &pass, sizeof(char));
			gotoxy(45 + i, 19);
			printf("*");
			i++;
			gotoxy(45 + i, 19);
		}
		else if (i <= 20 && i != 0 && pass == 8) { //백스페이스인 경우
			memcpy(&passwd[i - 1], &backsp, sizeof(char)); //이전에 입력한 글자 null로 덮어씌움
			gotoxy(45 + i - 1, 19); //이전 커서로 이동해서
			printf(" "); //공백으로 채우고
			i--;
			gotoxy(45 + i - 1, 19); //다시 이전 커서로 이동해 입력대기
		}
		else if (pass == -32) { //방향키 입력하는 경우
			_getch();
			rewind(stdin);
			continue;
		}
		else if (pass == 13) { //엔터키인 경우
			break; //반복문 탈출
		}
	}
	strcpy(&LOG2.PASSWORD, &passwd);
	gotoxy(43, 22);
	scanf(" %s", &LOG2.EMAIL);
	gotoxy(45, 25);
	scanf(" %s", &LOG2.PHONE);

	SAVE_ID(LOG2);
	printf("\n\n\n");
	printf("                                    회원가입이 완료되었습니다.\n");
	printf("                                   아무 키나 누르면 돌아갑니다.\n");
	_getch();
}

// 로그인 하기
void Login(char* id, char* passwd) {
	int login_chk = 0;
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
		printf("                                    ┌─────────────────────────┐\n");
		printf("                                    │        1. 로그인        │\n");
		printf("                                    └─────────────────────────┘\n");
		printf("                                    ┌─────────────────────────┐\n");
		printf("                                    │       2. 회원가입       │\n");
		printf("                                    └─────────────────────────┘\n");
		printf("                                    ┌─────────────────────────┐\n");
		printf("                                    │      3. 비회원 예매     │\n");
		printf("                                    └─────────────────────────┘\n");
		printf("\n\n");
		printf("                                                                            기능 선택: ");
		int logNum = 0;
		scanf("%d", &logNum);
		while (1) {
			if (logNum == 1) {
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
				printf("                                               로그인\n");
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
				char passwd2[20] = { 0, };
				int i = 0;
				while(1){
					rewind(stdin);
					pass = _getch();
					if (i<20 && pass >= 48 && pass <= 57) {
						memcpy(&passwd2[i], &pass, sizeof(char));
						gotoxy(45 + i, 19);
						printf("*");
						i++;
						gotoxy(45 + i, 19);
					}
					else if (i < 20 && pass >= 65 && pass <= 90) {
						memcpy(&passwd2[i], &pass, sizeof(char));
						gotoxy(45 + i, 19);
						printf("*");
						i++;
						gotoxy(45 + i, 19);
					}
					else if (i < 20 && pass >= 97 && pass <= 122) {
						memcpy(&passwd2[i], &pass, sizeof(char));
						gotoxy(45 + i, 19);
						printf("*");
						i++;
						gotoxy(45 + i, 19);
					}
					else if (i <= 20 && i!= 0 && pass == 8) {
						memcpy(&passwd2[i-1], &backsp, sizeof(char));
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
					strcpy(passwd, passwd2);
				}
				login_chk = check_ID(id, passwd);
				if (login_chk == 1) {
					// 로그인 성공 - 로그인 이후 창
					printf("\n\n\n");
					printf("                                       로그인에 성공했습니다.\n");
					printf("                                계속 진행하시려면 아무 키나 누르세요.\n");
					_getch();
					return;
				}
				else {
					// 로그인 실패 - 처음 화면으로
					printf("\n\n\n");
					printf("                            존재하지 않는 ID이거나, 비밀번호가 틀렸습니다.\n");
					printf("                                     확인 후 다시 시도해주세요.\n");
					printf("                                    아무 키나 누르면 돌아갑니다.\n");
					_getch();
					break;
				}
			}
			else if (logNum == 2)
			{
				// 회원 가입
				SignUP();
				break;
			}
			else if (logNum == 3) {
				strcpy(id, "");
				return;
			}
			else {
				gotoxy(0, 23);
				printf("                                                                            기능 선택:     ");
				gotoxy(0, 23);
				printf("                                                                            기능 선택: ");
				rewind(stdin);
				scanf("%d", &logNum);
			}
		}
	}
}