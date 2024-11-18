#include <stdio.h>
#include <string.h>

#include "damage_category.h"
#include "error/error_handler.h"

enum DamageCategory convert_to_damage_category(const char *const restrict damage_category_str)
{
	if (strcmp(damage_category_str, DAMAGE_CATEGORY_INSTANT_LITERAL) == 0)
	{
		return DamageCategoryInstant;
	}
	else if (strcmp(damage_category_str, DAMAGE_CATEGORY_DOTTICK_LITERAL) == 0)
	{
		return DamageCatergoryDottick;
	}
	else
	{
		ffxiv_mitigation_solver_error_info.error = InvalidDamageCategory;
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE, "Invalid Damage Type: %s", damage_category_str);
		longjmp(ffxiv_mitigation_solver_exception_jmp_buf, ffxiv_mitigation_solver_error_info.error);
		return -1;
	}
}