#include<stdio.h>
#include<conio.h>  // Macなら　<termios.h> 
#include<stdlib.h>　
#include<time.h>

#define FIELD_WIDTH 9
#define FIELD_HEIGHT 9

#define BOMB_COUNT 10
typedef struct {
	bool bomb;
	bool mine;
	bool flag;
} PLACE;

PLACE place_now[FIELD_HEIGHT][FIELD_WIDTH];

int CursolX;
int CursolY;

int getBomsCount(int, int);

int main() {
	srand(time(NULL));
	int n = 0;
	do {
		int x = rand() % FIELD_WIDTH;
		int y = rand() % FIELD_HEIGHT;
		if (!place_now[x][y].bomb) {
			place_now[y][x].bomb = true;
			n++;
		}
	} while (n < BOMB_COUNT);

	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			place_now[y][x].mine = true;
		}
	}
	system("cls");
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if ((x == CursolX) && (y == CursolY)) {
				printf("◯");
			} else if (place_now[y][x].flag) {
				printf("Ｆ");
			} else if (place_now[y][x].mine) {
				printf("Ｍ");
			} else if (place_now[y][x].bomb) {
				printf("Ｂ");
			} else {
				int num = getBomsCount(x, y);
				if (num = 0) {
					printf("□");
				} else {
					char str[] = "０";
					str[1] += num;
					printf("%s", str);
				}
				
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
		case 'f':
				place_now[CursolY][CursolX].flag = !(place_now[CursolY][CursolX].flag);
				break;
		default:
				place_now[y][x].mine = false;
				break;
	}     
}

int getBomsCount(int _x, int _y) {
	int num = 0;
	for (int y = -1; y <= 1; y++) {
		for (int x = -1; x <= 1; x++) {
			if ((x == 0) && (y == 0)) {
				continue;
			}
			int x2 = _x + x;
			int y2 = _y + y;

			if ((x2 >= 0) || (x2 < FIELD_WIDTH) || (y2 >= 0) || (y2 < FIELD_HEIGHT)) {
				if (place_now[y2][x2].bomb) {
					num++;
				}
			}
			
		}
	}
	return num;
}