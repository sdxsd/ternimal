/*
THIS FILE IS A PART OF THE TERNIMAL PROGRAM
Copyright (C) 2021  Will Maguire

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>

The definition of Free Software is as follows:
	- The freedom to run the program, for any purpose.
	- The freedom to study how the program works, and adapt it to your needs.
	- The freedom to redistribute copies so you can help your neighbor.
	- The freedom to improve the program, and release
	  your improvements to the public, so that the whole community benefits.

A program is free software if users have all of these freedoms.
*/

#ifndef TERNIMAL_H
# define TERNIMAL_H

// Includes:
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_ART_PATH "/.ternimal_art/cat.txt"
// TRUE and FALSE booleans.
#define TRUE 1
#define FALSE 0

// Defines default buffer size.
#define BUFFER_SIZE 1024

// Error text.
#define DEFAULT_ERROR "ERROR: "

// Defines the amount of seconds within an hour.
#define HOUR 7200

// Defines limits for the ternimal's stats and feelings.
#define MAX_HUNGER 64
#define MAX_HEALTH 64
#define MAX_SIZE 255
#define MAX_HAPPINESS 128
#define MAX_LOVE 1024

// Default stats and feelings.
#define DEFAULT_HUNGER 55
#define DEFAULT_HEALTH 12
#define DEFAULT_SIZE 12
#define DEFAULT_HAPPINESS 32
#define DEFAULT_LOVE 8

// Basic structure for the ternimal!
typedef struct ternimal {
	time_t	last_login;
	char	*name;
	char	*art_file;
	short	danger_flag;
	int 	hunger,
			health,
			size,
			happiness,
			love;
} ternimal_struct;

// TERNIMAL FUNCTIONS (ternimal_utils.c)
ternimal_struct *new_ternimal(void);
void print_ternimal_data(ternimal_struct *ternimal);
unsigned int ternimal_time_update(ternimal_struct *ternimal);
void ternimal_update(ternimal_struct *ternimal, unsigned int hours_passed);

// DANGER FUNCTIONS (danger.c)
void ternimal_angryletter(void);

#endif // TERNIMAL_H
