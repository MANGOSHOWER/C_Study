#ifndef __UTIL_H__
#define __UTIL_H__

//기타 유틸리티 함수
typedef enum {
	BLACK, BLUE, GREEN, CYAN, RED, PURPLE, YELLOW, WHITE, GRAY,
	LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, LIGHT_YELLOW, LIGHT_GRAY
}FONT_COLOR;
extern void gotoxy(int x, int y);
extern void fontcolor(FONT_COLOR color);

#endif