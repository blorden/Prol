#ifndef EXEC
#define EXEC

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "../lib/prol_stack.c"
#include "../lib/registers.c"

void exec (char *fname)
{

	FILE *fptr = fopen(fname, "rb");
	assert(fptr != NULL);

	prol_stack file_byte_stack = new_prol_stack(1);

	char *buf = NULL;

	fseek(fptr, 0, SEEK_END);
	size_t fsize = 	ftell(fptr);
	fseek(fptr, 0, SEEK_SET);

	buf = (char*) calloc(fsize, 1);
	fread(buf, 1, fsize, fptr);
	fclose(fptr);

	for (int i = 0; i < fsize; ++i)
		push_prol_stack(&file_byte_stack, buf + i);
	free(buf);


	prol_stack cpu_byte_stack = new_prol_stack(1),
			   cpu_ret_stack  = new_prol_stack(2);

	char **regs = (char**) calloc(REGISTERS_COUNT, sizeof(char*));
	for (int i = 0; i < REGISTERS_COUNT; ++i)
		regs[i] = (char*) calloc(8, 1);

	int  cmp_res = 0;
	uint16_t ret_temp = 0;

#define DEF_MAGIC_PROL_MASTER(cmd_name, cmd_num, cmd_size, cmd_args, de_args_code, code, is_jump, jump_byte) \
	if (true)																															\
		code 																															\
	if (is_jump)																														\
		_i = jump_byte;																													\
	else																																\
		_i += cmd_size;																														
//---------------------------------------------------------------------------------------------------------------------------------------


	for (int _i = 0; _i < file_byte_stack.size;)
	{

#include "../prol_masters/magic_prol_master.c"
	}

	clear_prol_stack(&cpu_byte_stack);
	clear_prol_stack(&cpu_ret_stack);
	clear_prol_stack(&file_byte_stack);

	for (int i = 0; i < REGISTERS_COUNT; ++i)
		free(regs[i]);
	free(regs);
}

#undef DEF_MAGIC_PROL_MASTER
#endif //EXEC