/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef ERROR_ERROR_HANDLER_H
#define ERROR_ERROR_HANDLER_H

#define ERROR_BUFFER_SIZE 128 

#include <setjmp.h>

enum FfxivMitigationSolverExceptions
{
	FileOpenError,
	InvalidFormat,
	InvalidNumberofTokens,
	InvalidDamageType,
	InvalidDamageTarget,
	InvalidDamageCategory,
};

struct ErrorInfo {
	enum FfxivMitigationSolverExceptions error;
	char message[ERROR_BUFFER_SIZE];
};


extern jmp_buf ffxiv_mitigation_solver_exception_jmp_buf;
extern struct ErrorInfo ffxiv_mitigation_solver_error_info;
void ffxiv_mitigation_solver_error_handler(void);

#endif