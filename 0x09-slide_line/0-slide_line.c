#include "slide_line.h"

/**
    * slide_line - slides and merges an array of integers
    * @line: points to an array of integers
    * @size: number of elements in array
    * @direction: SLIDE_LEFT or SLIDE_RIGHT
    * Return: 1 upon success, or 0 upon failure
    */


int slide_line(int *line, size_t size, int direction)
{
    size_t index, tmp;

    if (direction == SLIDE_LEFT) {
        for (index = 0; index < size; index++) {
            if (line[index] == 0) {
                for (tmp = index + 1; tmp < size; tmp++) {
                    if (line[tmp] != 0) {
                        line[index] = line[tmp];
                        line[tmp] = 0;
                        break;
                    }
                }
            }
        }
        for (index = 0; index < size - 1; index++) {
            if (line[index] == line[index + 1]) {
                line[index] += line[index + 1];
                line[index + 1] = 0;
            }
        }
        for (index = 0; index < size; index++) {
            if (line[index] == 0) {
                for (tmp = index + 1; tmp < size; tmp++) {
                    if (line[tmp] != 0) {
                        line[index] = line[tmp];
                        line[tmp] = 0;
                        break;
                    }
                }
            }
        }
    } else if (direction == SLIDE_RIGHT) {
        for (index = size - 1; index > 0; index--) {
            if (line[index] == 0) {
                for (tmp = index - 1; tmp > 0; tmp--) {
                    if (line[tmp] != 0) {
                        line[index] = line[tmp];
                        line[tmp] = 0;
                        break;
                    }
                }
            }
        }
        for (index = size - 1; index > 0; index--) {
            if (line[index] == line[index - 1]) {
                line[index] += line[index - 1];
                line[index - 1] = 0;
            }
        }
        for (index = size - 1; index > 0; index--) {
            if (line[index] == 0) {
                for (tmp = index - 1; tmp > 0; tmp--) {
                    if (line[tmp] != 0) {
                        line[index] = line[tmp];
                        line[tmp] = 0;
                        break;
                    }
                }
            }
        }
    } else {
        return (0);
    }
    return (1);
}

    /**
    * slide_left: operator for handling shifting the array to the left
    * @line: points to an array of integers
    * @size: number of elements in array
    *
    * Return: void
    */
void slide_left(int *line, size_t size) 

{

    size_t i, j;
    int tmp;

    for (i = 0; i < size && j < size; i++) {
        while (line[j] != 0) {
            j++;
        }
        if (line[i] != 0 && i > j) {
            tmp = line[i];
            line[i] = line[j];
            line[j] = tmp;
        }
    }
}

/**
* slide_right: operator for handling shifting the array to the right
* @line: points to an array of integers
* @size: number of elements in array
*
* Return: void
*
*/
void slide_right(int *line, size_t size) {
    size_t i, j;
    int tmp;
    for (i = size - 1; i > 0 && j > 0; i--) {
        while (line[j] != 0 && j > 0) {
            j--;
        }

        if (line[i]!= 0 && i < j) {
            tmp = line[i];
            line[i] = line[j];
            line[j] = tmp;
        }
    }
}
