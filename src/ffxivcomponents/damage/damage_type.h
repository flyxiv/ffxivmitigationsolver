/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIV_COMPONENTS_DAMAGE_TYPE_H
#define FFXIV_COMPONENTS_DAMAGE_TYPE_H

#define DAMAGE_TYPE_PHYSICAL_LITERAL "Physical"
#define DAMAGE_TYPE_MAGIC_LITERAL "Magic"

enum DamageType
{
	DamageTypePhysical,
	DamageTypeMagic,
};

enum DamageType convert_to_damage_type(const char *const restrict damage_type_str);

#endif