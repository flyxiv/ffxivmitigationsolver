#include <assert.h>
#include <string.h>
#include <util/string_util.h>

#include "test_macro.h"
#include "string_test.h"

void test_split_string()
{
	char str[] = "Hello, World! good, day";
	char delimeters[] = ",";
	char tokens[3][100];
	split_string(str, delimeters, 3, 100, tokens);

	assert(strcmp(tokens[0], "Hello") == 0);
	assert(strcmp(tokens[1], " World! good") == 0);
	assert(strcmp(tokens[2], " day") == 0);

	PRINT_TEST_PASSED();
}