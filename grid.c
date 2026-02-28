#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "grid.h"
#include "next_generation.h"



void grid_free(char **grid)
{
    for (size_t i = 0; i < HEIGHT; i++)
        free(grid[i]);
    free(grid);
}

static void sleep_ms(long ms)
{
#if defined(_WIN32)
    Sleep(ms);                     // Windows
#else
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000L;
    nanosleep(&ts, NULL);          // POSIX
#endif
}

void display(char** grid, char life, char death, struct langton *lan)
{
    printf("\033[H\033[J");
    for (size_t j = 1; j < HEIGHT - 1; j++) {
        for (size_t i = 1; i < WIDTH - 1; i++)
            if (lan->y == j && lan->x == i)
                printf("\033[33m%c\033[0m", '@');
            else if (grid[j][i] == 1)
                printf("\033[31m%c\033[0m", life);
            else if (grid[j][i] == 2)
                printf("\033[32m%c\033[0m", life);
            else if (grid[j][i] == 3)
                printf("\033[33m%c\033[0m", life);
            else if (grid[j][i] == 4)
                printf("\033[34m%c\033[0m", life);
            else if (grid[j][i] == 5)
                printf("\033[35m%c\033[0m", life);
            else if (grid[j][i] == 6)
                printf("\033[35m%c\033[0m", life);
            else
                putchar(death);

        putchar('\n');
    }
    printf("\n");
    printf("%d\n",lan->a);
    printf("%d\n",lan->b);
    printf("%d\n",lan->c);
    printf("%d\n",lan->d);
    printf("%d\n",lan->e);
    printf("%d\n",lan->f);
    printf("%d\n",lan->color);
    fflush(stdout);
    sleep_ms(DELAY);
}


char **grid_init(void)
{
    char **grid = calloc(HEIGHT, sizeof(char *));
    if (!grid) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < HEIGHT; i++) {
        grid[i] = calloc(WIDTH, sizeof(char));
        if (!grid[i]) {
            perror("malloc");
            grid_free(grid);
            exit(EXIT_FAILURE);
        }
    }

    return grid;
}
