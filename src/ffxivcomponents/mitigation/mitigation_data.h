/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_MITIGATION_MITIGATION_DATA_H
#define FFXIVCOMPONENTS_MITIGATION_MITIGATION_DATA_H

#include <util/types.h>
#include "./mitigation_type.h"

/*
 * Defines Data Types for the Various Mitigation Types in FFXIV.
 * Mitigation skills have one or more of these mitigation data types plus the MitigationType enum to tell how to read the data.
 */

struct MitigationShield
{
	DamageAmountType shield_amount;
};

struct MitigationPhysicalDamageReduction
{
	MitigationPercentType reduction_percent;
};

struct MitigationMagicDamageReduction
{
	MitigationPercentType reduction_percent;
};

struct MitigationHealingReceivedIncrease
{
	MitigationPercentType increase_percent;
};

struct MitigationPlayerMaxHPIncrease
{
	DamageAmountType increase_percent;
};

struct MitigationData;

struct MitigationData
{
	enum MitigationType type;
	union
	{
		struct MitigationShield shield;
		struct MitigationPhysicalDamageReduction physical_damage_reduction;
		struct MitigationMagicDamageReduction magic_damage_reduction;
		struct MitigationHealingReceivedIncrease healing_received_increase;
		struct MitigationPlayerMaxHPIncrease player_max_hp_increase;
	} mitigation_amount;
};

#endif