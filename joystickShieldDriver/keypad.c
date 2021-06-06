/*
 * keypad.c
 *
 *  Created on: 2021. 5. 27.
 *      Author: gdabba
 */


# include "keypad.h"

void make_UP_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = UP_PRESS[0];
	event_buffer[1] = UP_PRESS[1];
	event_buffer[2] = UP_PRESS[2];
}
void make_UP_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = UP_RELEASE[0];
	event_buffer[1] = UP_RELEASE[1];
	event_buffer[2] = UP_RELEASE[2];
}
void make_DOWN_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = DOWN_PRESS[0];
		event_buffer[1] = DOWN_PRESS[1];
		event_buffer[2] = DOWN_PRESS[2];
}
void make_DOWN_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = DOWN_RELEASE[0];
		event_buffer[1] = DOWN_RELEASE[1];
		event_buffer[2] = DOWN_RELEASE[2];
}
void make_LEFT_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = LEFT_PRESS[0];
		event_buffer[1] = LEFT_PRESS[1];
		event_buffer[2] = LEFT_PRESS[2];
}
void make_LEFT_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = LEFT_RELEASE[0];
		event_buffer[1] = LEFT_RELEASE[1];
		event_buffer[2] = LEFT_RELEASE[2];
}
void make_RIGHT_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = RIGHT_PRESS[0];
		event_buffer[1] = RIGHT_PRESS[1];
		event_buffer[2] = RIGHT_PRESS[2];
}
void make_RIGHT_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = RIGHT_RELEASE[0];
		event_buffer[1] = RIGHT_RELEASE[1];
		event_buffer[2] = RIGHT_RELEASE[2];
}
void make_ESC_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = ESC_PRESS[0];
		event_buffer[1] = ESC_PRESS[1];
		event_buffer[2] = ESC_PRESS[2];
}
void make_ESC_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = ESC_RELEASE[0];
		event_buffer[1] = ESC_RELEASE[1];
		event_buffer[2] = ESC_RELEASE[2];
}
void make_ENTER_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = ENTER_PRESS[0];
		event_buffer[1] = ENTER_PRESS[1];
		event_buffer[2] = ENTER_PRESS[2];
}
void make_ENTER_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = ENTER_RELEASE[0];
		event_buffer[1] = ENTER_RELEASE[1];
		event_buffer[2] = ENTER_RELEASE[2];
}
void make_SPACE_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = SPACE_PRESS[0];
		event_buffer[1] = SPACE_PRESS[1];
		event_buffer[2] = SPACE_PRESS[2];
}
void make_SPACE_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = SPACE_RELEASE[0];
		event_buffer[1] = SPACE_RELEASE[1];
		event_buffer[2] = SPACE_RELEASE[2];
}
void make_BSPACE_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = BSPACE_PRESS[0];
		event_buffer[1] = BSPACE_PRESS[1];
		event_buffer[2] = BSPACE_PRESS[2];
}
void make_BSPACE_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = BSPACE_RELEASE[0];
		event_buffer[1] = BSPACE_RELEASE[1];
		event_buffer[2] = BSPACE_RELEASE[2];
}
void make_V_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = V_PRESS[0];
		event_buffer[1] = V_PRESS[1];
		event_buffer[2] = V_PRESS[2];
}
void make_V_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = V_RELEASE[0];
		event_buffer[1] = V_RELEASE[1];
		event_buffer[2] = V_RELEASE[2];
}
void make_B_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = B_PRESS[0];
		event_buffer[1] = B_PRESS[1];
		event_buffer[2] = B_PRESS[2];
}
void make_B_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = B_RELEASE[0];
		event_buffer[1] = B_RELEASE[1];
		event_buffer[2] = B_RELEASE[2];
}
void make_N_PRESS(struct input_event event_buffer[3]){
	event_buffer[0] = N_PRESS[0];
		event_buffer[1] = N_PRESS[1];
		event_buffer[2] = N_PRESS[2];
}
void make_N_RELEASE(struct input_event event_buffer[3]){
	event_buffer[0] = N_RELEASE[0];
		event_buffer[1] = N_RELEASE[1];
		event_buffer[2] = N_RELEASE[2];
}

int setKeyEvent(int* event_fd) {
	char* device = "/dev/input/event2"; // argument로 받을 예정

	if ((*event_fd = open(device, O_WRONLY)) < 0) {
		printf("%s: open error\n", device);
		return 1;
	}
	return 0;
}

int keyIn(int* event_fd, struct input_event button[]) {
	size_t write_bytes;

	write_bytes = write(*event_fd, button, sizeof(struct input_event)*MAX_EVENT_BUF);
//	printf("write_bytes=%lu\n", write_bytes);
	if( write_bytes < sizeof(struct input_event) )
	{
		printf("write error");
		return 1;
	}
	return 0;
}
