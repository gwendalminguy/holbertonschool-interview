#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdbool.h>
#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
bool is_stable(int grid[3][3]);
void update_sandpiles(int grid1[3][3]);
void print_sandpiles(int grid[3][3]);

#endif /* SANDPILES_H */
