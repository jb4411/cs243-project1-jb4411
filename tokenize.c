/// file: tokenize.c 
/// description: a program that builds a transition matrix from a file passed
/// to the program as a command line argument. This transitiuon matrix is then
/// used to scan and recognize tokens from standard input.
/// @author Jesse Burdick-Pless jb4411

#include <stdio.h>
#include "classes.h"
#include "matrix.h"
#include "scanner.h"

#define MAX_STATES 75

/// The main function builds and prints the transition matrix built from a
/// file passed in as a command line argument.This transition matrix is then
/// used to recognize tokens from standard input. As tokens are being recognized
/// state transitions are printed and if a valid token is recognized the token 
/// is also printed. The scanner function is called until it returns 1, 
/// indicating that EOF has been reached at which point execution terminates.
///
/// @param argc integer value for the number of command line input
///        values
/// @param argv array of C string values, the command line arguments
/// @return 0 to tell the OS that the process ran successfully, OR
///         return 1 to tell the OS there were not enough command line
///         arguments
 
int main(int argc, char *argv[]) {
	if( argc < 2 ) {
		printf("usage: ./tokenize tmfile\n");
		return 1;
	}
	
	t_matrix tm[MAX_STATES][NUM_CLASSES];	
	int matrix_info[2] = {0};
	build_tm_file(argv[1], matrix_info, tm);
	
	int finished = 0;
	while( !finished ) {
		finished = scanner( matrix_info[0], matrix_info[1], tm );
	}
	return 0;
}	
