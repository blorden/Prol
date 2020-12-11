#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "trans/trans.c"
#include "exec/exec.c"

int main (int argc, char *argv[])
{

	assert(argc > 2);

	if (strcmp(argv[1], "trans") == 0)
	{

		trans(argv[2]);
		return 0;
	}

	if (strcmp(argv[1], "exec") == 0)
	{

		exec(argv[2]);
		return 0;
	}

	return 0;
}