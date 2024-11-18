/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#include "types.h"
#include "const.h"
#include "calculate_mitigation_amount.h"

/*
 * Calculates the amount of max HP increase given a percentage increase and the current max HP.
 */
DamageAmountType calculate_maxhp_increase_amount(const DamageAmountType max_hp, const MitigationPercentType increase_percent)
{
	MitigationPercentType increase_multiplier = (ONE_HUNDRED_PERCENT + increase_percent);
	DamageAmountType hp_after_increase = increase_multiplier * max_hp / ONE_HUNDRED_PERCENT_AS_DOUBLE;

	return hp_after_increase - max_hp;
}

/*
 * FFXIV Has diminishing returns on stacking damage mitigation
 *
 * ex)
 * 1) The first 10% mitigation reduces 10% of the raw damage, which means 90% of the raw damage is taken.
 * 2) The second 10% mitigation reduces 10% of the "remaining 90%" of the raw damage, which means 81% of the raw damage is taken. So it is actually only a 9% reduction from the raw damage.
 *
 * @param current_mitigation_percent The current mitigation percent of the player (ex) 82% -> 82)
 * @param reduction_percent The reduction percent of the new skill (ex) 10% -> 10)
 *
 * @return The "actual" mitigation percent of the new skill given the current mitigation percent.
 */
StackedMitigationType calculate_modified_damage_reduction(const StackedMitigationType total_mitigation, const MitigationPercentType reduction_percent)
{
	MitigationPercentType reduction_multiplier = (ONE_HUNDRED_PERCENT - reduction_percent) / ONE_HUNDRED_PERCENT_AS_DOUBLE;
	StackedMitigationType total_mitigation_after_current_skill = total_mitigation * reduction_multiplier;
	return total_mitigation_after_current_skill - total_mitigation;
}

inline DamageAmountType calculate_damage_reduction_amount(const DamageAmountType raw_damage, const StackedMitigationType total_mitigation)
{
	return raw_damage * total_mitigation;
}
