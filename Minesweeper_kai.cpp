#include<stdio.h>
#include<termios.h> // または<conio.h>

#define FIELD_WIDTH 9
#define FIELD_HEIGHT 9
int CursolX;
int CursolY;

int main() {
	for (int y = 0; y < FIELD_HEIGHT; y++) {
		for (int x = 0; x < FIELD_WIDTH; x++) {
			if ((x == CursolX) && (y == CursolY)) {
				printf("◉");
			} else {
				printf("・");
			}
		}
		printf("\n");
	}
	_getch();
        
}