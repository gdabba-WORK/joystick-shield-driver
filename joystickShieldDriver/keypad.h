/*
 * keypad.h
 *
 *  Created on: 2021. 5. 27.
 *      Author: gdabba
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

#define MAX_EVENT_BUF 3

void make_UP_PRESS(struct input_event event_buffer[3]);
void make_UP_RELEASE(struct input_event event_buffer[3]);
void make_DOWN_PRESS(struct input_event event_buffer[3]);
void make_DOWN_RELEASE(struct input_event event_buffer[3]);
void make_LEFT_PRESS(struct input_event event_buffer[3]);
void make_LEFT_RELEASE(struct input_event event_buffer[3]);
void make_RIGHT_PRESS(struct input_event event_buffer[3]);
void make_RIGHT_RELEASE(struct input_event event_buffer[3]);
void make_V_PRESS(struct input_event event_buffer[3]);
void make_V_RELEASE(struct input_event event_buffer[3]);
void make_B_PRESS(struct input_event event_buffer[3]);
void make_B_RELEASE(struct input_event event_buffer[3]);
void make_N_PRESS(struct input_event event_buffer[3]);
void make_N_RELEASE(struct input_event event_buffer[3]);
void make_ESC_PRESS(struct input_event event_buffer[3]);
void make_ESC_RELEASE(struct input_event event_buffer[3]);
void make_BSPACE_PRESS(struct input_event event_buffer[3]);
void make_BSPACE_RELEASE(struct input_event event_buffer[3]);
void make_ENTER_PRESS(struct input_event event_buffer[3]);
void make_ENTER_RELEASE(struct input_event event_buffer[3]);
void make_SPACE_PRESS(struct input_event event_buffer[3]);
void make_SPACE_RELEASE(struct input_event event_buffer[3]);
int setKeyEvent(int* event_fd);
int keyIn(int* event_fd, struct input_event[]);

static const struct input_event UP_PRESS[3] = {
		{.type=4, .code=4, .value=200},
		{.type=1, .code=103, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event UP_RELEASE[3] = {
		{.type=4, .code=4, .value=200},
		{.type=1, .code=103, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event DOWN_PRESS[3] = {
		{.type=4, .code=4, .value=208},
		{.type=1, .code=108, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event DOWN_RELEASE[3] = {
		{.type=4, .code=4, .value=208},
		{.type=1, .code=108, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event LEFT_PRESS[3] = {
		{.type=4, .code=4, .value=203},
		{.type=1, .code=105, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event LEFT_RELEASE[3] = {
		{.type=4, .code=4, .value=203},
		{.type=1, .code=105, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event RIGHT_PRESS[3] = {
		{.type=4, .code=4, .value=205},
		{.type=1, .code=106, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event RIGHT_RELEASE[3] = {
		{.type=4, .code=4, .value=205},
		{.type=1, .code=106, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event ESC_PRESS[3] = {
		{.type=4, .code=4, .value=1},
		{.type=1, .code=1, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event ESC_RELEASE[3] = {
		{.type=4, .code=4, .value=1},
		{.type=1, .code=1, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event BSPACE_PRESS[3] = {
		{.type=4, .code=4, .value=14},
		{.type=1, .code=14, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event BSPACE_RELEASE[3] = {
		{.type=4, .code=4, .value=14},
		{.type=1, .code=14, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event ENTER_PRESS[3] = {
		{.type=4, .code=4, .value=28},
		{.type=1, .code=28, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event ENTER_RELEASE[3] = {
		{.type=4, .code=4, .value=28},
		{.type=1, .code=28, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event SPACE_PRESS[3] = {
		{.type=4, .code=4, .value=57},
		{.type=1, .code=57, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event SPACE_RELEASE[3] = {
		{.type=4, .code=4, .value=57},
		{.type=1, .code=57, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event V_PRESS[3] = {
		{.type=4, .code=4, .value=47},
		{.type=1, .code=47, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event V_RELEASE[3] = {
		{.type=4, .code=4, .value=47},
		{.type=1, .code=47, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event B_PRESS[3] = {
		{.type=4, .code=4, .value=48},
		{.type=1, .code=48, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event B_RELEASE[3] = {
		{.type=4, .code=4, .value=48},
		{.type=1, .code=48, .value=0},
		{.type=0, .code=0, .value=0}
};
static const struct input_event N_PRESS[3] = {
		{.type=4, .code=4, .value=49},
		{.type=1, .code=49, .value=1},
		{.type=0, .code=0, .value=0}
};
static const struct input_event N_RELEASE[3] = {
		{.type=4, .code=4, .value=49},
		{.type=1, .code=49, .value=0},
		{.type=0, .code=0, .value=0}
};

#endif /* KEYPAD_H_ */
