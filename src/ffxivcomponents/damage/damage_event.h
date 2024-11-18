/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_DAMAGE_DAMAGE_EVENT_H
#define FFXIVCOMPONENTS_DAMAGE_DAMAGE_EVENT_H

#include <util/types.h>
#include "damage_info.h"

struct DamageEvent
{
	char *event_name;
	MilliSecondsType time_milliseconds;
	struct DamageInfo *damage_info;
};

#endif