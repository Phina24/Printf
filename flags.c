#include "main.h"

/**
 * get_flags: This calculates active flags
 * @format: Formatted string in which to print the arguments
 * @p: take a parameter.
 * Return: Flags:
 */
int get_flags(const char *format, int *p)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, curr_p;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_p = *p + 1; format[curr_p] != '\0'; curr_p++)
	{
		for (i = 0; FLAGS_CH[i] != '\0'; i++)
			if (format[curr_p] == FLAGS_CH[i])
			{
				flags |= FLAGS_ARR[i];
				break;
			}

		if (FLAGS_CH[i] == 0)
			break;
	}

	*p = curr_p - 1;

	return (flags);
}
