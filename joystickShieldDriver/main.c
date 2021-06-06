/*
 * main.c
 *
 *  Created on: 2021. 5. 27.
 *      Author: gdabba
 */


#include <time.h>
#include "arduino.h"
#include "keypad.h"

void delay(clock_t n);

int main(void) {
	int serial_port;
	char read_buf[2];

	int event_fd = -1;
	struct input_event event_buffer[3];

	setSerial(&serial_port);
	setKeyEvent(&event_fd);

	while (1) {
		memset(&read_buf, '\0', sizeof(read_buf));
		readSerial(&serial_port,  read_buf);

		if (memcmp(read_buf, "CE", sizeof(char)*2) == 0) {
			//			printf("center\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else	if (memcmp(read_buf, "UP", sizeof(char)*2) == 0) {
			//			printf("up\n");
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_UP_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			//			make_UP_RELEASE(event_buffer);
			//			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "RU", sizeof(char)*2) == 0) {
			//			printf("right up\n");
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_UP_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "RI", sizeof(char)*2) == 0) {
			//			printf("right\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			//			make_RIGHT_RELEASE(event_buffer);
			//			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "RD", sizeof(char)*2) == 0) {
			//			printf("right down\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else	if (memcmp(read_buf, "DO", sizeof(char)*2) == 0) {
			//			printf("down\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			//			make_DOWN_RELEASE(event_buffer);
			//			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "LD", sizeof(char)*2) == 0) {
			//			printf("left down\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "LE", sizeof(char)*2) == 0) {
			//			printf("left\n");
			make_UP_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			//			make_LEFT_RELEASE(event_buffer);
			//			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "LU", sizeof(char)*2) == 0) {
			//			printf("left up\n");
			make_DOWN_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_RIGHT_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_UP_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_LEFT_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "AB", sizeof(char)*2) == 0) {
			printf("space\n");
			make_SPACE_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_SPACE_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "BB", sizeof(char)*2) == 0) {
			printf("N\n");
			make_N_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_N_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "CB", sizeof(char)*2) == 0) {
			printf("V\n");
			make_V_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_V_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "DB", sizeof(char)*2) == 0) {
			printf("B\n");
			make_B_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_B_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "EB", sizeof(char)*2) == 0) {
			printf("esc\n");
			make_ESC_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_ESC_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "FB", sizeof(char)*2) == 0) {
			printf("enter\n");
			make_ENTER_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_ENTER_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
		else if (memcmp(read_buf, "JB", sizeof(char)*2) == 0) {
			printf("bspace\n");
			make_BSPACE_PRESS(event_buffer);
			keyIn(&event_fd, event_buffer);
			make_BSPACE_RELEASE(event_buffer);
			keyIn(&event_fd, event_buffer);
		}
	}
	close(serial_port);
	close(event_fd);

}

void delay(clock_t n) {
	clock_t start = clock();
	while(clock() - start < n);
}
