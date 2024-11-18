#include <string.h>
#include <stdio.h>
#include <error/error_handler.h>

#include "damage_target.h"

enum DamageTarget convert_to_damage_target(const char *const restrict damage_target_str)
{
	if (strcmp(damage_target_str, DAMAGE_TARGET_RAIDWIDE_LITERAL) == 0)
	{
		return DamageTargetRaidwide;
	}
	else if (strcmp(damage_target_str, DAMAGE_TARGET_TANK_SHARE_LITERAL) == 0)
	{
		return DamageTargetTankshare;
	}
	else if (strcmp(damage_target_str, DAMAGE_TARGET_TANK_SOLO_LITERAL) == 0)
	{
		return DamageTargetTanksolo;
	}
	else
	{
		ffxiv_mitigation_solver_error_info.error = InvalidDamageTarget;
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE, "Invalid Damage Target: %s", damage_target_str);
		longjmp(ffxiv_mitigation_solver_exception_jmp_buf, ffxiv_mitigation_solver_error_info.error);
		return -1;
	}
}