#ifndef REGISTERS
#define REGISTERS

#include <stdbool.h>
#include <string.h>

#define REGISTERS_COUNT ('p' - 'a' + 1)

bool is_reg (char *str)
{

	if (strlen(str) == 3 &&
		str[0] == 'r' && str[2] == 'x' &&
		str[1] >= 'a' && str[1] <= 'p')
	return true;

	return false;
}

char get_reg_num (char *str)
{

	return str[1] - 'a' + 1;
}

#endif //REGISTERS