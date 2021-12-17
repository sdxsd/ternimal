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

ternimal_struct *new_ternimal(void) {
	size_t max_name = 255;
	ternimal_struct *ternimal_new;

	ternimal_new = malloc(sizeof(ternimal_struct));
	ternimal_new -> hunger = DEFAULT_HUNGER;
	ternimal_new -> health = DEFAULT_HEALTH;
	ternimal_new -> size = DEFAULT_SIZE;
	ternimal_new -> happiness = DEFAULT_HAPPINESS;
	ternimal_new -> love = DEFAULT_LOVE;
	ternimal_new -> last_login = time(NULL);

	printf("(MAX 255) Enter a name for your ternimal!\n::> ");
	getline(&(ternimal_new -> name), &max_name, stdin);
	printf("New ternimal name: %s\n", ternimal_new -> name);

	return (ternimal_new);
}

void print_ternimal_data(ternimal_struct *ternimal) {
	printf("Name: %s", ternimal -> name);
	printf("Hunger:    %d\n", ternimal -> hunger);
	printf("Health:    %d\n", ternimal -> health);
	printf("Size:      %d\n", ternimal -> size);
	printf("Happiness: %d\n", ternimal -> happiness);
	printf("Love:      %d\n", ternimal -> love);

	return;
}

void ternimal_time_update(ternimal_struct *ternimal) {
	time_t current_time;

	time(&current_time);
	if ((current_time - ternimal -> last_login) > 10) {
		printf("Why did you abandon me?\n");
	}
	ternimal -> last_login = current_time;
	return ;
}