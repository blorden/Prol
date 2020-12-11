#ifndef IS_LABEL_LINE
#define IS_LABEL_LINE

#include <stdbool.h>

/* part - is a part first part of line
   return true if all line is "label line"
   else false
*/
bool is_label_line (char *part)
{

	size_t temp = strlen(part);
	return part[temp - 1] == ':';
}

#endif //IS_LABEL_LINE