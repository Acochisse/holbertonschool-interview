#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
int eval(int grid1[3][3]);
void topple(int grid1[3][3]);
static void print_grid(int grid[3][3]);
void grid_add(int grid1[3][3], int grid2[3][3]);



#endif