/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_DAMAGE_DAMAGE_PROFILE_H
#define FFXIVCOMPONENTS_DAMAGE_DAMAGE_PROFILE_H

#include <util/types.h>
#include "damage_type.h"

struct InstantDamage
{
	const DamageAmountType damage_amount;
};

struct DamageOverTime
{
	const DamageAmountType damage_amount;
	const MilliSecondsType duration_milliseconds;
};

struct DamageProfile
{
	enum DamageType damage_type;
	union
	{
		struct InstantDamage instant_damage;
		struct DamageOverTime dot_damage;
	} damage_data;
};

#endif