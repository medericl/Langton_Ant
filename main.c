#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#include "grid.h"
#include "next_generation.h"

static void _random(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    srand(tv.tv_sec * 1000000 + tv.tv_usec);
}

static struct langton * init_lan()
{
    _random();
    int a_ = (rand() % 3) - 1;
    _random();
    int b_ = (rand() % 3) - 1;
    _random();
    int c_ = (rand() % 3) - 1;
    _random();
    int d_ = (rand() % 3) - 1;
    _random();
    int e_ = (rand() % 3) - 1;
    _random();
    int f_ = (rand() % 3) - 1;
    _random();
    int color = (rand() % 6) + 1;

    struct langton * lan = malloc(sizeof * lan);
    lan->y = rand() % (HEIGHT / 2);
    lan->x = rand() % (WIDTH / 2) ;

    int dir = (rand() % 4);
    lan->dir = dir;

    lan->alive = 1;

    lan->a = a_;
    lan->b = b_;
    lan->c = c_;
    lan->d = d_;
    lan->e = e_;
    lan->f = f_;

    //lan->a = 1;
    //lan->b = 1;
    //lan->c = 1;
    //lan->d = 1;
    //lan->e = 1;
    //lan->f = 1;

    lan->color = color;

    return lan;
}

int main(int argc, char **argv)
{
    char living_cells = '+';
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

    grid[(HEIGHT / 2) + 1][WIDTH / 2] = 1;
    grid[(HEIGHT / 2)][WIDTH / 2] = 1;

    size_t k = 0;
    struct langton ** list_lan = malloc(sizeof(struct langton) * 10);
    for (size_t u = 0; u < 30; u += 1) {
        struct langton * lan = init_lan();
        list_lan[u] = lan;
    }

    struct langton * lan = init_lan();


    while (lan->alive)
    {
        display(grid, living_cells, dead_cells, lan);
        for (size_t u = 0; u < 30; u += 1) {
            if (list_lan[u]->alive)
                next_generation(grid, list_lan[u]);
        }
        k += 1;
    }

    grid_free(grid);

    return 0;
}
