#include "job.h"

#include <stdlib.h>
#include <string.h>

#include "damage/damage_target.h"
#include "mitigation/mitigation_data.h"
#include "mitigation/mitigation_skill.h"
#include "mitigation/mitigation_type.h"

#define PLD_MITIGATION_SKILL_CNT 3
#define WAR_MITIGATION_SKILL_CNT 2
#define SCH_MITIGATION_SKILL_CNT 6
#define AST_MITIGATION_SKILL_CNT 2

struct MitigationSkill *create_tank_common_mitigation_skills() {
  const struct MitigationSkill rampart = create_all_damage_mitigation_skill(
      "Rampart", DamageTargetTanksolo, 20, 20000, 90000);
  const struct MitigationSkill reprisal = create_all_damage_mitigation_skill(
      "Reprisal", DamageTargetRaidwide, 10, 15000, 60000);

  struct MitigationSkill *tank_common_mitigation_skills =
      malloc(sizeof(struct MitigationSkill) * 2);
  tank_common_mitigation_skills[0] = rampart;
  tank_common_mitigation_skills[1] = reprisal;

  return tank_common_mitigation_skills;
}

struct MitigationSkill *create_pld_mitigation_skills() {
  const struct MitigationSkill *tank_common_mitigation_skills =
      create_tank_common_mitigation_skills();
  /*
  const struct MitigationSkill holy_sheltron =
  create_all_damage_mitigation_skill("Holy Sheltron", DamageTargetTanksolo, 25,
  8000, 15000); const struct MitigationSkill hallowed_ground =
  create_all_damage_mitigation_skill("Hallowed Ground", DamageTargetTanksolo,
  100, 10000, 420000); const struct MitigationSkill guardian = { .name =
  "Guardian", .target = DamageTargetTanksolo, .mitigation_data = {
                  {
                          .type = Shield,
                          .mitigation_amount = {.shield = 40000},
                  },
                  {
                          .type = PhysicalDamageReduction,
                          .mitigation_amount = {.reduction_percent = 40},
                  },
                  {
                          .type = MagicDamageReduction,
                          .mitigation_amount = {.reduction_percent = 40},
                  }},
          .duration_milliseconds = 15000,
          .cooldown_milliseconds = 120000,
          .cast_count = 0};
  const struct MitigationSkill sentinel =
  create_all_damage_mitigation_skill("Sentinel", DamageTargetTanksolo, 30,
  15000, 120000);
  */

  const struct MitigationSkill wings = create_all_damage_mitigation_skill(
      "Wings", DamageTargetRaidwide, 15, 5000, 120000);

  struct MitigationData *divine_veil_mitigation_data =
      malloc(sizeof(struct MitigationData) * 1);

  divine_veil_mitigation_data[0] = (struct MitigationData){
    Shield,
    .mitigation_amount = { .shield = { .shield_amount = 16000 } },
  };

  const struct MitigationSkill divine_veil = { 
	.name = "Divine Veil",
    .target = DamageTargetRaidwide,
    .mitigation_data =
        divine_veil_mitigation_data,
    .duration_milliseconds = 30000,
    .cooldown_milliseconds = 90000,
    .cast_count = 0 
  };

  struct MitigationSkill *pld_mitigation_skills =
      malloc(sizeof(struct MitigationSkill) * PLD_MITIGATION_SKILL_CNT);
  pld_mitigation_skills[0] = tank_common_mitigation_skills[1];
  pld_mitigation_skills[1] = wings;
  pld_mitigation_skills[2] = divine_veil;

  return pld_mitigation_skills;
}

/*
struct MitigationSkill *create_war_mitigation_skills()
{
        const struct MitigationSkill
tank_common_mitigation_skills[TANK_COMMON_SKILLS_CNT] =
create_tank_common_mitigation_skills(); const struct MitigationSkill
shake_it_off = { .name = "Shake It Off", .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                Shield,
                                .mitigation_amount = {.shield = 24000},
                        }},
                .duration_milliseconds = 15000,
                .cooldown_milliseconds = 90000,
                .cast_count = 0};

        struct MitigationSkill *war_mitigation_skills =
malloc(WAR_MITIGATION_SKILL_CNT * sizeof(struct MitigationSkill));
        war_mitigation_skills[0] = tank_common_mitigation_skills[1];
        war_mitigation_skills[1] = shake_it_off;

        return war_mitigation_skills;
}

struct MitigationSkill *create_sch_mitigation_skills()
{
        const struct MitigationSkill fey_illumination = {
                .name = "Fey Illumination",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 5},
                        }},
                .duration_milliseconds = 20000,
                .cooldown_milliseconds = 120000,
                .cast_count = 0};

        const struct MitigationSkill adlo_spread = {
                .name = "Adlo Spread",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                Shield,
                                .mitigation_amount = {.shield = 40000},
                        }},
                .duration_milliseconds = 30000,
                .cooldown_milliseconds = 90000,
                .cast_count = 0};

        const struct MitigationSkill shield = {
                .name = "Shield",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                Shield,
                                .mitigation_amount = {.shield = 16000},
                        }},
                .duration_milliseconds = 30000,
                .cooldown_milliseconds = 2500,
        };

        const struct MitigationSkill soil =
create_all_damage_mitigation_skill("Soil", DamageTargetRaidwide, 10, 18000,
30000); const struct MitigationSkill seraph = { .name = "Seraph", .target =
DamageTargetRaidwide, .mitigation_data = {
                        {
                                .type = Shield,
                                .mitigation_amount = {.shield = 16000},
                        }},
                .duration_milliseconds = 30000,
                .cooldown_milliseconds = 120000,
                .cast_count = 0};

        const struct MitigationSkill expedient =
create_all_damage_mitigation_skill("Expedient", DamageTargetRaidwide, 10, 20000,
120000);

        const struct MitigationSkill sch_mitigation_skills[6] =
{fey_illumination, adlo_spread, shield, soil, seraph, expedient};

        return sch_mitigation_skills;
}

struct MitigationSkill *create_ast_mitigation_skills()
{
        const struct MitigationSkill neural_sect = {
                .name = "Neural Sect",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                .type = Shield,
                                .mitigation_amount = {.shield = 20000},
                        },
                        {
                                .type = MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        },
                        {
                                .type = PhysicalDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        }},
                .duration_milliseconds = 30000,
                .cooldown_milliseconds = 120000,
                .cast_count = 0};

        const struct MitigationSkill wheel =
create_all_damage_mitigation_skill("Wheel", DamageTargetRaidwide, 10, 15000,
60000);

        struct MitigationSkill ast_mitigation_skills[AST_MITIGATION_SKILL_CNT] =
{neural_sect, wheel};

        return ast_mitigation_skills;
}

struct MitigationSkill *create_melee_mitigation_skills()
{
        const struct MitigationSkill feint = {
                .name = "Feint",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                .type = MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 5},
                        },
                        {
                                .type = PhysicalDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        }},
                .duration_milliseconds = 15000,
                .cooldown_milliseconds = 90000,
                .cast_count = 0};

        struct MitigationSkill melee_mitigation_skills[1] = {feint};

        return melee_mitigation_skills;
}

struct MitigationSkill *create_ranged_mitigation_skills()
{
        const struct MitigationSkill ranged_mit = {
                .name = "Ranged Mitigation",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                .type = MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        },
                        {
                                .type = PhysicalDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        }},
                .duration_milliseconds = 15000,
                .cooldown_milliseconds = 90000,
                .cast_count = 0};

        struct MitigationSkill ranged_mitigation_skills[1] = {ranged_mit};

        return ranged_mitigation_skills;
}

struct MitigationSkill *create_redmage_mitigation_skills()
{
        const struct MitigationSkill addle = {
                .name = "Addle",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                .type = MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        },
                        {
                                .type = PhysicalDamageReduction,
                                .mitigation_amount = {.reduction_percent = 5},
                        }},
                .duration_milliseconds = 15000,
                .cooldown_milliseconds = 90000,
                .cast_count = 0};

        const struct MitigationSkill magick_barrier = {
                .name = "Magick Barrier",
                .target = DamageTargetRaidwide,
                .mitigation_data = {
                        {
                                .type = MagicDamageReduction,
                                .mitigation_amount = {.reduction_percent = 10},
                        }},
                .duration_milliseconds = 10,
                .cooldown_milliseconds = 120000,
                .cast_count = 0};

        struct MitigationSkill caster_mitigation_skills[2] = {addle,
magick_barrier};

        return caster_mitigation_skills;
}
*/
struct FfxivJob create_job(const PartyMemberIdType id, const char *job_abbrev) {
  struct FfxivJob pld_job = { .id = id,
                              .name = PLD_JOB_ABBREV,
                              .mitigation_skill_count =
                                  PLD_MITIGATION_SKILL_CNT,
                              .mitigation_skills =
                                  create_pld_mitigation_skills() };

  return pld_job;
  /*
  else if (strcmp(job_abbrev, WAR_JOB_ABBREV) == 0)
  {
          struct FfxivJob war_job = {
                  .id = id,
                  .name = WAR_JOB_ABBREV,
                  .mitigation_skill_count = 0,
                  .mitigation_skills = create_war_mitigation_skills()};
          return war_job;
  }
  else if (strcmp(job_abbrev, AST_JOB_ABBREV) == 0)
  {
          struct FfxivJob ast_job = {
                  .id = id,
                  .name = AST_JOB_ABBREV,
                  .mitigation_skill_count = AST_MITIGATION_SKILL_CNT,
                  .mitigation_skills = create_ast_mitigation_skills()};
          return ast_job;
  }
  else if (strcmp(job_abbrev, NIN_JOB_ABBREV) == 0)
  {
          struct FfxivJob nin_job = {
                  .id = id,
                  .name = NIN_JOB_ABBREV,
                  .mitigation_skill_count = 0,
                  .mitigation_skills = create_melee_mitigation_skills()};
          return nin_job;
  }
  else if (strcmp(job_abbrev, DRG_JOB_ABBREV) == 0)
  {
          struct FfxivJob drg_job = {
                  .id = id,
                  .name = DRG_JOB_ABBREV,
                  .mitigation_skill_count = 0,
                  .mitigation_skills = create_melee_mitigation_skills()};
          return drg_job;
  }
  else if (strcmp(job_abbrev, BRD_JOB_ABBREV) == 0)
  {
          struct FfxivJob dnc_job = {
                  .id = id,
                  .name = BRD_JOB_ABBREV,
                  .mitigation_skill_count = 0,
                  .mitigation_skills = create_ranged_mitigation_skills()};
          return dnc_job;
  }
  else
  {
          struct FfxivJob caster_job = {
                  .id = id,
                  .name = job_abbrev,
                  .mitigation_skill_count = 0,
                  .mitigation_skills = create_redmage_mitigation_skills()};
          return caster_job;
  }
  */
}
