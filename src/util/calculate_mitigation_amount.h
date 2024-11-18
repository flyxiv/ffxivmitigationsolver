/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef UTIL_CALCULATE_MITIGATION_AMOUNT_H
#define UTIL_CALCULATE_MITIGATION_AMOUNT_H

#include "types.h"

/*
 * defines calculation functions used for calculating specific mitigation amounts
 */

DamageAmountType calculate_maxhp_increase_amount(const DamageAmountType max_hp, MitigationPercentType increase_percent);
StackedMitigationType calculate_modified_damage_reduction(const StackedMitigationType total_mitigation, const MitigationPercentType reduction_percent);
inline DamageAmountType calculate_damage_reduction_amount(const DamageAmountType raw_damage, const StackedMitigationType total_mitigation);

#endif