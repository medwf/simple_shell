#ifndef MAIN_H
#define MAIN_H

/* --- include header file --- */
#include <stdio.h>	   /* stdin using in getline */
#include <unistd.h>	   /* for write and execve function */
#include <sys/types.h> /* for get process pid_t and size_t */
#include <sys/wait.h>  /* wait function */
#include <stdlib.h>	   /* exit and free function */
#include <string.h>	   /* strlen strtok function */
#include <sys/stat.h>  /* stat function */
#include <signal.h>	   /* for signal function */
/* --- Create structure --- */
/**
 * struct input_output_shell  - define a stucture to hold data for our shell.
 * @stored : a string to store user input.
 * @array : an arrays of string to hold argument
 * @name_shell : a string that stored name of ececute file.
 * @env : a double pointer to enviroment.
 * @count : a unsigned intgers give as number of process.
 * @_exit : last exit status.
 */

typedef struct input_output_shell
{
	char *stored;
	char **array;
	const char *name_shell;
	char **env;
	size_t count;
	int _exit;
} shell;

/* --- Function --- */
/* - in file function.c you will find -*/
void free_array(shell *ptr);
void divide_arg(shell *ptr);
void handler(int signal);
void dte_space(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* - in file function_1.c you will find -*/
int print(const char *str);
void get_command(shell *ptr);
void fork_execve(shell *ptr);
void init_struct(shell *p, const char *name, char **env);
char *_getenv(char *name, char **env);

/* - in file handle_string.c you will find -*/
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strncmp(char *s1, char *s2, int n);

/* - in file handle_string_1.c you will find -*/
int _strcmp(char *s1, char *s2);
int _atoi(char *str);

/* in file handle_err.c */
void print_error(shell *ptr, char *err);
void print_number(size_t n);
void putchar_err(char c);

/* in handle_path.c */
void check_path(shell *ptr);

/* handle_exit_env.c*/
int handle_exit_env(shell *ptr);

#endif /* main.h */
