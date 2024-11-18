/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef FFXIVCOMPONENTS_JOB_H
#define FFXIVCOMPONENTS_JOB_H

#define PLD_JOB_ABBREV "PLD"
#define WAR_JOB_ABBREV "WAR"
#define DRK_JOB_ABBREV "DRK"
#define GNB_JOB_ABBREV "GNB"

#define WHM_JOB_ABBREV "WHM"
#define SCH_JOB_ABBREV "SCH"
#define AST_JOB_ABBREV "AST"
#define SGE_JOB_ABBREV "SGE"

#define MNK_JOB_ABBREV "MNK"
#define DRG_JOB_ABBREV "DRG"
#define NIN_JOB_ABBREV "NIN"
#define SAM_JOB_ABBREV "SAM"
#define RPR_JOB_ABBREV "RPR"
#define VPR_JOB_ABBREV "VPR"

#define BRD_JOB_ABBREV "BRD"
#define MCH_JOB_ABBREV "MCH"
#define DNC_JOB_ABBREV "DNC"

#define BLM_JOB_ABBREV "BLM"
#define SMN_JOB_ABBREV "SMN"
#define RDM_JOB_ABBREV "RDM"
#define PCT_JOB_ABBREV "PCT"

#define TANK_COMMON_SKILLS_CNT 2
#define MELEE_COMMON_SKILLS_CNT 1

#include <util/types.h>
#include "mitigation/mitigation_skill.h"

struct FfxivJob
{
	PartyMemberIdType id;
	char *name;

	MitigationSkillCountType mitigation_skill_count;
	struct MitigationSkill *mitigation_skills;
};

struct FfxivJob create_job(const PartyMemberIdType id, const char *name);

#endif