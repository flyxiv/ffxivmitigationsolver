#include <stdio.h>
#include <ffxivcomponents/timelineboard/solver_board.h>
#include <timelineparser/input_timeline_parser.h>

int main(void)
{
	char *input_text_file_path = "input.txt";

	struct SolverBoard board = parse_input_timeline(input_text_file_path);
	printf("%d\n", board.damage_event_count);

	return 0;
}