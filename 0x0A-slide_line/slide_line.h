#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1


#include <stdio.h>
#include <stdlib.h>

int slide_line(int *line, size_t size, int direction);
void slide_left(int *line, size_t size);
void slide(int *line, size_t size);
void reverse_line(int *line, size_t size);

#endif /* SLIDE_LINE_H */
