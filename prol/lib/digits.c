#ifndef DIGITS
#define DIGITS

#include <stdbool.h>

/*
	This func check - long long or not.
*/
bool is_long (char *str)
{

	size_t len = strlen(str);
	for (int i = 0; i < len; ++i)
	{

		if (i == 0 && str[i] == '-')
			continue;

		if (str[i] >= '0' && str[i] <= '9')
			continue;
		else
			return false;
	}

	if (str[0] == '-' && len > 18)
		return false;
	else if (len > 17 && str[0] != '-')
		return false;

	return true;
}

/*
	double or not
*/
bool is_double (char *str)
{

	size_t len = strlen(str);
	bool dot = false;
	size_t count_until_dot = 0;

	for (int i = 0; i < len; ++i)
	{

		if (i == 0 && str[i] == '-')
			continue;

		if (str[i] == '.')
		{

			if (dot)
				return false;
			dot = true;
			continue;
		}

		if (!dot)
			count_until_dot++;

		if (str[i] >= '0' && str[i] <= '9')
			continue;

		return false;
	}

	if (count_until_dot > 18)
		return false;

	return true;
}

#endif //DIGITS