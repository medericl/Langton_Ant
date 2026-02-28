#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#include "next_generation.h"
#include "grid.h"


static void _random(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec * 1000000 + tv.tv_usec);
}

void next_generation(char ** grid, struct langton * lan)
{
    char cur = grid[lan->y][lan->x];

    if (!cur)
    {
        // black
        grid[lan->y][lan->x] = lan->color;
        lan->dir += lan->e; // turn clockwise
    }
    else
    {
        // color
        //_random();
        //int aa = (rand() % 4);
        //if (aa == 0)
        //    grid[lan->y][lan->x] = lan->color;
        //else
        grid[lan->y][lan->x] = 0;
        lan->dir -= lan->f; // turn counter-clockwise
    }

    if (lan->dir == - 1)
        lan->dir = 3;
    else if (lan->dir == 4)
        lan->dir = 0;

    int aa = (rand() % 4);
    if (aa == 0) {
        if (lan->dir == 0)
            lan->y -= lan->a;
        else if (lan->dir == 2)
            lan->y += lan->b;
        else if (lan->dir == 3)
            lan->x -= lan->c;
        else if (lan->dir == 1)
            lan->x += lan->d;
    }

    else {
        if (lan->dir == 0)
            lan->y -= 1;
        else if (lan->dir == 2)
            lan->y += 1;
        else if (lan->dir == 3)
            lan->x -= 1;
        else if (lan->dir == 1)
            lan->x += 1;
    }

    if (lan->x > WIDTH - 1 || lan->y > HEIGHT - 1)
        lan->alive = 0;

}
