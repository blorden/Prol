#ifndef PROL_CHEKC
#define PROL_CHEKC

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../lib/is_label_line.c"
#include "../lib/label_map.c"
#include "../lib/prol_stack.c"
#include "../lib/registers.c"
#include "../lib/digits.c"

#define DEF_TRANS_PROL_MASTER(is_correct, command_sz, command_num, trans_code) \
	if (all_lines_is_correct && !is_correct)								   \
		all_lines_is_correct = false;										   \
	if (!is_correct)														   \
		printf("\nerror: incorrect line\nline number: %lu\n%s\n",			   \
				line_num + 1, line);		 								   \
	free(line);																   \
	line = NULL;															   \
	cur_byte += command_sz;					
//------------------------------------------------------------------------------

#define CODE_CHECKING

bool prol_check (FILE *fptr, label_map *labels)
{

	char *line = NULL;
	size_t line_sz  = 0,
		   line_num = 0,
		   cur_byte = 0;

	prol_stack jmp_lines_stack  = new_prol_stack(sizeof(char*)),
			   jmp_lines_nums   = new_prol_stack(sizeof(size_t)),
			   jmp_labels_stack = new_prol_stack(sizeof(char*));

	bool all_lines_is_correct = true;

	while (getline(&line, &line_sz, fptr) != EOF)
	{

#include "../prol_masters/trans_prol_master.c"
		line_num++;
	}
	free(line);
	fseek(fptr, 0, SEEK_SET);

	for (int i = 0; i < jmp_labels_stack.size; ++i)
	{

		if (!exist_label_map(labels, *(char**)get_prol_stack(&jmp_labels_stack, i)))
		{

			all_lines_is_correct = false;
			printf("\nerror: label is not exist\nline number: %lu\n%s\n",
					*(size_t*)get_prol_stack(&jmp_lines_nums, i), 
					*(char**)get_prol_stack(&jmp_lines_stack, i));
		}


	}

	clear_prol_stack(&jmp_lines_nums);

	for (int i = 0; i < jmp_lines_stack.size; ++i)
	{

		free(*(char**)get_prol_stack(&jmp_lines_stack, i));
		free(*(char**)get_prol_stack(&jmp_labels_stack, i));	
	}

	clear_prol_stack(&jmp_lines_stack);
	clear_prol_stack(&jmp_labels_stack);

	return all_lines_is_correct;
}

#undef DEF_TRANS_PROL_MASTER
#undef CODE_CHECKING
#endif //PROL_CHEKC