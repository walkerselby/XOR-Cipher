//Walker Selby - 7 December 2021

#ifndef HEADER
#define HEADER

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool debugMode;
char *file1;
char *file2;
char keyC;

void debug(const char *message);
void debugInt(const char *message, int val);
void debugStr(const char* message, const char *str);
void error(const char *message);
int cipher();

#endif
