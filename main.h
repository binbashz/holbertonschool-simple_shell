#ifndef main_h
#define main_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /* header for strtok */
#include <errno.h> /* for perror alert */
#include <unistd.h>
#include <sys/wait.h>
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
#endif
