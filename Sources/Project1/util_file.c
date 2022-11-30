#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <Windows.h>
#include "struct.h"
#include "function.h"


// 로그인 아이디 저장
void SAVE_ID(LOGIN log1)
{
	FILE* fp = NULL;
	fp = fopen("d:/save_ID.txt", "ab");
	if (fp == NULL) {
		printf("파일을 생성할수가 없습니다.\n");
		return;
	}
	fwrite(&log1, sizeof(LOGIN), 1, fp);
	fclose(fp);
}

// 아이디, 패스워드 확인
int check_ID(char* ID, char* PASSWORD) {
	FILE* fp = fopen("d:/save_ID.txt", "rb");
	if (fp == NULL) {
		printf("파일을 읽을수가 없습니다.\n");
		return -1;
	}

	LOGIN IDPASS = { 0, };
	//static LOGIN dest[256] = { 0, };
	//int idx = 0;

	while (fread(&IDPASS, sizeof(LOGIN), 1, fp) == 1) {
		//memcpy(&dest[idx], &IDPASS, sizeof(LOGIN));
		// 아이디 패스워드 비교
		if (strcmp(ID, IDPASS.ID) == 0 && strcmp(PASSWORD, IDPASS.PASSWORD) == 0) {;
			fclose(fp);
			return 1;
		}
		//idx++;
	}
	fclose(fp);
	return 0;
}