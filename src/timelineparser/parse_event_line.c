#include <stdio.h>
#include <stdlib.h>

#include <util/string_util.h>
#include <util/types.h>
#include <util/const.h>
#include <error/error_handler.h>
#include <ffxivcomponents/damage/damage_event.h>
#include <ffxivcomponents/damage/damage_type.h>
#include <ffxivcomponents/damage/damage_category.h>
#include <ffxivcomponents/damage/damage_target.h>

#include "parse_event_line.h"
#include "damage_event_parse_position.h"

#define MIN_DAMAGE_EVENT_INPUT_TOKEN_COUNT 6

#define FFXIV_PARTY_SIZE 8
#define FFXIV_JOB_ABBREV_SIZE 4

#define HP_INFO_TOKEN_COUNT 2

MilliSecondsType parse_mm_ss_time(const char *const restrict time_str)
{
	int minutes = 0;
	int seconds = 0;

	if (sscanf(time_str, "%d:%d", &minutes, &seconds) != 2)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Invalid time format: %s, must be mm:ss format", time_str);
		ffxiv_mitigation_solver_error_info.error = InvalidFormat;
		ffxiv_mitigation_solver_error_handler();
	}

	if (minutes < 0 || seconds < 0 || seconds >= 60)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Invalid time value - string: %s, minutes: %d, seconds: %d", time_str, minutes, seconds);
		ffxiv_mitigation_solver_error_info.error = InvalidFormat;
		ffxiv_mitigation_solver_error_handler();
	}

	return (minutes * MINUTE_IN_SECONDS + seconds) * SECOND_IN_MILLISECONDS;
}

void parse_party_members_line(char *const restrict line, const int party_size, struct FfxivJob party[party_size])
{
	char tokens[FFXIV_PARTY_SIZE][FFXIV_JOB_ABBREV_SIZE];
	const int token_cnt = split_string(line, " ", FFXIV_PARTY_SIZE, FFXIV_JOB_ABBREV_SIZE, tokens);

	if (token_cnt != FFXIV_PARTY_SIZE)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Invalid number of tokens: Party member line must have exactly 8 tokens, but got %d", token_cnt);
		ffxiv_mitigation_solver_error_info.error = InvalidNumberofTokens;
		ffxiv_mitigation_solver_error_handler();
	}

	for (int i = 0; i < party_size; i++)
	{
		struct FfxivJob party_member = create_job(i, tokens[i]);
		party[i] = party_member;
	}
}

struct HpInfo parse_hp_info_line(char *const restrict line)
{
	char tokens[HP_INFO_TOKEN_COUNT][MAX_INPUT_TEXT_SIZE];

	const int token_cnt = split_string(line, " ", HP_INFO_TOKEN_COUNT, MAX_INPUT_TEXT_SIZE, tokens);

	if (token_cnt != HP_INFO_TOKEN_COUNT)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Invalid number of tokens: HP info line must have exactly 2 tokens, but got %d", token_cnt);
		ffxiv_mitigation_solver_error_info.error = InvalidNumberofTokens;
		ffxiv_mitigation_solver_error_handler();
	}

	const DamageAmountType tank_max_hp = atoi(tokens[0]);
	const DamageAmountType non_tank_max_hp = atoi(tokens[1]);

	struct HpInfo hp_info = {
		.tank_max_hp = tank_max_hp,
		.non_tank_max_hp = non_tank_max_hp,
	};

	return hp_info;
}

struct DamageEvent parse_damage_event_line(char *const restrict line)
{
	char tokens[MAX_INPUT_TEXT_TOKEN_SIZE][MAX_INPUT_TEXT_SIZE];

	const int token_cnt = split_string(line, " ", MAX_INPUT_TEXT_TOKEN_SIZE, MAX_INPUT_TEXT_SIZE, tokens);

	if (token_cnt < MIN_DAMAGE_EVENT_INPUT_TOKEN_COUNT)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Invalid number of tokens: Damage event line must have at least 6 tokens, but got %d", token_cnt);
		ffxiv_mitigation_solver_error_info.error = InvalidNumberofTokens;
		ffxiv_mitigation_solver_error_handler();
	}

	char *const damage_event_name = tokens[DamageEventParsePositionCategory];
	const MilliSecondsType time_milliseconds = parse_mm_ss_time(tokens[DamageEventParsePositionTime]);
	const enum DamageType damage_type = convert_to_damage_type(tokens[DamageEventParsePositionType]);
	const enum DamageTarget damage_target = convert_to_damage_target(tokens[DamageEventParsePositionTarget]);
	const enum DamageCategory damage_category = convert_to_damage_category(tokens[DamageEventParsePositionCategory]);
	const DamageAmountType damage_amount = atoi(tokens[DamageEventParsePositionRawDamage]);

	if (damage_category == DamageCategoryInstant)
	{
		struct DamageEvent damage_event = {
			.event_name = damage_event_name,
			.time_milliseconds = time_milliseconds,
			.damage_info = &(struct DamageInfo){
				.damage_profile = {
					.damage_type = damage_type,
					.damage_data = {
						.instant_damage = {
							.damage_amount = damage_amount,
						},
					},
				},
				.damage_target = damage_target,
			},
		};

		return damage_event;
	}
	else
	{
		const MilliSecondsType dot_duration_seconds = atoi(tokens[DamageEventParsePositionDotDurationSeconds]);
		struct DamageEvent damage_event = {
			.event_name = damage_event_name,
			.time_milliseconds = time_milliseconds,
			.damage_info = &(struct DamageInfo){
				.damage_profile = {
					.damage_type = damage_type,
					.damage_data = {
						.dot_damage = {
							.damage_amount = damage_amount,
							.duration_milliseconds = dot_duration_seconds * SECOND_IN_MILLISECONDS,
						},
					},
				},
				.damage_target = damage_target,
			},
		};

		return damage_event;
	}
}