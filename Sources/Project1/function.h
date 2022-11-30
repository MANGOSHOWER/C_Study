#ifndef __MENU_H__
#define __MENU_H__

extern void intro();

//메인 메뉴 호출
extern int main_menu();

//영화 목록 출력, 예매할 영화 선택
extern int print_List();
extern void choose_List(int count);

//좌석 선택
extern void seatselect(char* movie, int many);

//결제
extern void payment(char* movie, char seat[][5], int many);
extern void payment_mem(char* id, char* pass, char* movie, char seat[][5], int many);

//예매 내역 확인, 예매 취소
extern void checkIn(); //회원, 비회원 조회 선택
extern void check(); //비회원 조회
extern void check_mem(); //회원 조회
extern void delete_name(char* name, char* phone, char* movie, char* seat); //비회원 예매취소
extern void delete_mem(char* id, char* pass, char* movie, char* seat); //회원 예매취소

//영화 추천받기
extern void my_rec();

//장르별 검색
extern void search();

//로그인
extern void Login(char* id, char* passwd);
extern int check_ID(char* ID, char* PASSWORD);

//회원가입
extern void SignUP();
extern void SAVE_ID(LOGIN);

//종료
extern void quit();

//관리자메뉴
extern void admin_menu(); //메뉴표시&선택
extern void admin_NOW_MV_input(); //상영작 입력
extern void admin_REC_MV_input(); //추천용 DB 입력
extern void NOW_MV_del(); //상영작 삭제
extern void REC_MV_del(); //추천용 DB 삭제
extern void NOW_MV_read(); //상영작 표시
extern void REC_MV_read(); //추천용 DB 표시
extern void book_init(); //예매내역 초기화

extern void help();

#endif