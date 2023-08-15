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
/* --- Create structure --- */
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
void dte_space(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
/* - in file function_1.c you will find -*/
int print(const char *str);
void _getline(input *ptr);
void fork_execve(input *ptr);
void init_struct(input *p, const char *name);

/* - in file handle_string.c you will find -*/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);

#endif /* main.h */
