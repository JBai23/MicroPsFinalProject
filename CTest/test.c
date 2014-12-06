#include <stdio.h>

/*
int main() {
	char *arr[6];

	char word[12];
	word = "Hello";

	arr[0] = "123456789012345";
	arr[1] = "123456789012345";
	arr[2] = "123456789012345";
	arr[3] = "123456789012345";
	arr[4] = "123456789012345";
	arr[5] = "123456789012345";

	arr[0] = word;

	printf("%s", arr[0]);
}
*/

/*
typedef struct {
	struct stuff *s;
	int i;
	int x;
	int y;
} stuff;

stuff s = {.i = 1};

int main() {
	//stuff s = {.i = 1};
	// s.i = 1;
	// s.x = 2;
	// s.y = 3;

	printf("%i, %i, %i", s.i, s.x, s.y);
}
*/

#define STRSIZE 12

typedef enum {
	BTN1_I, BTN2_I, BTN3_I, BTN4_I, BTN5_I, BTN6_I, BTNA_I, BTNB_I, NON_I
} input_t;

typedef struct {
	struct menu_s *back;

	int option_count;
	
	char option_names[6][STRSIZE];
	input_t input[6];
	struct menu_s *submenu[6];
} menu_s;

menu_s fight_menu = {.option_count = 4};
// menu_s fight_menu;
// fight_menu.option_count = 4;

int main() {

}