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
