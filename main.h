#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* header for strtok */
#include <errno.h> /* header perror alert */
#include <sys/wait.h> /* header for wait */
#include <unistd.h>

/* globar variable */

extern char **environ;
/* --------------------------- */

char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
/* int print_env(void); */
int print_env(void);
#endif
