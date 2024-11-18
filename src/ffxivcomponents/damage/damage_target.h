/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_DAMAGE_TARGET_H
#define FFXIVCOMPONENTS_DAMAGE_TARGET_H

#define DAMAGE_TARGET_RAIDWIDE_LITERAL "Raidwide"
#define DAMAGE_TARGET_TANK_SOLO_LITERAL "Tanksolo"
#define DAMAGE_TARGET_TANK_SHARE_LITERAL "Tankshare"

enum DamageTarget
{
	DamageTargetRaidwide,

	// Tankbuster where one tank receives damage
	DamageTargetTanksolo,

	// Tankbuster where two tanks share the damage.
	DamageTargetTankshare
};

enum DamageTarget convert_to_damage_target(const char *const restrict damage_target_str);

#endif