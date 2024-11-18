/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_MITIGATION_MITIGATION_TYPE_H
#define FFXIVCOMPONENTS_MITIGATION_MITIGATION_TYPE_H

/*
 * Defines different types of mitigation in FFXIV combat.
 */

enum MitigationType
{
	Shield,

	// Mitigation that reduces only physical damage
	PhysicalDamageReduction,

	// Mitigation that reduces only magic damage
	MagicDamageReduction,

	// Mitigation that increases amount of healing received
	HealingReceivedIncrease,

	// Mitigation that increases a single player's max HP
	PlayerMaxHPIncrease,
};

#endif