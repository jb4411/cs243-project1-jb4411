/// file: matrix.h
/// description:
/// @author Jesse Burdick-Pless jb4411

#ifndef MATRIX_H
#define MATRIX_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "classes.h"

#define BUFLENGTH 127

typedef struct transition_matrix_ {
        int next;
        char action;
} t_matrix; 

void build_tm_file( char *filename, int matrix_info[3], t_matrix tm[][NUM_CLASSES] );

#endif
