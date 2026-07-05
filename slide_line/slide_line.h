#define SLIDE_LEFT -1
#define SLIDE_RIGHT 1

#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

#include <stdlib.h>
#include <stdio.h>

int slide_line(int *line, size_t size, int direction);
void reverse(int *line, int size);
int merge(int *line, int i, int j);
int move(int *line, int i, int j);

#endif /* SLIDE_LINE_H */
