#ifndef NEXT_GENERATION_H
#define NEXT_GENERATION_H

struct langton
{
    size_t x;
    size_t y;
    int cur;
    int next;
    int dir;
    int alive;
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int color;
};

void next_generation(char ** grid, struct langton * lan);

#endif

