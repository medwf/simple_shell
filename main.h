#ifndef MAIN_H
#define MAIN_H

/* --- include header file --- */
#include <stdio.h>       /* stdin using in getline */
#include <unistd.h>     /* for write and execve function */
#include <sys/types.h> /* for get process pid_t and size_t */
#include <sys/wait.h> /* wait function */
#include <stdlib.h>  /* exit and free function */
#include <string.h> /* strlen strtok function */
#include <sys/stat.h>       /* stat function */
#include <signal.h> /* for signal function */
/* --- struct for data arg stored shell name --- */
/**
 * struct input_argument  - define a stucture to hold data
 * @stored : a string to store user input.
 * @array : an arrays of string to hold argument
 * @name_shell : a string that stored name of ececute file.
 */

typedef struct input_argument
{
	char *stored;
	char **array;
	const char *name_shell;
} input;

/* --- Function --- */
/* - in file function.c you will find -*/
void free_array(input *ptr);
void divide_arg(input *ptr);
void handler(int signal);
void output_cmd(input *ptr);
void dte_space(char *str);

#endif /* main.h */
