/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>

#include <util/const.h>

#include "error_handler.h"

jmp_buf ffxiv_mitigation_solver_exception_jmp_buf;
struct ErrorInfo ffxiv_mitigation_solver_error_info = {0};

void ffxiv_mitigation_solver_error_handler(void)
{
	switch (setjmp(ffxiv_mitigation_solver_exception_jmp_buf))
	{
	case InvalidFormat:
		printf("Invalid Format: %s\n", ffxiv_mitigation_solver_error_info.message);
		break;
	case InvalidNumberofTokens:
		printf("Invalid Number of Arguments: %s\n", ffxiv_mitigation_solver_error_info.message);
		break;
	case InvalidDamageType:
		printf("Invalid Damage Type: %s\n", ffxiv_mitigation_solver_error_info.message);
		break;
	case InvalidDamageTarget:
		printf("Invalid Damage Target: %s\n", ffxiv_mitigation_solver_error_info.message);
		break;
	case InvalidDamageCategory:
		printf("Invalid Damage Category: %s\n", ffxiv_mitigation_solver_error_info.message);
		break;
	}

	exit(1);
}
