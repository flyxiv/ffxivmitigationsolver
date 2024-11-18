#include <stdio.h>
#include <error/error_handler.h>
#include <ffxivcomponents/timelineboard/solver_board.h>
#include <ffxivcomponents/damage/damage_event.h>

#include "input_timeline_parser.h"
#include "parse_event_line.h"

struct SolverBoard parse_input_timeline(const char *const restrict input_timeline_file_path)
{
	FILE *input_timeline_file = fopen(input_timeline_file_path, "r");
	if (input_timeline_file == NULL)
	{
		snprintf(ffxiv_mitigation_solver_error_info.message, ERROR_BUFFER_SIZE,
				 "Failed to open input timeline file: %s", input_timeline_file_path);
		ffxiv_mitigation_solver_error_info.error = FileOpenError;
		ffxiv_mitigation_solver_error_handler();
	}

	char line[MAX_INPUT_TEXT_SIZE];

	fgets(line, MAX_INPUT_TEXT_SIZE, input_timeline_file);

	struct FfxivJob party[FFXIV_PARTY_MEMBER_COUNT];
	parse_party_members_line(line, FFXIV_PARTY_MEMBER_COUNT, party);
	printf("party_members: %s %s\n", party[0].name, party[1].name);


	fgets(line, MAX_INPUT_TEXT_SIZE, input_timeline_file);
	struct HpInfo hp_info = parse_hp_info_line(line);
	printf("hp_info: %d %d\n", hp_info.tank_max_hp, hp_info.non_tank_max_hp);

	struct DamageEvent damage_events[MAX_DAMAGE_EVENT_COUNT];

	int damage_event_count = 0;
	while (fgets(line, MAX_INPUT_TEXT_SIZE, input_timeline_file) != NULL)
	{
		struct DamageEvent damage_event = parse_damage_event_line(line);
		damage_events[damage_event_count] = damage_event;
		damage_event_count++;
	}

	fclose(input_timeline_file);

	printf("damage_event_count: %d\n", damage_events[0].time_milliseconds);

	return (struct SolverBoard){
		.hp_info = hp_info,
		.damage_event_count = damage_event_count,
		.damage_events = damage_events,
		.party_members = party};
}