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

#include "../includes/ternimal.h"
#include <fcntl.h>

// Defines the path to the file containing the ternimal's art.
char *set_ascii(void) {
	size_t	buf_size = 0;
	char	*buf = NULL;

	printf("Enter the full filepath to your ascii art file\n(or enter for default)\n::> ");
	getline(&buf, &buf_size, stdin);
	if (strcmp(buf, "\n")) {
		buf[strlen(buf) - 1] = '\0';
		return (buf);
	}
	else
		return (strcat(getenv("HOME"), DEFAULT_ART_PATH));
}
// Initialises a new ternimal using the default parameters defined in ternimal.h
ternimal_struct *new_ternimal(void) {
	ternimal_struct	*ternimal_new;
	size_t name_size = 0;

	ternimal_new = malloc(sizeof(ternimal_struct));
	ternimal_new -> hunger = DEFAULT_HUNGER;
	ternimal_new -> health = DEFAULT_HEALTH;
	ternimal_new -> size = DEFAULT_SIZE;
	ternimal_new -> happiness = DEFAULT_HAPPINESS;
	ternimal_new -> love = DEFAULT_LOVE;
	ternimal_new -> last_login = time(NULL);

	printf("(MAX 255) Enter a name for your ternimal!\n::> ");
	getline(&(ternimal_new -> name), &name_size, stdin);
	printf("New ternimal name: %s", ternimal_new -> name);

	ternimal_new -> art_file = set_ascii();
	printf("File path: %s", ternimal_new -> art_file);

	return (ternimal_new);
}

int print_art(char *art_file) {
	FILE	*fp = fopen(art_file, "r");
	size_t 	bufsize = 0;
	char	*buf = NULL;

	if (!art_file)
		return (-1);
	if (!fp) {
		perror(DEFAULT_ERROR);
		printf("Does your ternimals artfile exist?\n");
		return (-1);
	}
	while(getline(&buf, &bufsize, fp) >= 0)
		printf("%s", buf);
	return (1);
}

// Prints the current stats of the ternimal.
void print_ternimal_data(ternimal_struct *ternimal) {
	while (!print_art(ternimal -> art_file)) {
		printf("ERROR: Art file potentially not valid...\n");
		if (ternimal -> art_file)
			free(ternimal -> art_file);
		ternimal -> art_file = set_ascii();
	}
	printf("Name:      %s", ternimal -> name);
	printf("Hunger:    %d\n", ternimal -> hunger);
	printf("Health:    %d\n", ternimal -> health);
	printf("Size:      %d\n", ternimal -> size);
	printf("Happiness: %d\n", ternimal -> happiness);
	printf("Love:      %d\n", ternimal -> love);

	return;
}

// Checks the date of the last login, vs the date of the current login, and determines
// the amount of hours passed, increasing hunger, and deducting stats accordingly.
unsigned int ternimal_time_update(ternimal_struct *ternimal) {
	unsigned int	hours_passed = 0;
	unsigned int	difference;
	time_t			current_time;

	time(&current_time);
	difference = (current_time - ternimal -> last_login);
	while (difference > HOUR) {
		hours_passed++;
		difference -= HOUR;
	}
	printf("You last logged in %u hours ago!\n", hours_passed);
	ternimal -> last_login = current_time;
	return (hours_passed);
}

void ternimal_update(ternimal_struct *ternimal, unsigned int hours_passed) {
	for (; hours_passed > 0; hours_passed--) {
		ternimal -> hunger += 8;
		if (ternimal -> hunger > MAX_HUNGER) {
			ternimal -> health -= 2;
			ternimal -> size--;
			ternimal -> happiness -= 3;
			ternimal -> love -= 4;
			ternimal -> hunger = MAX_HUNGER;
		}
	}
	return;
}
