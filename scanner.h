/// file: scanner.h
/// description: scanner.h is the interface for functions that use a transition
/// matrix to classify tokens from standard input.
/// @author Jesse Burdick-Pless jb4411

#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <ctype.h>
#include "classes.h"
#include "matrix.h"

/// Used by the scanner to classify a character into a numbered class and
/// return its class number for use as an index into the transition matrix.
///
/// @param chr  the character to be classified
/// @return     the number of the character class of the character passed in

int classify( int chr );

/// Called repeatedly by the main function to recognize tokens from standard
/// input. Tokens are recognized by using a transition matrix.
///

/// @param start   the start state for the transition matrix
/// @param accept  the accepting state for the transition matrix
/// @param tm      an array of t_matrix structures that represents the
///                transition matrix
/// @return        a number when a token is recognized or rejected, or when EOF
///                is reached. 0 is returned if a token is recognized or
///                rejected. 1 is returned when EOF is reached.

int scanner( int start, int accept, t_matrix tm[][NUM_CLASSES] );

#endif
