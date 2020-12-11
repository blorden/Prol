char *temp_line = NULL;
temp_line = (char*) calloc(line_sz + 1, sizeof(char));

for (int i = 0; i < line_sz; ++i)
	temp_line[i] = line[i];
temp_line[line_sz] = '\0';

char *correct_line = temp_line;

for (int i = 0; correct_line[i] != '\0'; ++i)
	if (correct_line[i] == ';')
	{

		correct_line[i] = '\0';
		break;
	}

//---------------------------------------------------

char  *parts_of_line[10];
size_t parts_count = 0;

char *temp_str = strtok(correct_line, " \t\r\n");

while (parts_count < 10)
{

	if (temp_str == NULL)
		break;

	parts_of_line[parts_count++] = temp_str;

	temp_str = strtok(NULL, " \t\r\n");
}

if (strtok(NULL, " \t\r\n") != NULL)
{

	DEF_TRANS_PROL_MASTER(false, 0, 0, {})
}
else if (parts_count == 0)
{

	DEF_TRANS_PROL_MASTER(true, 0, 0, {})
}
else if (parts_count == 1 && is_label_line(parts_of_line[0]))
{

#ifdef CODE_CHECKING

	if (insert_label_map(labels, parts_of_line[0], cur_byte) != 0)
	{

		DEF_TRANS_PROL_MASTER(false, 0, 0, {})
	}
	else
	{

		DEF_TRANS_PROL_MASTER(true, 0, 0, {})
	}
#else

	DEF_TRANS_PROL_MASTER(true, 0, 0, {})
#endif
}
//1 byte 0 arguments
else if (parts_count == 1 && strcmp(parts_of_line[0], "lin") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 1, 
	{

		char temp = 1;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "din") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 2, 
	{

		char temp = 2;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "lout") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 3, 
	{

		char temp = 3;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dout") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 4, 
	{

		char temp = 4;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "pop") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 5, 
	{

		char temp = 5;
		push_prol_stack(&byte_stack, &temp);		
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "sqrt") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 6, 
	{

		char temp = 6;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "lsqr") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 7, 
	{

		char temp = 7;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dsqr") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 8, 
	{

		char temp = 8;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "ladd") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 9, 
	{

		char temp = 9;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dadd") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 10, 
	{

		char temp = 10;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "lmul") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 11, 
	{

		char temp = 11;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dmul") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 12, 
	{

		char temp = 12;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "ldiv") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 13, 
	{

		char temp = 13;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "ddiv") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 14, 
	{

		char temp = 14;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "mod") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 15, 
	{

		char temp = 15;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "lsub") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 16, 
	{

		char temp = 16;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dsub") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 17, 
	{

		char temp = 17;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "hlt") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 18, 
	{

		char temp = 18;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "tol") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 19, 
	{

		char temp = 19;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "tod") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 20, 
	{

		char temp = 20;
		push_prol_stack(&byte_stack, &temp);
	})
}
//3 byte 1 argument
else if (parts_count == 2 && strcmp(parts_of_line[0], "jmp") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 21, 
	{

		char temp = 21;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "call") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 22, 
	{

		char temp = 22;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "jm") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 23, 
	{

		char temp = 23;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "jb") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 24, 
	{

		char temp = 24;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "jbe") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 25, 
	{

		char temp = 25;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "je") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 26, 
	{

		char temp = 26;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "jne") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 27, 
	{

		char temp = 27;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ja") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 28, 
	{

		char temp = 28;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "jae") == 0)
{

#ifdef CODE_CHECKING
	char *temp1 = (char*) calloc(strlen(parts_of_line[1]) + 1, 1);
	memcpy(temp1, parts_of_line[1], strlen(parts_of_line[1]) + 1);
	push_prol_stack(&jmp_labels_stack, &temp1);

	char *temp2 = (char*) calloc(line_sz + 1, 1);
	memcpy(temp2, line, line_sz);
	temp2[line_sz] = '\0';
	push_prol_stack(&jmp_lines_stack, &temp2);

	size_t temp3 = line_num + 1;
	push_prol_stack(&jmp_lines_nums, &temp3);
#endif

	DEF_TRANS_PROL_MASTER(true, 3, 29, 
	{

		char temp = 29;
		push_prol_stack(&byte_stack, &temp);

		uint16_t temp2 = get_num_byte_label_map(&labels, parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 2);
	})
}
//1 byte 0 arguments
else if (parts_count == 1 && strcmp(parts_of_line[0], "dcmp") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 30, 
	{

		char temp = 30;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "lcmp") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 31, 
	{

		char temp = 31;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "ret") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 32, 
	{

		char temp = 32;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "inc") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 33, 
	{

		char temp = 33;
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 1 && strcmp(parts_of_line[0], "dec") == 0)
{

	DEF_TRANS_PROL_MASTER(true, 1, 34, 
	{

		char temp = 34;
		push_prol_stack(&byte_stack, &temp);
	})
}
//registers, 2 byte 1 argument
else if (parts_count == 2 && strcmp(parts_of_line[0], "lin") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 35, 
	{

		char temp = 35;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);		
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "din") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 36, 
	{

		char temp = 36;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lout") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 37, 
	{

		char temp = 37;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dout") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 38, 
	{

		char temp = 38;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "push") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 39, 
	{

		char temp = 39;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "pop") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 40, 
	{

		char temp = 40;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "sqrt") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 41, 
	{

		char temp = 41;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lsqr") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 42, 
	{

		char temp = 42;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dsqr") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 43, 
	{

		char temp = 43;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ladd") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 44, 
	{

		char temp = 44;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dadd") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 45, 
	{

		char temp = 45;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lmul") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 46, 
	{

		char temp = 46;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dmul") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 47, 
	{

		char temp = 47;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ldiv") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 48, 
	{

		char temp = 48;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ddiv") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 49, 
	{

		char temp = 49;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "mod") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 50, 
	{

		char temp = 50;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lsub") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 51, 
	{

		char temp = 51;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dsub") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 52, 
	{

		char temp = 52;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "tol") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 53, 
	{

		char temp = 53;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "tod") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 54, 
	{

		char temp = 54;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 55, 
	{

		char temp = 55;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 56, 
	{

		char temp = 56;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "inc") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 57, 
	{

		char temp = 57;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dec") == 0 &&
		  is_reg(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 2, 58, 
	{

		char temp = 58;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);
	})
}
//registers, 3 byte 2 arguments
else if (parts_count == 3 && strcmp(parts_of_line[0], "sqrt") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 59, 
	{

		char temp = 59;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lsqr") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 60, 
	{

		char temp = 60;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dsqr") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 61, 
	{

		char temp = 61;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ladd") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 62, 
	{

		char temp = 62;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dadd") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 63, 
	{

		char temp = 63;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lmul") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 64, 
	{

		char temp = 64;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dmul") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 65, 
	{

		char temp = 65;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ldiv") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 66, 
	{

		char temp = 66;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ddiv") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 67, 
	{

		char temp = 67;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "mod") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 68, 
	{

		char temp = 68;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lsub") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 69, 
	{

		char temp = 69;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dsub") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 70, 
	{

		char temp = 70;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "tol") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 71, 
	{

		char temp = 71;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "tod") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 72, 
	{

		char temp = 72;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 73, 
	{

		char temp = 73;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 74, 
	{

		char temp = 74;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "mov") == 0 &&
		  is_reg(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 3, 75, 
	{

		char temp = 75;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
//register and long, 2 arguments 10 byte
else if (parts_count == 3 && strcmp(parts_of_line[0], "mov") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 76, 
	{

		char temp = 76;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 77, 
	{

		char temp = 77;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ladd") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 78, 
	{

		char temp = 78;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lmul") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 79, 
	{

		char temp = 79;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ldiv") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 80, 
	{

		char temp = 80;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "mod") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 81, 
	{

		char temp = 81;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lsub") == 0 &&
		  is_reg(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 82, 
	{

		char temp = 82;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
//long and register, 2 arguments 10 byte
else if (parts_count == 3 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_long(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 83, 
	{

		char temp = 83;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "tod") == 0 &&
		  is_long(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 84, 
	{

		char temp = 84;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
//long, 1 arguments 9 byte
else if (parts_count == 2 && strcmp(parts_of_line[0], "lout") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 85, 
	{

		char temp = 85;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "push") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 86, 
	{

		char temp = 86;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lsqr") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 87, 
	{

		char temp = 87;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ladd") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 88, 
	{

		char temp = 88;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lmul") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 89, 
	{

		char temp = 89;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ldiv") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 90, 
	{

		char temp = 90;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "mod") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 91, 
	{

		char temp = 91;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lsub") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 92, 
	{

		char temp = 92;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "tod") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 93, 
	{

		char temp = 93;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_long(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 94, 
	{

		char temp = 94;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
//2 arguments, 17 byte, 2 longs :)
else if (parts_count == 3 && strcmp(parts_of_line[0], "lcmp") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 95, 
	{

		char temp = 95;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ladd") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 96, 
	{

		char temp = 96;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lmul") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 97, 
	{

		char temp = 97;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ldiv") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 98, 
	{

		char temp = 98;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "lsub") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 99, 
	{

		char temp = 99;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "mod") == 0 &&
		  is_long(parts_of_line[1]) && is_long(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 100, 
	{

		char temp = 100;
		push_prol_stack(&byte_stack, &temp);

		long long temp2 = atoll(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atoll(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
//register and double, 2 arguments 10 byte
else if (parts_count == 3 && strcmp(parts_of_line[0], "mov") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 101, 
	{

		char temp = 101;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);		
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 102, 
	{

		char temp = 102;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dadd") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 103, 
	{

		char temp = 103;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dmul") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 104, 
	{

		char temp = 104;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ddiv") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 105, 
	{

		char temp = 105;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dsub") == 0 &&
		  is_reg(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 106, 
	{

		char temp = 106;
		push_prol_stack(&byte_stack, &temp);

		temp = get_reg_num(parts_of_line[1]);
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
//double and register, 2 arguments 10 byte
else if (parts_count == 3 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_double(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 107, 
	{

		char temp = 107;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "tol") == 0 &&
		  is_double(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 108, 
	{

		char temp = 108;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "sqrt") == 0 &&
		  is_double(parts_of_line[1]) && is_reg(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 10, 109, 
	{

		char temp = 109;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp = get_reg_num(parts_of_line[2]);
		push_prol_stack(&byte_stack, &temp);
	})
}
//double, 1 arguments 9 byte
else if (parts_count == 2 && strcmp(parts_of_line[0], "dout") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 110, 
	{

		char temp = 110;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "push") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 111, 
	{

		char temp = 111;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dsqr") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 112, 
	{

		char temp = 112;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dadd") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 113, 
	{

		char temp = 113;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dmul") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 114, 
	{

		char temp = 114;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "ddiv") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 115, 
	{

		char temp = 115;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "sqrt") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 116, 
	{

		char temp = 116;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dsub") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 117, 
	{

		char temp = 117;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "tol") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 118, 
	{

		char temp = 118;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 2 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_double(parts_of_line[1]))
{

	DEF_TRANS_PROL_MASTER(true, 9, 119, 
	{

		char temp = 119;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
//2 arguments, 17 byte, 2 doubles :)
else if (parts_count == 3 && strcmp(parts_of_line[0], "dcmp") == 0 &&
		  is_double(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 120, 
	{

		char temp = 120;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dadd") == 0 &&
		  is_double(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 121, 
	{

		char temp = 121;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dmul") == 0 &&
		  is_double(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 122, 
	{

		char temp = 122;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "ddiv") == 0 &&
		  is_double(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 123, 
	{

		char temp = 123;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else if (parts_count == 3 && strcmp(parts_of_line[0], "dsub") == 0 &&
		  is_double(parts_of_line[1]) && is_double(parts_of_line[2]))
{

	DEF_TRANS_PROL_MASTER(true, 17, 124, 
	{

		char temp = 124;
		push_prol_stack(&byte_stack, &temp);

		double temp2 = atof(parts_of_line[1]);
		push_n_prol_stack(&byte_stack, &temp2, 8);

		temp2 = atof(parts_of_line[2]);
		push_n_prol_stack(&byte_stack, &temp2, 8);
	})
}
else
{

	DEF_TRANS_PROL_MASTER(false, 0, 0, {})
}

free(temp_line);