#ifndef GRID_H
#define GRID_H

//#define WIDTH 129
//#define HEIGHT 36

#include "next_generation.h"

#define WIDTH 300
#define HEIGHT 80

#define DELAY 5

void grid_free(char **grid);

void display(char** grid, char life, char death, struct langton *lan);

void grid_free(char **grid);

char **grid_init(void);

#endif

