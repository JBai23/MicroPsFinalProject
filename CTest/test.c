#include <stdio.h>
#include <string.h>

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

/*
typedef struct a A;
typedef struct b B;

struct a {
    B *bb;
};
struct b {
    A *aa;
};*/

/*
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
*/

// char text_buffers[241]; // interfacing with Full Screen Message
// char text_buffers_padded[241];
// int text_count;


// void strpad(char* str, char* strpad, int len) {
// 	int curr_len = strlen(str);
// 	strcpy(strpad, str);
// 	for (; curr_len < len; ++curr_len) {
// 		strcat(strpad, "*");
// 	}
// }

// void text_update() {
// 	strpad(text_buffers, text_buffers_padded, 240);

// 	char c;

// 	c = text_buffers_padded[80];
// 	text_buffers_padded[80] = '\0';
// 	printf("%s\n", text_buffers_padded);
// 	text_buffers_padded[80] = c;

// 	c = text_buffers_padded[160];
// 	text_buffers_padded[160] = '\0';
// 	printf("%s\n", text_buffers_padded + 80);
// 	text_buffers_padded[160] = c;

// 	printf("%s\n", text_buffers_padded + 160);

// 	// sendFullScreenMessage(0, text_buffers_padded);
// 	// sendFullScreenMessage(0, text_buffers_padded + 80);
// 	// sendFullScreenMessage(0, text_buffers_padded + 160);
// }

// void text_out(char* str) {
// 	if (text_count >= 240) {
// 		return;
// 	}

// 	int str_length = strlen(str);

// 	if (text_count + str_length <= 240) {
// 		strcat(text_buffers, str);
// 		text_count += str_length;
// 	} else {
// 		int remain_length = 240 - text_count;	
// 		memcpy(text_buffers + text_count, str, remain_length);
// 		text_buffers[241] = '\0';
// 		text_count = 240;
// 	}
// 	text_update();
// }

// void text_clear() {
// 	text_count = 0;
// 	strcpy(text_buffers, "");
// 	text_update();
// }

// int main() {
// 	printf("HELLO WORLD\n");
// 	text_count = 0;
// 	printf("%i\n", text_count);
// 	printf("BLEEP\n");
// 	text_out("helloworld ");
// 	text_out("pikachua ");
// 	text_out("bulbasaur ");
// 	text_out("scyther ");
// 	text_out("its super effective ");
// 	text_out("its not very effective ");
// 	text_out("more snake, hurt me more dawg ");
// 	text_out("im so fluckin' cray cray fo rizzle ");
// 	text_out("seriously, i'm getting pretty f'in pissed off ");
// 	text_out("OKAY. TIME TO SMOKE THE CIGS I KEPT IN MY ");
// 	text_out("STOMACH... AWWWWWESOME! ");
// 	text_clear();
// 	text_out("FUCK YEAH BATMAN! ");
// 	text_out("FUCK YEAH BATMAN! ");
// 	text_out("FUCK YEAH BATMAN! ");
// 	// text_out("HELLO");
// }

int main() {
	char str[32];
}