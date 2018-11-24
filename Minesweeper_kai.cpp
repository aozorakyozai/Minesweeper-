#include<stdio.h>
#include<termios.h> // または<conio.h>
#include<stdlib.h>

#define FIELD_WIDTH 9
#define FIELD_HEIGHT 9
typedef struct {
	bool bomb;
	bool mine;
	bool flag;
} PLACE;

PLACE place_now[FIELD_HEIGHT][FIELD_WIDTH];

int CursolX;
int CursolY;

int main() {
	system("cls");
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if ((x == CursolX) && (y == CursolY)) {
				printf("Ｐ");
			} else if (place_now[y][x].flag) {
				printf("Ｆ");
			} else if (place_now[y][x].mine) {
				printf("Ｍ");
			} else if (place_now[y][x].bomb) {
				printf("Ｂ");
			} else {
				printf("・");
			}
		}
		printf("\n");
	}
	switch (_getch()) {
		case 'W': 
				CursolY--;
				break;
		case 'x': 
				CursolY++;
				break;
		case 'a': 
				CursolX--;
				break;
		case 'd': 
				CursolX++;
				break;
		case 'b':
				place_now[CursolY][CursolX].bomb = !(place_now[CursolY][CursolX].bomb);
				break;
		case 'm':
				place_now[CursolY][CursolX].mine = !(place_now[CursolY][CursolX].mine);
				break;
		case 'm':
				place_now[CursolY][CursolX].flag = !(place_now[CursolY][CursolX].flag);
				break;
	}
        
}