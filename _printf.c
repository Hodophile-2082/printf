#include "main.h"
#include <staarg.h>
#include <stdio.h>
#include <stdlib.h>
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int i, j, count;
	char *str, *sep;

	type_t types[] = {
		{"c", print_char},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{NULL, NULL}
	};
	va_start(ap, format);
	i = 0;
	count = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			j = 0;
			while (types[j].t != NULL)
			{
				if (format[i + 1] == types[j].t[0])
				{
					str = "";
					sep = "";
					if (i == 0)
						str = "";
					else if (format[i + 1] == '\0')
						sep = "";
					printf("%s", sep);
					types[j].f(ap);
					sep = "";
					count++;
					i++;
					break;
				}
				j++;
			}
		}
		else
		{
			str = "";
			sep = "";
			if (i == 0)
				str = "";
			else if (format[i + 1] == '\0')
				sep = "";
			printf("%s%c", sep, format[i]);
			count++;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
	return (count);
}
/**
 * printf_char - prints a character
 * @ap: list of arguments
 */
void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}
/**
 * print_string - prints a string
 * @ap: list of arguments
 */
void print_string(va_list ap)
{
	char *str;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}
/**
 * print_percent - prints a percent
 * @ap: list of arguments
 */
void print_percent(va_list ap)
{
	printf("%%");
}
/**
 * print_binary - prints a number in binary
 * @ap: list of arguments
 */
void print_binary(va_list ap)
{
	unsigned int n, i, j, k, l, m, o, p, q, r, s, t, u, v, w, x, y, z;
	unsigned int a, b, c, d, e, f, g, h;

	n = va_arg(ap, unsigned int);
	i = n >> 31;
	j = n >> 30;
	k = n >> 29;
	l = n >> 28;
	m = n >> 27;
	o = n >> 26;
	p = n >> 25;
	q = n >> 24;
	r = n >> 23;
	s = n >> 22;
	t = n >> 21;
	u = n >> 20;
	v = n >> 19;
	w = n >> 18;
	x = n >> 17;
	y = n >> 16;
	z = n >> 15;
	a = n >> 14;
	b = n >> 13;
	c = n >> 12;
	d = n >> 11;
	e = n >> 10;
	f = n >> 9;
	g = n >> 8;
	h = n >> 7;
	printf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d", i & 1, j & 1, k & 1, l & 1, m & 1, o & 1, p & 1, q & 1, r & 1, s & 1, t & 1, u & 1, v & 1, w & 1, x & 1, y & 1, z & 1, a & 1,b & 1, c & 1, d & 1, e & 1, f & 1, g & 1, h & 1, n & 1);
}
