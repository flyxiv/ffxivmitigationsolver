#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include "const.h"
#include "string_util.h"

int split_string(char *restrict str, const char delimeters[static 1], int max_token_cnt, int token_length, char tokens[][token_length])
{
	char *str_copy = strdup(str);
	if (str_copy == NULL)
	{
		perror("Memory allocation failed");
		return -1;
	}

	int token_cnt = 0;
	char *ptr = strtok(str_copy, delimeters);

	while (ptr != NULL && token_cnt < max_token_cnt)
	{
		strncpy(tokens[token_cnt], ptr, token_length - 1);
		tokens[token_cnt][token_length - 1] = '\0'; // Ensure null-termination
		token_cnt++;
		ptr = strtok(NULL, delimeters);
	}

	free(str_copy);

	return token_cnt;
}