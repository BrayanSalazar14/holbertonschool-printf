#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);

int printChar(va_list arguments);
int printString(va_list arguments);
int countNum(unsigned int n);
int printPercent(va_list arguments);
int printNumsInt(va_list arguments);

#endif
