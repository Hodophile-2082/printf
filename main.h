#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
/**
 * struct type - struct type
 * @t: type
 * @f: function
 */
typedef struct type
{
	char *t;
	void (*f)(va_list);
} type_t;
int _printf(const char *format, ...);
void print_char(va_list ap);
void print_string(va_list ap);
void print_percent(va_list ap);
#endif
