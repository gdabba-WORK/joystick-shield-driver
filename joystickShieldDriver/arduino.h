/*
 * arduino.h
 *
 *  Created on: 2021. 5. 27.
 *      Author: gdabba
 */

#ifndef ARDUINO_H_
#define ARDUINO_H_

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <unistd.h>

int setSerial(int *serial_port);
int readSerial(int *serial_port, char read_buf[256]);

#endif /* ARDUINO_H_ */
