/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIV_COMPONENTS_DAMAGE_CATEGORY_H
#define FFXIV_COMPONENTS_DAMAGE_CATEGORY_H

#define DAMAGE_CATEGORY_INSTANT_LITERAL "Instant"
#define DAMAGE_CATEGORY_DOTTICK_LITERAL "Dottick"

enum DamageCategory
{
	DamageCategoryInstant,
	DamageCatergoryDottick,
};

enum DamageCategory convert_to_damage_category(const char *const restrict damage_category_str);
#endif