/// file: scanner.h
/// description:
/// @author Jesse Burdick-Pless jb4411

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <ctype.h>
#include "classes.h"
#include "matrix.h"

int classify( int chr );

int scanner( int start, int accept, t_matrix tm[][NUM_CLASSES] );

#endif
