/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_TIMELINEBOARD_SOLVER_BOARD_H
#define FFXIVCOMPONENTS_TIMELINEBOARD_SOLVER_BOARD_H

#include <util/types.h>
#include <util/const.h>
#include <ffxivcomponents/damage/damage_event.h>

struct HpInfo
{
	DamageAmountType tank_max_hp;
	DamageAmountType non_tank_max_hp;
};

struct SolverBoard
{
	struct HpInfo hp_info;

	const DamageEventCountType damage_event_count;
	struct DamageEvent *damage_events;

	struct FfxivJob *party_members;
};

#endif