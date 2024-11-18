/**
 * Copyright (c) 2024 Jun Yeop Na(ns090200@gmail.com)
 * All rights reserved.
 */

#ifndef TIMELINEPARSER_PARSE_LINE_H
#define TIMELINEPARSER_PARSE_LINE_H

#include <ffxivcomponents/job.h>
#include <ffxivcomponents/timelineboard/solver_board.h>
#include <util/types.h>
#include <util/const.h>

#include <damage/damage_event.h>

/*
 * Utility function to parse input text lines
 */

/*
 * parse mm:ss type string to milliseconds
 * ex) parse_mm_ss_time("02:11") == 131000
 */
MilliSecondsType parse_mm_ss_time(const char *const restrict time_str);

/*
 * Parse party member event line and return corresponding 8 man party
 */
void parse_party_members_line(char *const restrict line, const int party_size, struct FfxivJob party[party_size]);

struct HpInfo parse_hp_info_line(char *const restrict line);

/*
 * Parse damage event line and return a DamageEvent struct
 * Length of token varies depending whether damage is instant or dot
 *
 * damage event line example:
 * ex1) "Phylas_Morphic 00:11 Magic Raidwide Instant 105022"
 * ex2) "Tank_Buster_Dot 00:15 Magic Tankshare Dottick 10222 30"
 */
struct DamageEvent parse_damage_event_line(char *const restrict line);

#endif