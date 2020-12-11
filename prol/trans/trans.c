#ifndef TRANS
#define TRANS

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "../prol_check/prol_check.c"
#include "../lib/label_map.c"
#include "../lib/prol_stack.c"

/*
	Transform prol code to laborer bin code
*/
void trans (char *fname)
{

	FILE *fptr = fopen(fname, "r");
	assert(fptr != NULL);

	label_map labels = new_label_map();

	bool can_trans = prol_check(fptr, &labels);
	if (!can_trans)
	{

		printf("\nCan`t trans.\n\n");
		fclose(fptr);
		clear_label_map(&labels);
		return;
	}

	char  *line = NULL;
	size_t line_sz  = 0,
		   line_num = 0,
		   cur_byte = 0;

#define DEF_TRANS_PROL_MASTER(is_correct, command_sz, command_num, trans_code) \
	if (true)																   \
		trans_code															   \
	free(line);																   \
	line = NULL;															   \
	cur_byte += command_sz;													   
//------------------------------------------------------------------------------

	size_t fname_len = strlen(fname);
	char *out_fname = (char*) calloc(fname_len + 1, 1);
	memcpy(out_fname, fname, fname_len + 1);

	out_fname[fname_len - 1] = 'n';
	out_fname[fname_len - 3] = 'b';

	FILE *out_fptr = fopen(out_fname, "wb");

	prol_stack byte_stack = new_prol_stack(1);

	while (getline(&line, &line_sz, fptr) != EOF)
	{

#include "../prol_masters/trans_prol_master.c"
		line_num++;
	}
	free(line);

#undef DEF_TRANS_PROL_MASTER
	clear_label_map(&labels);

	dump_prol_stack(&byte_stack, out_fptr);
	clear_prol_stack(&byte_stack);

	fclose(fptr);
	fclose(out_fptr);
	free(out_fname);
}

#endif //TRANS