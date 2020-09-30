/// file: matrix.h
/// description: matrix.h is the interface for the function that builds a 
/// transition matrix.
/// @author Jesse Burdick-Pless jb4411

#ifndef MATRIX_H
#define MATRIX_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "classes.h"

#define BUFLENGTH 127

/// This structure represents a transition matrix.
typedef struct transition_matrix_ {
        int next;
        char action;
} t_matrix; 

/// Build a transition matrix to be used by the scanner when classifying tokens. 
/// 
/// @param filename     a pointer to the name of the file that contains the 
///                     transition matrix
/// @param matrix_info  an array that the start and sccepting stete numbers 
///                     are put into
/// @param tm           an array of t_matrix structures that represents the
///                     transition matrix

void build_tm_file( char *filename, int matrix_info[2], t_matrix tm[][NUM_CLASSES] );

#endif
