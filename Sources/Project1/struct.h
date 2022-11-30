#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct _BOOK { //비회원 예매내역 저장용, 좌석유무 확인용
	char name[20];
	char phone[20];
	char movie[40];
	char seat1[5];
	char seat2[5];
	char seat3[5];
	int price;
} BOOK;

typedef struct _BOOK_MEM { //회원 예매내역 저장용
	char id[20];
	char pass[20];
	char movie[40];
	char seat1[5];
	char seat2[5];
	char seat3[5];
	int price;
} BOOK_MEM;

typedef struct _NOWMOVIE { //현재상영작
	char name[40];
	char genre[20];
} NOW;

typedef struct _RECOMMEND { //영화추천 DB 저장용
	char name[40];
	char genre[20];
	char director[30];
	char actor[60];
} RECOM;

typedef struct _MEMBER {
	char id[20];
	char password[20];
} MEMBER;

typedef struct _LOGIN {
	char ID[20];		// ID 입력
	char PHONE[20];		// 전화번호 입력
	char EMAIL[40];		// 이메일 입력
	char PASSWORD[40];	// 비밀번호 입력
} LOGIN;

typedef enum {
	HELP = 0,
	RESERVATION = 1,
	CHECK,
	RECOMMEND,
	GENRE_SEARCH,
	MANAGE,
	QUIT
}menu_select;

#endif