/// file: scanner.h
/// description:
/// @author Jesse Burdick-Pless jb4411

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include "classes.h"
#include "matrix.h"

int classify( char chr );

char* scanner( int states, int start, int accept );

#endif
