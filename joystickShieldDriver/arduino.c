/*
 * arduino.c
 *
 *  Created on: 2021. 5. 27.
 *      Author: gdabba
 */



#include "arduino.h"

int setSerial(int *serial_port) {
	*serial_port = open("/dev/ttyACM0", O_RDWR);

	struct termios tty;

	if(tcgetattr(*serial_port, &tty) != 0) {
		printf("Error %i from tcgetattr: %s\n", errno, strerror(errno));
		return 1;
	}

	tty.c_cflag &= ~PARENB;
	tty.c_cflag &= ~CSTOPB;
	tty.c_cflag &= ~CSIZE;
	tty.c_cflag |= CS8;
	tty.c_cflag &= ~CRTSCTS;
	tty.c_cflag |= CREAD | CLOCAL;

	tty.c_lflag &= ~ICANON;
	tty.c_lflag &= ~ECHO;
	tty.c_lflag &= ~ECHOE;
	tty.c_lflag &= ~ECHONL;
	tty.c_lflag &= ~ISIG;
	tty.c_iflag &= ~(IXON | IXOFF | IXANY);
	tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL);

	tty.c_oflag &= ~OPOST;
	tty.c_oflag &= ~ONLCR;

	tty.c_cc[VTIME] = 10;
	tty.c_cc[VMIN] = 0;


	cfsetispeed(&tty, B9600);
	cfsetospeed(&tty, B9600);


	if (tcsetattr(*serial_port, TCSANOW, &tty) != 0) {
		printf("Error %i from tcsetattr: %s\n", errno, strerror(errno));
		return 1;
	}
	return 0;
}

int readSerial(int *serial_port, char read_buf[]) {
	int num_bytes = read(*(serial_port), read_buf, sizeof(char)*16);
	if (num_bytes < 0) {
		printf("Error reading: %s\n", strerror(errno));
		return 1;
	}

	return 0;
}
