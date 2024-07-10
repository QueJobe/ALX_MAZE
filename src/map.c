#include "raycasting.h"
#include <stdio.h>

/**
 * parse_line - line paser function
 * @line: input
 * @row: row info
 * @map: map array
 * return:0 on success 1 on fail
 */

int parse_line(const char *line, int row, int map[MAP_W][MAP_H])
{
	int col = 0;

	for (col = 0; col < MAP_W && line[col] != '\0', col++)
	{
		if (line[col] == '1')
		{
			map[row][col] = 1;
		}
		else if (line[col] == '0')
		{
			map[row][col] = 0
		}
		else
			return (0);
	}
	return (1);
}

/**
 * load_map - function to load map
 * @filename: file containing the map
 * @map: map array
 * return: map height
 */

int load_map(const char *filename, int map[MAP_W][MAP_H])
{
	FILE *file = fopen(filename, "r");

	if (!file)
	{
		return (0);
	}

	char line[MAP_W + 2];
	int row = 0;

	while (fgets(line, sizeof(line), file) && row < MAP_H)
	{
		if (!parse_line(line, row, map))
		{
			fclose(file);
			return (0);
		}
		row++;
	}
	fclose(file);
	return (row == MAP_H);
}
