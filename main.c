#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "grid.h"

int main(int argc, char **argv)
{

    char living_cells = '*';
    char dead_cells = ' ';
    int arg = 1;
    int pat = 0;

    if (argc >= 2 && argv[1][0] == '-' && argv[1][1] == 'p')
    {
        pat = 1;
        arg += 1;
    }

    if (argc - pat >= 2)
    {
        living_cells = argv[arg][0];
        if (argc - pat > 2)
            dead_cells = argv[arg + 1][0];
    }

    char **grid = grid_init();
    char **grid_next = grid_init();
    
    grid[HEIGHT / 2][WIDTH / 2] = 1;

    while (1)
    {
        display(grid, living_cells, dead_cells);

        //char** new_grid = next_generation(grid, grid_next);

        //char** grid_tmp = grid;
        //grid = new_grid;
        //grid_next = grid_tmp;
    }

    grid_free(grid);
    grid_free(grid_next);

    return 0;
}
