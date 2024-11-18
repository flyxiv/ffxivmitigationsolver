/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_DAMAGE_DANAGE_INFO_H
#define FFXIVCOMPONENTS_DAMAGE_DANAGE_INFO_H

#include <util/types.h>

#include "damage_type.h"
#include "damage_profile.h"
#include "damage_target.h"

struct DamageInfo
{
	const enum DamageType damage_type;
	const enum DamageTarget damage_target;
	const struct DamageProfile damage_profile;
};

#endif