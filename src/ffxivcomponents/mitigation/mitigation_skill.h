/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_MITIGATION_MITIGATION_SKILL_H
#define FFXIVCOMPONENTS_MITIGATION_MITIGATION_SKILL_H

#include <util/const.h>
#include <ffxivcomponents/damage/damage_target.h>

#include "mitigation_data.h"

struct MitigationSkill
{
	char *name;

	enum DamageTarget target;
	struct MitigationData *mitigation_data;

	MilliSecondsType duration_milliseconds;
	MilliSecondsType cooldown_milliseconds;

	CastCountType cast_count;
	MilliSecondsType cast_times_millisecond[MAX_CAST_COUNT];
};

MilliSecondsType get_current_cooldown_millisecond(const struct MitigationSkill *skill, const MilliSecondsType current_combat_time_millisecond);

struct MitigationSkill create_all_damage_mitigation_skill(
	const char *const skill_name,
	enum DamageTarget damage_target,
	const MitigationPercentType mitigation_percent,
	const MilliSecondsType duration_milliseconds,
	const MilliSecondsType cooldown_milliseconds);
#endif