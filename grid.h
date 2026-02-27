#ifndef GRID_H
#define GRID_H

#define WIDTH 129
#define HEIGHT 36

//#define WIDTH 300
//#define HEIGHT 80

#define DELAY 30

void grid_free(char **grid);

void display(char** grid, char life, char death);

void grid_free(char **grid);

char **grid_init(void);

void grid_pattern(char **grid);

void grid_random(char **grid);

#endif

