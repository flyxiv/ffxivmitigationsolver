#include <stdio.h>
#include <string.h>
#include <error/error_handler.h>

#include "damage_type.h"

enum DamageType convert_to_damage_type(const char *const restrict damage_type_str)
{
	if (strcmp(damage_type_str, DAMAGE_TYPE_PHYSICAL_LITERAL) == 0)
	{
		return DamageTypePhysical;
	}
	else if (strcmp(damage_type_str, DAMAGE_TYPE_MAGIC_LITERAL) == 0)
	{
		return DamageTypeMagic;
	}
	else
	{
		ffxiv_mitigation_solver_error_info.error = InvalidDamageType;
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE, "Invalid Damage Type: %s", damage_type_str);
		longjmp(ffxiv_mitigation_solver_exception_jmp_buf, ffxiv_mitigation_solver_error_info.error);
		return -1;
	}
}