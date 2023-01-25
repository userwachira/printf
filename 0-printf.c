#include "main.h"
/**
 * _printf - prints function
 * @format: format
 * Return: value
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					write(1, &va_arg(args, int),1);
					count++;
					break;
				case 's':
					count += write(1, va_args(args, char *), strlen(va_arg(args, char *)));
					break;
				case '%':
					write(1, "%", 1);
					count++;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
	}
	va_end(args);

	return count;
}
