#include "main.h"
/**
 * _printf - function that does the same thing as printf
 * @format: input string
 * Return: number of characters in input
 */
int _printf(const char *format, ...)
{
	int len = 0;
	int str_length = 0;
	int int_length = 0;
	int sec_int_length = 0;
	int x;
	int xi;
	char c;
	char *s;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			len++;
		}
		else{
			format++;
		}

		if (*format == 'c')
		{
			c = va_arg(args, int);
			write(1, &c, 1);
		}

		if (*format == 's')
		{
			s = va_arg(args, char *);

			while (s[str_length] != '\0')
				str_length++;

			write(1, s, str_length);
			len = len + str_length;
		}

		if (*format == 'd')
		{
			x = va_arg(args, int);

			while (x != 0) {
				x /= 10;
				int_length++;
			}

			write(1, &x, int_length);
			len = len + int_length;
		}

		if (*format == 'i')
		{
			xi = va_arg(args, int);

			while (xi != 0)
			{
				xi /= 10;
				sec_int_length++;
			}

			write(1, &xi, sec_int_length);
			len = len + sec_int_length;
		}
	}

	va_end(args);

	return (len);
}
