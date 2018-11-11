/*
Copyright 2011 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HOST_DRIVER_H
#define HOST_DRIVER_H

#include <stdint.h>
#include "report.h"


typedef struct {
    uint8_t (*keyboard_leds)(void);
    void (*send_keyboard)(report_keyboard_t *);
    void (*send_mouse)(report_mouse_t *);
    void (*send_system)(uint16_t);
    void (*send_consumer)(uint16_t);
	
	// Atmel ASF HAL can send individual keys only
	void (*send_keyboard_keyUp)(uint8_t);
	void (*send_keyboard_keyDown)(uint8_t);
	void (*send_keyboard_modifierUp)(uint8_t);
	void (*send_keyboard_modifierDown)(uint8_t);
} host_driver_t;

#endif
