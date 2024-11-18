#include <assert.h>
#include <stdlib.h> 
#include <util/calculations.h>

#include "mitigation_skill.h"


MilliSecondsType get_current_cooldown_millisecond(
    const struct MitigationSkill *skill,
    const MilliSecondsType current_combat_time_millisecond) {
  if (skill->cast_count == 0) {
    return 0;
  }

  MilliSecondsType last_skill_usage_time_millisecond =
      skill->cast_times_millisecond[skill->cast_count - 1];
  assert(current_combat_time_millisecond >= last_skill_usage_time_millisecond);

  MilliSecondsType time_since_last_use_millisecond = WRAPPING_SUBTRACT(
      current_combat_time_millisecond, last_skill_usage_time_millisecond);
  return WRAPPING_SUBTRACT(skill->cooldown_milliseconds,
                           time_since_last_use_millisecond);
}

struct MitigationSkill create_all_damage_mitigation_skill(
    const char *const skill_name, enum DamageTarget damage_target,
    const MitigationPercentType mitigation_percent,
    const MilliSecondsType duration_milliseconds,
    const MilliSecondsType cooldown_milliseconds) {
  const struct MitigationData
      physical_mitigation_data = { .type = PhysicalDamageReduction,
                                   .mitigation_amount = {
                                       .physical_damage_reduction = {
                                           .reduction_percent =
                                               mitigation_percent } } };

  const struct MitigationData
      magic_mitigation_data = { .type = MagicDamageReduction,
                                .mitigation_amount = {
                                    .magic_damage_reduction = {
                                        .reduction_percent =
                                            mitigation_percent } } };

  struct MitigationData *mitigation_datas = malloc(sizeof(struct MitigationData) * 2);
  mitigation_datas[0] = physical_mitigation_data;
  mitigation_datas[1] = magic_mitigation_data;

  struct MitigationSkill mitigation_skill = {
    .name = skill_name,
    .target = damage_target,
    .mitigation_data = mitigation_datas,
    .duration_milliseconds = duration_milliseconds,
    .cooldown_milliseconds = cooldown_milliseconds,
    .cast_count = 0
  };

  return mitigation_skill;
}
