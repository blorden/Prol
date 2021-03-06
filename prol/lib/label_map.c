#ifndef LABEL_MAP
#define LABEL_MAP

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct __label_map
{

	char **mem;
	uint16_t *labels;

	size_t size,
		   capacity;
} label_map;

label_map new_label_map ()
{

	label_map temp;
	temp.mem = (char**) calloc(100, sizeof(char*));
	temp.labels = (uint16_t*) calloc(100, sizeof(uint16_t));

	temp.size = 0;
	temp.capacity = 100;

	return temp;
}

int insert_label_map (label_map *st, char *str, uint16_t byte_num)
{

	for (int i = 0; i < st->size; ++i)
	{

		if (strlen(str) <= strlen(st->mem[i]))
			continue;

		if (strlen(str) - strlen(st->mem[i]) != 1)
			continue;



		size_t temp = strlen(st->mem[i]);
		bool not_equ = false;

		for (int j = 0; j < temp; ++j)
			if (st->mem[i][j] != str[j])
			{
				not_equ = true;
				break;
			}

		if (!not_equ)
			return -1;
	}

	if (st->size == st->capacity)
	{

		st->capacity *= 2;
		st->mem = (char**) realloc(st->mem, st->capacity * sizeof(char*));
		st->labels = (uint16_t*) realloc(st->labels, st->capacity * sizeof(char*));
	}

	size_t temp_sz = strlen(str);

	char *temp = (char*) calloc(temp_sz + 1, 1);
	memcpy(temp, str, temp_sz + 1);
	temp[temp_sz - 1] = '\0'; //delete :

	st->mem[st->size] = temp;
	st->labels[st->size++] = byte_num;

	return 0;
}

bool exist_label_map (label_map *st, char *str)
{

	for (int i = 0; i < st->size; ++i)
		if (strcmp(st->mem[i], str) == 0)
			return true;

	return false;
}

uint16_t get_num_byte_label_map (label_map *st, char *str)
{

	for (int i = 0; i < st->size; ++i)
		if (strcmp(st->mem[i], str) == 0)
			return st->labels[i];

	return 0;
}

void clear_label_map (label_map *st)
{

	for (int i = 0; i < st->size; ++i)
		free(st->mem[i]);

	free(st->mem);
	free(st->labels);

	st->size = 0;
	st->capacity = 0;
}

#endif //LABEL_MAP